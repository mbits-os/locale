#include "diag_helper.h"

namespace diags::testing {
	std::string_view lng_strings::get(severity sev) const noexcept {
		switch (sev) {
			case diags::severity::verbose:
				return {};
			case diags::severity::note:
				return get(lng::SEVERITY_NOTE);
			case diags::severity::warning:
				return get(lng::SEVERITY_WARNING);
			case diags::severity::error:
				return get(lng::SEVERITY_ERROR);
			case diags::severity::fatal:
				return get(lng::SEVERITY_FATAL);
		}
		return {};
	}

	std::string_view strings_mock::get(lng id) const noexcept {
		switch (id) {
			case lng::ARGS_USAGE:
				return "usage: ";
			case lng::ARGS_DEF_META:
				return "ARG";
			case lng::ARGS_POSITIONALS:
				return "positional arguments";
			case lng::ARGS_OPTIONALS:
				return "optional arguments";
			case lng::ARGS_HELP_DESCRIPTION:
				return "show this help message and exit";
			case lng::ARGS_UNRECOGNIZED:
				return "unrecognized argument: {0}";
			case lng::ARGS_NEEDS_PARAM:
				return "argument {0}: expected one argument";
			case lng::ARGS_NEEDS_NUMBER:
				return "argument {0}: expected a number";
			case lng::ARGS_NEEDED_NUMBER_EXCEEDED:
				return "argument {0}: number outside of expected bounds";
			case lng::ARGS_REQUIRED:
				return "argument {0} is required";
			case lng::ARGS_ERROR_MSG:
				return "{0}: error: {1}";
			case lng::ARGS_APP_DESCR_CMD_MAKE:
				return "Translates MO file to LNG file.";
			case lng::ARGS_APP_DESCR_CMD_POT:
				return "Creates POT file from message file.";
			case lng::ARGS_APP_DESCR_CMD_ENUMS:
				return "Creates header file from message file.";
			case lng::ARGS_APP_DESCR_CMD_PY:
				return "Creates Python module with string keys.";
			case lng::ARGS_APP_DESCR_CMD_RES:
				return "Creates C++ file with fallback resource for the "
				       "message file.";
			case lng::ARGS_APP_DESCR_CMD_FREEZE:
				return "Reads the language description file and assigns values "
				       "to new strings.";
			case lng::ARGS_APP_DESCR_USAGE:
				return "[-h] [--version] <command> [<arguments>]";
			case lng::ARGS_APP_FLOW_TITLE:
				return "The flow for string management and creation";
			case lng::ARGS_APP_FLOW_ROLE_STRMGR:
				return "Translation Manager";
			case lng::ARGS_APP_FLOW_ROLE_TRANSLATOR:
				return "Translator";
			case lng::ARGS_APP_FLOW_ROLE_DEV_COMPILE:
				return "Developer (compiling existing list)";
			case lng::ARGS_APP_FLOW_ROLE_DEV_ADD:
				return "Developer (adding new string)";
			case lng::ARGS_APP_FLOW_ROLE_DEV_RELEASE:
				return "Developer (releasing a build)";
			case lng::ARGS_APP_KNOWN_CMDS:
				return "known commands";
			case lng::ARGS_APP_NO_COMMAND:
				return "command missing";
			case lng::ARGS_APP_UNK_COMMAND:
				return "unknown command: {0}";
			case lng::ARGS_APP_META_FILE:
				return "<file>";
			case lng::ARGS_APP_META_HOLDER:
				return "<holder>";
			case lng::ARGS_APP_META_EMAIL:
				return "<email>";
			case lng::ARGS_APP_META_TITLE:
				return "<title>";
			case lng::ARGS_APP_META_PO_MO_FILE:
				return "<gettext file>";
			case lng::ARGS_APP_META_DIR:
				return "<dir>";
			case lng::ARGS_APP_VERSION:
				return "shows program version and exits";
			case lng::ARGS_APP_SHARE_REDIR:
				return "replaces {0} as new data directory";
			case lng::ARGS_APP_VERBOSE:
				return "shows more info";
			case lng::ARGS_APP_COPYRIGHT:
				return "sets the name of copyright holder";
			case lng::ARGS_APP_AUTHOR:
				return "sets the name and email address of first author";
			case lng::ARGS_APP_TITLE:
				return "sets a descriptive title for the POT project";
			case lng::ARGS_APP_RESOURCE:
				return "instructs the Strings type to use data generated by "
				       "the `lngs res'.";
			case lng::ARGS_APP_WARP_MISSING_SINGULAR:
				return "replaces missing strings with warped ones; resulting "
				       "strings are always singular";
			case lng::ARGS_APP_WARP_ALL_PLURAL:
				return "replaces all strings with warped ones; plural strings "
				       "will still be plural (as if English)";
			case lng::ARGS_APP_WITH_KEY_BLOCK:
				return "adds block of strings with key names";
			case lng::ARGS_APP_ALT_INCLUDE:
				return "sets file name to #include in the implementation of "
				       "the Resource class; defaults to \"<project>.hpp\".";
			case lng::ARGS_APP_OUT_POT:
				return "sets POT file name to write results to; use \"-\" for "
				       "standard output";
			case lng::ARGS_APP_OUT_CPP:
				return "sets C++ header file name to write results to; use "
				       "\"-\" for standard output";
			case lng::ARGS_APP_OUT_RES:
				return "sets C++ code file name with builtin strings to write "
				       "results to; use \"-\" for standard output";
			case lng::ARGS_APP_OUT_PY:
				return "sets Python file name to write results to; use \"-\" "
				       "for standard output";
			case lng::ARGS_APP_OUT_LNG:
				return "sets LNG binary file name to write results to; use "
				       "\"-\" for standard output";
			case lng::ARGS_APP_OUT_IDL:
				return "sets IDL message file name to write results to; it may "
				       "be the same as input; use \"-\" for standard output";
			case lng::ARGS_APP_IN_IDL:
				return "sets message file name to read from";
			case lng::ARGS_APP_IN_PO_MO:
				return "sets GetText message file name to read from";
			case lng::ARGS_APP_IN_LLCC:
				return "sets ATTR_LANGUAGE file name with ll_CC "
				       "(language_COUNTRY) names list";
			case lng::SEVERITY_NOTE:
				return "note";
			case lng::SEVERITY_WARNING:
				return "warning";
			case lng::SEVERITY_ERROR:
				return "error";
			case lng::SEVERITY_FATAL:
				return "fatal";
			case lng::ERR_FILE_MISSING:
				return "could not open `{0}'";
			case lng::ERR_FILE_NOT_FOUND:
				return "could not open the file";
			case lng::ERR_NOT_STRINGS_FILE:
				return "`{0}' is not strings file";
			case lng::ERR_NO_NEW_STRINGS:
				return "no new strings";
			case lng::ERR_ATTR_EMPTY:
				return "attribute `{0}' should not be empty";
			case lng::ERR_ATTR_MISSING:
				return "attribute `{0}' is missing";
			case lng::ERR_REQ_ATTR_MISSING:
				return "required attribute `{0}' is missing";
			case lng::ERR_ID_MISSING_HINT:
				return "before finalizing a value, use `id(-1)'";
			case lng::ERR_EXPECTED:
				return "expected {0}, got {1}";
			case lng::ERR_EXPECTED_GOT_UNRECOGNIZED:
				return "unrecognized text";
			case lng::ERR_EXPECTED_STRING:
				return "string";
			case lng::ERR_EXPECTED_NUMBER:
				return "number";
			case lng::ERR_EXPECTED_ID:
				return "identifier";
			case lng::ERR_EXPECTED_GOT_EOF:
				return "end of file";
			case lng::ERR_EXPECTED_GOT_EOL:
				return "end of line";
			case lng::ERR_EXPECTED_GOT_STRING:
				return "string";
			case lng::ERR_EXPECTED_GOT_NUMBER:
				return "number";
			case lng::ERR_EXPECTED_GOT_ID:
				return "identifier";
			case lng::ERR_MSGS_TRANSLATION_MISSING:
				return "message file does not contain translation for \"{0}\"";
			case lng::ERR_MSGS_ATTR_LANG_MISSING:
				return "message file does not contain Language attribute";
			case lng::ERR_UNANMED_LOCALE:
				return "locale {0} has no name";
			case lng::ERR_LOCALE_MISSING:
				return "no {0} locale on the list";
			case lng::ERR_GETTEXT_FORMAT:
				return "gettext file format error";
			case lng::ERR_GETTEXT_BLOCKS_OVERLAP:
				return "two or more blocks occupy the same space";
			case lng::ERR_GETTEXT_STRING_OUTSIDE:
				return "string not contained inside the block";
			case lng::ERR_GETTEXT_FILE_TRUNCATED:
				return "file truncated; data missing";
			case lng::ERR_GETTEXT_NOT_ASCIIZ:
				return "strings must end with a zero";
			case lng::ERR_EXPECTED_EOF:
				return "end of file";
			case lng::ERR_EXPECTED_EOL:
				return "end of line";
			case lng::ERR_GETTEXT_UNRECOGNIZED_FIELD:
				return "unrecognized field `{0}'";
			case lng::ERR_GETTEXT_UNRECOGNIZED_ESCAPE:
				return "unrecognized escape sequence `\\{0}'";
		}
		return "";
	}

