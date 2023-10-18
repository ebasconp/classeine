#pragma once

#include <string>
#include <sstream>

namespace clsn::core::StringUtils
{
    template <typename OutputStream>
    OutputStream& buildStream(OutputStream& os)
    {
        return os;
    }

    template <typename OutputStream, typename T, typename... Args>
    OutputStream& buildStream(OutputStream& os, const T& value, const Args&... args)
    {
        os << value;
        return buildStream(os, args...);
    }

    template <typename... Args>
    std::string buildString(const Args& ... args)
    {
        std::stringstream ss;
        return buildStream(ss, args...).str();
    }
}