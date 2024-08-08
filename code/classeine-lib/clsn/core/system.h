#pragma once

#include "console.h"

namespace clsn::core::system
{
    template <typename... Args>
    void panic(int exitCode, std::string_view fmtspec, const Args&... args)
    {
        console::print_stream(std::cerr, "RUNTIME ERROR: ");
        console::println_stream(std::cerr, fmtspec, args...);
        exit(exitCode);
    }

    template <typename... Args>
    void panic(std::string_view fmtspec, const Args&... args)
    {
        panic(-1, fmtspec, args...);
    }
}