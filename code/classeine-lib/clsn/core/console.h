#pragma once

#include "strings.h"

#include <iostream>

namespace clsn::core::console
{
    template <typename... Args>
    void print_stream(std::ostream& os, std::string_view fmtspec, const Args&... args)
    {
        strings::format_stream(os, fmtspec, args...);
    }

    template <typename... Args>
    void println_stream(std::ostream& os, std::string_view fmtspec, const Args&... args)
    {
        strings::format_stream(os, fmtspec, args...);
        os << '\n';
    }

    template <typename... Args>
    void print(std::string_view fmtspec, const Args&... args)
    {
        print_stream(std::cout, fmtspec, args...);
    }

    template <typename... Args>
    void println(std::string_view fmtspec, const Args&... args)
    {
        println_stream(std::cout, fmtspec, args...);
    }

#ifdef _CLSN_DEBUG_
    template <typename... Args>
    void debug(std::string_view fmtspec, const Args&... args)
    {
        print("DEBUG: ");
        println(fmtspec, args...);
    }
#else
    inline void debug(std::string_view, ...)
    {
    }
#endif


}