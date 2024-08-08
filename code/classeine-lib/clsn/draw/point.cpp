#include "point.h"

namespace clsn::draw
{
    point::point()
    : point(0, 0)
    {
    }

    point::point(int x, int y)
    : m_x{x}
    , m_y{y}
    {
    }

    auto point::get_x() const noexcept -> int { return m_x; }

    auto point::get_y() const noexcept -> int { return m_y; }

    auto point::operator==(const point& other) const -> bool
    {
        return m_x == other.m_x && m_y == other.m_y;
    }
}