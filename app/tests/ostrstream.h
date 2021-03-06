#pragma once

#include <diags/streams.hpp>
#include <numeric>
#include <string>

namespace lngs::app::testing {
	struct outstrstream : diags::outstream {
		std::string contents;

		using outstream::write;
		std::size_t write(const void* data, std::size_t length) noexcept final {
			auto b = static_cast<const char*>(data);
			auto e = b + length;
			auto size = contents.size();
			contents.insert(end(contents), b, e);
			return contents.size() - size;
		}
	};
}  // namespace lngs::app::testing