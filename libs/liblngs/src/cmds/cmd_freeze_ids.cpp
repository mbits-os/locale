/*
 * Copyright (C) 2015 midnightBITS
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <locale/file.hpp>
#include <lngs/argparser.hpp>
#include <lngs/strings.hpp>
#include <lngs/streams.hpp>
#include <algorithm>

namespace freeze {
	void write(FILE* out, const locale::Strings& defs, std::vector<std::byte>& data);
	int call(args::parser& parser)
	{
		fs::path inname, outname;
		bool verbose = false;

		parser.set<std::true_type>(verbose, "v", "verbose").help("show more info").opt();
		parser.arg(inname, "i", "in").meta("FILE").help("LNGS message file to read");
		parser.arg(outname, "o", "out").meta("FILE").help("LNGS message file to write; it may be the same as input; if - is used, result is written to standard output");
		parser.parse();

		inname.make_preferred();

		if (verbose)
			printf("%s\n", inname.string().c_str());

		locale::Strings strings;
		std::vector<std::byte> contents;

		{
			auto inf = fs::fopen(inname, "rb");

			if (!inf) {
				fprintf(stderr, "could not open `%s'", inname.string().c_str());
				return -1;
			}
			contents = inf.read();
		}

		{
			locale::meminstream is{ contents.data(), contents.size() };
			if (!locale::read_strings(is, inname.string(), strings)) {
				if (verbose)
					fprintf(stderr, "`%s' is not strings file.\n", inname.string().c_str());
				return -1;
			}
		}

		if (!strings.has_new) {
			if (verbose)
				printf("No new strings found\n");
			return -1;
		}

		++strings.serial;

		for (auto& s : strings.strings) {
			s.value.clear();
			s.help.clear();
			s.plural.clear();
		}

		std::sort(begin(strings.strings), end(strings.strings),
			[](auto&& left, auto&& right) { return left.id_offset < right.id_offset; });

		if (outname == "-") {
			write(stdout, strings, contents);
			return 0;
		}

		auto outf = fs::fopen(outname, "wb");

		if (!outf) {
			fprintf(stderr, "could not open `%s'", outname.string().c_str());
			return -1;
		}

		write(outf.handle(), strings, contents);
		return 0;
	}

	constexpr std::byte operator""_b(char c) { return (std::byte) c; }
	std::pair<int, int> value_pos(const std::byte* start)
	{
		int first = 0;
		while (*start != '('_b) ++start, ++first;
		int second = first;
		while (*start != ')'_b) ++start, ++second;

		return{ first, second };
	}

	void write(FILE* out, const locale::Strings& defs, std::vector<std::byte>& data)
	{
		const std::byte* bytes = data.data();
		int offset = 0;
		auto [from, to] = value_pos(bytes + defs.serial_offset);
		fwrite(bytes, 1, defs.serial_offset + from + 1, out);
		fprintf(out, "%d", defs.serial);
		offset = defs.serial_offset + to;

		for (auto& str : defs.strings) {
			auto[from, to] = value_pos(bytes + str.id_offset);
			fwrite(bytes + offset, 1, str.id_offset + from + 1 - offset, out);
			fprintf(out, "%d", str.id);
			offset = str.id_offset + to;
		}

		fwrite(bytes + offset, 1, data.size() - offset, out);
	}
}