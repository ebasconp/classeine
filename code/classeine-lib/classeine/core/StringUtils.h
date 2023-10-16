#pragma once

#include <string>
#include <sstream>

namespace classeine::core::StringUtils
{
    namespace detail
    {
        void innerBuildString(std::string&) { }

        template <typename T, typename... Args>
        void innerBuildString(std::string& str, const T& value, const Args&... args)
        {
            str += std::to_string(value);
            innerBuildString(str, args...);
        }
    }

    template <typename OutputStream>
    void buildStream(OutputStream&)
    {
    }

    template <typename OutputStream, typename T, typename... Args>
    void buildStream(OutputStream& os, const T& value, const Args&... args)
    {
        os << value;
        buildStream(os, args...);
    }

    template <typename... Args>
    std::string buildString(const Args& ... args)
    {
        std::stringstream ss;
        buildStream(ss, args...);
        return ss.str();
    }
}