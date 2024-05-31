#include "FontInfo.h"

namespace clsn::draw
{
    FontInfo::FontInfo(std::string_view name, clsn::draw::FontStyle style)
    : m_name{name}
    , m_style{style}
    {
    }

    auto FontInfo::getName() const noexcept -> const std::string&
    {
        return m_name;
    }

    auto FontInfo::getStyle() const noexcept -> FontStyle { return m_style; }

    auto FontInfo::operator==(const clsn::draw::FontInfo& oth) const -> bool
    {
        if (this == &oth)
            return true;

        return m_name == oth.m_name && m_style == oth.m_style;
    }
}