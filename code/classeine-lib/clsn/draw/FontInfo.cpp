#include "FontInfo.h"

namespace clsn::draw
{
    FontInfo::FontInfo(std::string_view name, clsn::draw::FontStyle style)
    : m_name{name}
    , m_style{style}
    {

    }

    const std::string& FontInfo::getName() const noexcept { return m_name; }

    FontStyle FontInfo::getStyle() const noexcept { return m_style; }

    bool FontInfo::operator==(const clsn::draw::FontInfo& oth) const
    {
        if (this == &oth)
            return true;

        return m_name == oth.m_name && m_style == oth.m_style;
    }
}