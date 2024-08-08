#include "Font.h"

#include <tuple>

namespace clsn::draw
{
    Font::Font() : Font{"", FontStyle::REGULAR, 0}
    {
    }

    auto Font::getName() const noexcept -> const std::string&
    {
        return m_name;
    }

    auto Font::get_size() const noexcept -> int
    {
        return m_size;
    }

    auto Font::getStyle() const noexcept -> FontStyle
    {
        return m_style;
    }

    auto Font::operator==(const Font& other) const noexcept -> bool
    {
        return std::tie(m_name, m_style, m_size) ==
               std::tie(other.m_name, other.m_style, other.m_size);
    }
}