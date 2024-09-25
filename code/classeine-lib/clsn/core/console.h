/// @file
/// @brief Console utility class for printing formatted strings.
/// @copyright © 2024 Ernesto Bascón Pantoja
/// @license BSD-3-Clause

#pragma once

#include <clsn/core/non_instantiable.h>
#include <clsn/core/strings.h>

#include <iostream>

namespace clsn::core
{
    /// @brief Console class with static methods for console services.
    class console final : public non_instantiable
    {
    public:
        /// @brief Prints a formatted string to the given output stream.
        /// @tparam Args Variadic template arguments.
        /// @param os The output stream to print to.
        /// @param fmtspec The format specification string.
        /// @param args The arguments to format.
        template <typename... Args>
        static void print_stream(std::ostream& os, std::string_view fmtspec, const Args&... args)
        {
            strings::format_stream(os, fmtspec, args...);
        }

        /// @brief Prints a formatted string to the given output stream and appends a newline.
        /// @tparam Args Variadic template arguments.
        /// @param os The output stream to print to.
        /// @param fmtspec The format specification string.
        /// @param args The arguments to format.
        template <typename... Args>
        static void println_stream(std::ostream& os, std::string_view fmtspec, const Args&... args)
        {
            strings::format_stream(os, fmtspec, args...);
            os << '\n';
        }

        /// @brief Prints a formatted string to the standard output stream.
        /// @tparam Args Variadic template arguments.
        /// @param fmtspec The format specification string.
        /// @param args The arguments to format.
        template <typename... Args>
        static void print(std::string_view fmtspec, const Args&... args)
        {
            print_stream(std::cout, fmtspec, args...);
        }

        /// @brief Prints a formatted string to the standard output stream and appends a newline.
        /// @tparam Args Variadic template arguments.
        /// @param fmtspec The format specification string.
        /// @param args The arguments to format.
        template <typename... Args>
        static void println(std::string_view fmtspec, const Args&... args)
        {
            println_stream(std::cout, fmtspec, args...);
        }

#ifdef _CLSN_DEBUG_
        /// @brief Prints a debug message to the standard output stream if debugging is enabled.
        /// @tparam Args Variadic template arguments.
        /// @param fmtspec The format specification string.
        /// @param args The arguments to format.
        template <typename... Args>
        static void debug(std::string_view fmtspec, const Args&... args)
        {
            print("DEBUG: ");
            print(fmtspec, args...);
            std::cout << std::endl;
        }
#else
        /// @brief No-op function for debug messages when debugging is disabled.
        /// @param fmtspec The format specification string (ignored).
        static inline void debug(std::string_view, ...)
        {
        }
#endif
    };
}