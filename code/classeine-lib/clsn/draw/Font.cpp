#include "Font.h"

#include <tuple>

namespace clsn::draw
{
    Font::Font() : Font{"", FontStyle::REGULAR, 0}
    {
    }

    const std::string& Font::getName() const noexcept { return m_name; }

    int Font::getSize() const noexcept { return m_size; }

    FontStyle Font::getStyle() const noexcept { return m_style; }

    bool Font::operator==(const Font& other) const noexcept
    {
        return std::tie(m_name, m_style, m_size) ==
               std::tie(other.m_name, other.m_style, other.m_size);
    }
}