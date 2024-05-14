#include "Dimension.h"

namespace clsn::draw
{
    Dimension::Dimension()
    : Dimension(0, 0)
    {
    }

    Dimension::Dimension(int width, int height)
    : m_width{width}
    , m_height{height}
    {
    }

    int Dimension::getWidth() const noexcept { return m_width; }

    int Dimension::getHeight() const noexcept { return m_height; }

    bool Dimension::operator==(const Dimension& other) const noexcept
    {
        return m_width == other.m_width && m_height == other.m_height;
    }
}