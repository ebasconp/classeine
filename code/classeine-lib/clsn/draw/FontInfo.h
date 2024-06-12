#pragma once

#include "FontStyle.h"

#include <string>
#include <string_view>

namespace clsn::draw
{
    class FontInfo final
    {
        std::string m_name;
        FontStyle m_style;

    public:
        FontInfo(std::string_view name, FontStyle style);

        auto operator==(const FontInfo& oth) const -> bool;

        auto getStyle() const noexcept -> FontStyle;
        auto getName() const noexcept -> const std::string&;
    };
}

template <>
struct std::hash<clsn::draw::FontInfo>
{
    auto operator()(const clsn::draw::FontInfo& fontInfo) const noexcept -> int
    {
        return std::hash<std::string>{}(fontInfo.getName()) * 31 +
               static_cast<int>(fontInfo.getStyle());
    }
};
