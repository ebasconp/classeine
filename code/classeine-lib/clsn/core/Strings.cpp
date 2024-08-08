#include "Strings.h"

#include <charconv>

#include "clsn/core/Panic.h"

namespace clsn::core::Strings
{
    auto to_int(std::string_view value) -> std::optional<int>
    {
        int result;
        auto [ptr, ec] = std::from_chars(value.data(), value.data() + value.size(), result);
        if (ec == std::errc()) {
            return result;
        }

        return std::nullopt;
    }

    auto toString(int value) -> std::string
    {
        return std::to_string(value);
    }

    auto toString(double value) -> std::string
    {
        return std::to_string(value);
    }

    auto toString(bool value) -> std::string
    {
        return value ? "true" : "false";
    }

    auto toString(std::string_view value) -> std::string
    {
        return std::string{value};
    }

    auto toString(const std::string& value) -> const std::string&
    {
        return value;
    }

    auto toString(const char* value) -> std::string
    {
        return value;
    }

    void populateValuesAsStrings(std::vector<std::string>& )
    {
        // Do nothing
    }

    auto format_stream(std::ostream& os, std::string_view spec) -> std::ostream&
    {
        os << spec;
        return os;
    }

    void formatValues(std::ostream& os, std::string_view fmtspec, const std::vector<std::string>& values)
    {
        auto count = fmtspec.length();

        auto non_counted_index = 0;

        for (auto i = 0U; i < count; i++)
        {
            char thisk = fmtspec[i];

            if (thisk != '{')
            {
                os << thisk;
                continue;
            }

            if (thisk == '{' && i < count - 1 && fmtspec[i + 1] == '{')
            {
                os << '{';
                i++;
                continue;
            }

            auto closing_idx = fmtspec.find('}', i + 1);
            if (closing_idx == std::string_view::npos)
                clsn::core::Panic("} not found");

            auto sub = fmtspec.substr(i + 1, closing_idx - i - 1);

            auto arg_index = sub.empty() ? non_counted_index++ : to_int(sub);
            if (!arg_index.has_value())
                clsn::core::Panic("Invalid format index");

            if (*arg_index >= static_cast<int>(values.size()))
                clsn::core::Panic("Invalid index. Index higher than number of values");

            os << values[*arg_index];
            i = closing_idx;
        }
    }
}