	std::string_view alt_strings_mock::get(lng id) const noexcept {
		switch (id) {
			case lng::ARGS_USAGE:
				return "ARGS_USAGE";
			case lng::ARGS_DEF_META:
				return "ARGS_DEF_META";
			case lng::ARGS_POSITIONALS:
				return "ARGS_POSITIONALS";
			case lng::ARGS_OPTIONALS:
				return "ARGS_OPTIONALS";
			case lng::ARGS_HELP_DESCRIPTION:
				return "ARGS_HELP_DESCRIPTION";
			case lng::ARGS_UNRECOGNIZED:
				return "ARGS_UNRECOGNIZED({0})";
			case lng::ARGS_NEEDS_PARAM:
				return "ARGS_NEEDS_PARAM({0})";
			case lng::ARGS_NEEDS_NUMBER:
				return "ARGS_NEEDS_NUMBER({0})";
			case lng::ARGS_NEEDED_NUMBER_EXCEEDED:
				return "ARGS_NEEDED_NUMBER_EXCEEDED({0})";
			case lng::ARGS_REQUIRED:
				return "ARGS_REQUIRED({0})";
			case lng::ARGS_ERROR_MSG:
				return "ARGS_ERROR_MSG({0}|{1})";
			case lng::ARGS_APP_DESCR_CMD_MAKE:
				return "ARGS_APP_DESCR_CMD_MAKE";
			case lng::ARGS_APP_DESCR_CMD_POT:
				return "ARGS_APP_DESCR_CMD_POT";
			case lng::ARGS_APP_DESCR_CMD_ENUMS:
				return "ARGS_APP_DESCR_CMD_ENUMS";
			case lng::ARGS_APP_DESCR_CMD_PY:
				return "ARGS_APP_DESCR_CMD_PY";
			case lng::ARGS_APP_DESCR_CMD_RES:
				return "ARGS_APP_DESCR_CMD_RES";
			case lng::ARGS_APP_DESCR_CMD_FREEZE:
				return "ARGS_APP_DESCR_CMD_FREEZE";
			case lng::ARGS_APP_DESCR_USAGE:
				return "ARGS_APP_DESCR_USAGE";
			case lng::ARGS_APP_FLOW_TITLE:
				return "ARGS_APP_FLOW_TITLE";
			case lng::ARGS_APP_FLOW_ROLE_STRMGR:
				return "ARGS_APP_FLOW_ROLE_STRMGR";
			case lng::ARGS_APP_FLOW_ROLE_TRANSLATOR:
				return "ARGS_APP_FLOW_ROLE_TRANSLATOR";
			case lng::ARGS_APP_FLOW_ROLE_DEV_COMPILE:
				return "ARGS_APP_FLOW_ROLE_DEV_COMPILE";
			case lng::ARGS_APP_FLOW_ROLE_DEV_ADD:
				return "ARGS_APP_FLOW_ROLE_DEV_ADD";
			case lng::ARGS_APP_FLOW_ROLE_DEV_RELEASE:
				return "ARGS_APP_FLOW_ROLE_DEV_RELEASE";
			case lng::ARGS_APP_KNOWN_CMDS:
				return "ARGS_APP_KNOWN_CMDS";
			case lng::ARGS_APP_NO_COMMAND:
				return "ARGS_APP_NO_COMMAND";
			case lng::ARGS_APP_UNK_COMMAND:
				return "ARGS_APP_UNK_COMMAND";
			case lng::ARGS_APP_META_FILE:
				return "ARGS_APP_META_FILE";
			case lng::ARGS_APP_META_HOLDER:
				return "ARGS_APP_META_HOLDER";
			case lng::ARGS_APP_META_EMAIL:
				return "ARGS_APP_META_EMAIL";
			case lng::ARGS_APP_META_TITLE:
				return "ARGS_APP_META_TITLE";
			case lng::ARGS_APP_META_PO_MO_FILE:
				return "ARGS_APP_META_PO_MO_FILE";
			case lng::ARGS_APP_META_DIR:
				return "ARGS_APP_META_DIR";
			case lng::ARGS_APP_VERSION:
				return "ARGS_APP_VERSION";
			case lng::ARGS_APP_SHARE_REDIR:
				return "ARGS_APP_SHARE_REDIR({0})";
			case lng::ARGS_APP_VERBOSE:
				return "ARGS_APP_VERBOSE";
			case lng::ARGS_APP_COPYRIGHT:
				return "ARGS_APP_COPYRIGHT";
			case lng::ARGS_APP_AUTHOR:
				return "ARGS_APP_AUTHOR";
			case lng::ARGS_APP_TITLE:
				return "ARGS_APP_TITLE";
			case lng::ARGS_APP_RESOURCE:
				return "ARGS_APP_RESOURCE";
			case lng::ARGS_APP_WARP_MISSING_SINGULAR:
				return "ARGS_APP_WARP_MISSING_SINGULAR";
			case lng::ARGS_APP_WARP_ALL_PLURAL:
				return "ARGS_APP_WARP_ALL_PLURAL";
			case lng::ARGS_APP_WITH_KEY_BLOCK:
				return "ARGS_APP_WITH_KEY_BLOCK";
			case lng::ARGS_APP_ALT_INCLUDE:
				return "ARGS_APP_ALT_INCLUDE";
			case lng::ARGS_APP_OUT_POT:
				return "ARGS_APP_OUT_POT";
			case lng::ARGS_APP_OUT_CPP:
				return "ARGS_APP_OUT_CPP";
			case lng::ARGS_APP_OUT_RES:
				return "ARGS_APP_OUT_RES";
			case lng::ARGS_APP_OUT_PY:
				return "ARGS_APP_OUT_PY";
			case lng::ARGS_APP_OUT_LNG:
				return "ARGS_APP_OUT_LNG";
			case lng::ARGS_APP_OUT_IDL:
				return "ARGS_APP_OUT_IDL";
			case lng::ARGS_APP_IN_IDL:
				return "ARGS_APP_IN_IDL";
			case lng::ARGS_APP_IN_PO_MO:
				return "ARGS_APP_IN_PO_MO";
			case lng::ARGS_APP_IN_LLCC:
				return "ARGS_APP_IN_LLCC";
			case lng::SEVERITY_NOTE:
				return "nnn";
			case lng::SEVERITY_WARNING:
				return "www";
			case lng::SEVERITY_ERROR:
				return "eee";
			case lng::SEVERITY_FATAL:
				return "fff";
			case lng::ERR_FILE_MISSING:
				return "ERR_FILE_MISSING({0})";
			case lng::ERR_FILE_NOT_FOUND:
				return "ERR_FILE_NOT_FOUND";
			case lng::ERR_NOT_STRINGS_FILE:
				return "ERR_NOT_STRINGS_FILE({0})";
			case lng::ERR_NO_NEW_STRINGS:
				return "ERR_NO_NEW_STRINGS";
			case lng::ERR_ATTR_EMPTY:
				return "ERR_ATTR_EMPTY({0})";
			case lng::ERR_ATTR_MISSING:
				return "ERR_ATTR_MISSING({0})";
			case lng::ERR_REQ_ATTR_MISSING:
				return "ERR_REQ_ATTR_MISSING({0})";
			case lng::ERR_ID_MISSING_HINT:
				return "ERR_ID_MISSING_HINT";
			case lng::ERR_EXPECTED:
				return "ERR_EXPECTED({0}, {1})";
			case lng::ERR_EXPECTED_GOT_UNRECOGNIZED:
				return "ERR_EXPECTED_GOT_UNRECOGNIZED";
			case lng::ERR_EXPECTED_STRING:
				return "ERR_EXPECTED_STRING";
			case lng::ERR_EXPECTED_NUMBER:
				return "ERR_EXPECTED_NUMBER";
			case lng::ERR_EXPECTED_ID:
				return "ERR_EXPECTED_ID";
			case lng::ERR_EXPECTED_GOT_EOF:
				return "ERR_EXPECTED_GOT_EOF";
			case lng::ERR_EXPECTED_GOT_EOL:
				return "ERR_EXPECTED_GOT_EOL";
			case lng::ERR_EXPECTED_GOT_STRING:
				return "ERR_EXPECTED_GOT_STRING";
			case lng::ERR_EXPECTED_GOT_NUMBER:
				return "ERR_EXPECTED_GOT_NUMBER";
			case lng::ERR_EXPECTED_GOT_ID:
				return "ERR_EXPECTED_GOT_ID";
			case lng::ERR_MSGS_TRANSLATION_MISSING:
				return "ERR_MSGS_TRANSLATION_MISSING({0})";
			case lng::ERR_MSGS_ATTR_LANG_MISSING:
				return "ERR_MSGS_ATTR_LANG_MISSING";
			case lng::ERR_UNANMED_LOCALE:
				return "ERR_UNANMED_LOCALE({0})";
			case lng::ERR_LOCALE_MISSING:
				return "ERR_LOCALE_MISSING({0})";
			case lng::ERR_GETTEXT_FORMAT:
				return "ERR_GETTEXT_FORMAT";
			case lng::ERR_GETTEXT_BLOCKS_OVERLAP:
				return "ERR_GETTEXT_BLOCKS_OVERLAP";
			case lng::ERR_GETTEXT_STRING_OUTSIDE:
				return "ERR_GETTEXT_STRING_OUTSIDE";
			case lng::ERR_GETTEXT_FILE_TRUNCATED:
				return "ERR_GETTEXT_FILE_TRUNCATED";
			case lng::ERR_GETTEXT_NOT_ASCIIZ:
				return "ERR_GETTEXT_NOT_ASCIIZ";
			case lng::ERR_EXPECTED_EOF:
				return "ERR_EXPECTED_EOF";
			case lng::ERR_EXPECTED_EOL:
				return "ERR_EXPECTED_EOL";
			case lng::ERR_GETTEXT_UNRECOGNIZED_FIELD:
				return "ERR_GETTEXT_UNRECOGNIZED_FIELD({0})";
			case lng::ERR_GETTEXT_UNRECOGNIZED_ESCAPE:
				return "ERR_GETTEXT_UNRECOGNIZED_ESCAPE({0})";
		}
		return "";
	}

