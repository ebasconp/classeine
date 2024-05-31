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

    auto Dimension::getWidth() const noexcept -> int { return m_width; }

    auto Dimension::getHeight() const noexcept -> int { return m_height; }

    auto Dimension::operator==(const Dimension& other) const noexcept -> bool
    {
        return m_width == other.m_width && m_height == other.m_height;
    }
}