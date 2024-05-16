#include "Point.h"

namespace clsn::draw
{
    Point::Point(int x, int y)
    : m_x{x}
    , m_y{y}
    {
    }

    int Point::getX() const noexcept { return m_x; }

    int Point::getY() const noexcept { return m_y; }
}