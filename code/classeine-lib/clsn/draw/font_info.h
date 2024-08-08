#pragma once

#include "font_style.h"

#include <string>
#include <string_view>

namespace clsn::draw
{
    class font_info final
    {
        std::string m_name;
        font_style m_style;

    public:
        font_info(std::string_view name, font_style style);

        auto operator==(const font_info& oth) const -> bool;

        auto get_style() const noexcept -> font_style;
        auto get_name() const noexcept -> const std::string&;
    };
}

template <>
struct std::hash<clsn::draw::font_info>
{
    auto operator()(const clsn::draw::font_info& a_font_info) const noexcept -> int
    {
        return std::hash<std::string>{}(a_font_info.get_name()) * 31 +
               static_cast<int>(a_font_info.get_style());
    }
};
