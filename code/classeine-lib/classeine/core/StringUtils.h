#pragma once

#include <string>
#include <sstream>

namespace classeine::core::StringUtils
{
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