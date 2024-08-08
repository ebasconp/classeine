#include "dimension.h"

namespace clsn::draw
{
    dimension::dimension()
    : dimension(0, 0)
    {
    }

    dimension::dimension(int width, int height)
    : m_width{width}
    , m_height{height}
    {
    }

    auto dimension::get_width() const noexcept -> int { return m_width; }

    auto dimension::get_height() const noexcept -> int { return m_height; }

    auto dimension::operator==(const dimension& other) const noexcept -> bool
    {
        return m_width == other.m_width && m_height == other.m_height;
    }
}