	const char* UnexpectedDiags::name(lng val) {
		switch (val) {
#define NAME(x)  \
	case lng::x: \
		return #x
			NAME(ARGS_USAGE);
			NAME(ARGS_DEF_META);
			NAME(ARGS_POSITIONALS);
			NAME(ARGS_OPTIONALS);
			NAME(ARGS_HELP_DESCRIPTION);
			NAME(ARGS_UNRECOGNIZED);
			NAME(ARGS_NEEDS_PARAM);
			NAME(ARGS_NEEDS_NUMBER);
			NAME(ARGS_NEEDED_NUMBER_EXCEEDED);
			NAME(ARGS_REQUIRED);
			NAME(ARGS_ERROR_MSG);
			NAME(ARGS_APP_DESCR_CMD_MAKE);
			NAME(ARGS_APP_DESCR_CMD_POT);
			NAME(ARGS_APP_DESCR_CMD_ENUMS);
			NAME(ARGS_APP_DESCR_CMD_PY);
			NAME(ARGS_APP_DESCR_CMD_RES);
			NAME(ARGS_APP_DESCR_CMD_FREEZE);
			NAME(ARGS_APP_DESCR_USAGE);
			NAME(ARGS_APP_FLOW_TITLE);
			NAME(ARGS_APP_FLOW_ROLE_STRMGR);
			NAME(ARGS_APP_FLOW_ROLE_TRANSLATOR);
			NAME(ARGS_APP_FLOW_ROLE_DEV_COMPILE);
			NAME(ARGS_APP_FLOW_ROLE_DEV_ADD);
			NAME(ARGS_APP_FLOW_ROLE_DEV_RELEASE);
			NAME(ARGS_APP_KNOWN_CMDS);
			NAME(ARGS_APP_NO_COMMAND);
			NAME(ARGS_APP_UNK_COMMAND);
			NAME(ARGS_APP_META_FILE);
			NAME(ARGS_APP_META_HOLDER);
			NAME(ARGS_APP_META_EMAIL);
			NAME(ARGS_APP_META_TITLE);
			NAME(ARGS_APP_META_PO_MO_FILE);
			NAME(ARGS_APP_META_DIR);
			NAME(ARGS_APP_VERSION);
			NAME(ARGS_APP_SHARE_REDIR);
			NAME(ARGS_APP_VERBOSE);
			NAME(ARGS_APP_COPYRIGHT);
			NAME(ARGS_APP_AUTHOR);
			NAME(ARGS_APP_TITLE);
			NAME(ARGS_APP_RESOURCE);
			NAME(ARGS_APP_WARP_MISSING_SINGULAR);
			NAME(ARGS_APP_WARP_ALL_PLURAL);
			NAME(ARGS_APP_WITH_KEY_BLOCK);
			NAME(ARGS_APP_ALT_INCLUDE);
			NAME(ARGS_APP_OUT_POT);
			NAME(ARGS_APP_OUT_CPP);
			NAME(ARGS_APP_OUT_RES);
			NAME(ARGS_APP_OUT_PY);
			NAME(ARGS_APP_OUT_LNG);
			NAME(ARGS_APP_OUT_IDL);
			NAME(ARGS_APP_IN_IDL);
			NAME(ARGS_APP_IN_PO_MO);
			NAME(ARGS_APP_IN_LLCC);
			NAME(SEVERITY_NOTE);
			NAME(SEVERITY_WARNING);
			NAME(SEVERITY_ERROR);
			NAME(SEVERITY_FATAL);
			NAME(ERR_FILE_MISSING);
			NAME(ERR_FILE_NOT_FOUND);
			NAME(ERR_NOT_STRINGS_FILE);
			NAME(ERR_NO_NEW_STRINGS);
			NAME(ERR_ATTR_EMPTY);
			NAME(ERR_ATTR_MISSING);
			NAME(ERR_REQ_ATTR_MISSING);
			NAME(ERR_ID_MISSING_HINT);
			NAME(ERR_EXPECTED);
			NAME(ERR_EXPECTED_GOT_UNRECOGNIZED);
			NAME(ERR_EXPECTED_EOF);
			NAME(ERR_EXPECTED_EOL);
			NAME(ERR_EXPECTED_STRING);
			NAME(ERR_EXPECTED_NUMBER);
			NAME(ERR_EXPECTED_ID);
			NAME(ERR_EXPECTED_GOT_EOF);
			NAME(ERR_EXPECTED_GOT_EOL);
			NAME(ERR_EXPECTED_GOT_STRING);
			NAME(ERR_EXPECTED_GOT_NUMBER);
			NAME(ERR_EXPECTED_GOT_ID);
			NAME(ERR_MSGS_TRANSLATION_MISSING);
			NAME(ERR_MSGS_ATTR_LANG_MISSING);
			NAME(ERR_UNANMED_LOCALE);
			NAME(ERR_LOCALE_MISSING);
			NAME(ERR_GETTEXT_FORMAT);
			NAME(ERR_GETTEXT_BLOCKS_OVERLAP);
			NAME(ERR_GETTEXT_STRING_OUTSIDE);
			NAME(ERR_GETTEXT_FILE_TRUNCATED);
			NAME(ERR_GETTEXT_NOT_ASCIIZ);
			NAME(ERR_GETTEXT_UNRECOGNIZED_FIELD);
			NAME(ERR_GETTEXT_UNRECOGNIZED_ESCAPE);
#undef NAME
		};
		return "???";
	}

