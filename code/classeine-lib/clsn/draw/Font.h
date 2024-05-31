#pragma once

#include "FontStyle.h"

#include <string>
#include <utility>

namespace clsn::draw
{
    class Font
    {
        std::string m_name;
        FontStyle m_style;
        int m_size;

    public:
        Font();

        template <typename StringType>
        Font(StringType&& name, FontStyle style, int size)
        : m_name{std::forward<StringType>(name)}
        , m_style{style}
        , m_size{size}
        {
        }

        auto getName() const noexcept -> const std::string&;
        auto getSize() const noexcept -> int;
        auto getStyle() const noexcept -> FontStyle;

        bool operator==(const Font& font) const noexcept;
    };
}

namespace std
{
    template <>
    struct hash<clsn::draw::Font>
    {
        auto operator()(const clsn::draw::Font& font) const -> int
        {
            return std::hash<std::string>{}(font.getName()) * 31 +
                   static_cast<int>(font.getStyle()) * 31 + font.getSize();
        }
    };
}