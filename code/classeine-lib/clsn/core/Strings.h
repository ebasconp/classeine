#pragma once

#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace clsn::core::Strings
{
    auto to_int(std::string_view ) -> std::optional<int>;

    template <typename T>
    auto toString(const T& value) -> std::string
    {
        return value.toString();
    }

    auto toString(int value) -> std::string;
    auto toString(double value) -> std::string;
    auto toString(bool value) -> std::string;
    auto toString(std::string_view value) -> std::string;
    auto toString(const std::string& value) -> const std::string&;
    auto toString(const char* value) -> std::string;

    void populateValuesAsStrings(std::vector<std::string>& );

    template <typename Head>
    void populateValuesAsStrings(std::vector<std::string>& values, const Head& head)
    {
        values.push_back(toString(head));
    }

    template <typename Head, typename... Tail>
    void populateValuesAsStrings(std::vector<std::string>& values, const Head& head, const Tail&... tail)
    {
        values.push_back(toString(head));
        populateValuesAsStrings(values, tail...);
    }

    template <typename... Args>
    auto getValuesAsStrings(const Args&... args) -> std::vector<std::string>
    {
        std::vector<std::string> values;
        populateValuesAsStrings(values, args...);
        return values;
    }

    void formatValues(std::ostream& os, std::string_view fmtspec, const std::vector<std::string>& values);

    template <typename... Args>
    auto format_stream(std::ostream& os, std::string_view fmtspec, const Args&... args) -> std::ostream&
    {
        auto values = getValuesAsStrings(args...);
        formatValues(os, fmtspec, values);
        return os;
    }

    // This overload is a helper to make printing interface consistent.
    // It does not perform any validation or parsing
    // on the spec parameter.
    auto format_stream(std::ostream& os, std::string_view spec) -> std::ostream&;

    template <typename... Args>
    auto format(std::string_view fmtspec, const Args&... args) -> std::string
    {
        std::stringstream ss;
        format_stream(ss, fmtspec, args...);
        return ss.str();
    }
}