#include "Point.h"

namespace clsn::draw
{
    Point::Point(int x, int y)
    : m_x{x}
    , m_y{y}
    {
    }

    auto Point::getX() const noexcept -> int { return m_x; }

    auto Point::getY() const noexcept -> int { return m_y; }
}