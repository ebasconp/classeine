#pragma once

#include "FontStyle.h"

#include <string>
#include <string_view>
#include <unordered_map>

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

namespace std
{
    template <>
    struct hash<clsn::draw::FontInfo>
    {
        int operator()(const clsn::draw::FontInfo& fontInfo) const
        {
            return std::hash<std::string>{}(fontInfo.getName()) * 31 +
                   static_cast<int>(fontInfo.getStyle());
        }
    };
}