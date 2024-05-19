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

        const std::string& getName() const noexcept;
        int getSize() const noexcept;
        FontStyle getStyle() const noexcept;

        bool operator==(const Font& font) const noexcept;
    };
}

namespace std
{
    template <>
    struct hash<clsn::draw::Font>
    {
        int operator()(const clsn::draw::Font& font) const
        {
            return std::hash<std::string>{}(font.getName()) * 31 +
                   static_cast<int>(font.getStyle()) * 31 + font.getSize();
        }
    };
}