	const char* UnexpectedDiags::name(diags::severity sev) {
		switch (sev) {
#define NAME(x)              \
	case diags::severity::x: \
		return "severity::" #x;
			NAME(verbose);
			NAME(note);
			NAME(warning);
			NAME(error);
			NAME(fatal);
#undef NAME
		};
		return "!!!";
	}

	void UnexpectedDiags::info(std::ostream& o,
	                           noenum::string::argument const& arg) {
		std::visit(
		    [&](auto const& arg) {
			    if constexpr (std::is_same_v<decltype(arg),
			                                 std::string const&>) {
				    o << "\"" << arg << "\"";
			    } else if constexpr (std::is_same_v<
			                             decltype(arg),
			                             noenum::string::formatable const&>) {
				    info(o, arg);
			    } else if constexpr (std::is_same_v<
			                             decltype(arg),
			                             noenum::string::singular const&>) {
				    o << "lng::" << name(static_cast<lng>(arg.id));
			    } else {
				    o << "[" << arg.id << "/" << arg.count << "]";
			    }
		    },
		    static_cast<noenum::string::argument::base_class const&>(arg));
	}

	void UnexpectedDiags::info(std::ostream& o,
	                           noenum::string::formatable const& arg) {
		std::visit(
		    [&](auto const& arg) {
			    if constexpr (std::is_same_v<decltype(arg),
			                                 std::string const&>) {
				    o << "\"" << arg << "\"";
			    } else if constexpr (std::is_same_v<
			                             decltype(arg),
			                             noenum::string::singular const&>) {
				    o << "lng::" << name(static_cast<lng>(arg.id));
			    } else {
				    o << "[" << arg.id << "/" << arg.count << "]";
			    }
		    },
		    arg.subject());

		if (arg.arguments().empty()) return;

		o << "(";
		auto first = true;
		for (auto const& sub : arg.arguments()) {
			if (first)
				first = false;
			else
				o << ",";
			info(o, sub);
		}
		o << ")";
	}
}  // namespace diags::testing

namespace lngs::app {
	void PrintTo(lng id, std::ostream* o) {
		*o << diags::testing::UnexpectedDiags::name(id);
	}
}  // namespace lngs::app

namespace diags {
	void PrintTo(severity sev, std::ostream* o) {
		*o << testing::UnexpectedDiags::name(sev);
	}

	namespace noenum::string {
		void PrintTo(argument const& arg, std::ostream* o) {
			testing::UnexpectedDiags::info(*o, arg);
		}

		void PrintTo(message const& arg, std::ostream* o) {
			testing::UnexpectedDiags::info(*o, arg);
			*o << " :: [" << arg.dbg() << ']';
		}
	}  // namespace noenum::string
}  // namespace diags
