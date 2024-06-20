#include "Point.h"

namespace clsn::draw
{
    Point::Point()
    : Point(0, 0)
    {
    }

    Point::Point(int x, int y)
    : m_x{x}
    , m_y{y}
    {
    }

    auto Point::getX() const noexcept -> int { return m_x; }

    auto Point::getY() const noexcept -> int { return m_y; }

    auto Point::operator==(const Point& other) const -> bool
    {
        return m_x == other.m_x && m_y == other.m_y;
    }
}