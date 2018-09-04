// THIS FILE IS AUTOGENERATED
#pragma once

#include <locale/locale.hpp>

namespace lngs {
    enum class lng {
        SEVERITY_NOTE = 1001, // note (Name of the severity label for notes.)
        SEVERITY_WARNING = 1002, // warning (Name of the severity label for warnings.)
        SEVERITY_ERROR = 1003, // error (Name of the severity label for errors.)
        SEVERITY_FATAL = 1004, // fatal (Name of the severity label for fatals.)
        ERR_FILE_MISSING = 1005, // could not open `{0}' (Needed file was not found; filename is going to be shown as argument {0}.)
        ERR_FILE_NOT_FOUND = 1006, // could not open the file (Needed file was not found; filename is going to be shown as source of message.)
        ERR_NOT_STRINGS_FILE = 1007, // `{0}' is not strings file (Presented as additional message, if input file was not parsed properly.)
        ERR_NO_NEW_STRINGS = 1008, // no new strings (Shown by lngs freeze.)
        ERR_ATTR_EMPTY = 1009, // attribute `{0}' should not be empty (Used for attributes with no value. The argument represents the name of the attribute.)
        ERR_ATTR_MISSING = 1010, // attribute `{0}' is missing (Optional attribute is not present. The argument represents the name of the attribute.)
        ERR_REQ_ATTR_MISSING = 1011, // required attribute `{0}' is missing (A required attribute is not present. The argument represents the name of the attribute.)
        ERR_ID_MISSING_HINT = 1012, // before finalizing a value, use `id(-1)' (Hint for IDL authors, when an id attribute is missing.)
        ERR_EXPECTED = 1013, // expected {0}, got {1} (Information about bad syntax in the stirngs file. The arguments represent the expected and actual token, respectively.)
        ERR_EXPECTED_UNRECOGNIZED = 1014, // unrecognized text (Used as first argument for ERR_EXPECTED, as in "expected unrecognized text")
        ERR_EXPECTED_EOF = 1015, // EOF (Used as first argument for ERR_EXPECTED, as in "expected EOF")
        ERR_EXPECTED_STRING = 1016, // string (Used as first argument for ERR_EXPECTED, as in "expected string")
        ERR_EXPECTED_NUMBER = 1017, // number (Used as first argument for ERR_EXPECTED, as in "expected number")
        ERR_EXPECTED_ID = 1018, // identifier (Used as first argument for ERR_EXPECTED, as in "expected identifier")
        ERR_EXPECTED_GOT_EOF = 1019, // EOF (Used as second argument for ERR_EXPECTED, as in "..., got EOF")
        ERR_EXPECTED_GOT_STRING = 1020, // string (Used as second argument for ERR_EXPECTED, as in "..., got string")
        ERR_EXPECTED_GOT_NUMBER = 1021, // number (Used as second argument for ERR_EXPECTED, as in "..., got number")
        ERR_EXPECTED_GOT_ID = 1022, // identifier (Used as second argument for ERR_EXPECTED, as in "..., got identifier")
    }; // enum class lng

    struct Resource {
        static const char* data();
        static std::size_t size();
    };

    using Strings = locale::SingularStrings<lng, locale::storage::FileWithBuiltin<Resource>>;
}; // namespace lngs