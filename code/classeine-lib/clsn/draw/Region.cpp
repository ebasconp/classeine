#include "Region.h"


namespace clsn::draw
{
    Region::Region(const Point& position, const Dimension& size)
    : m_position{position}
    , m_size{size}
    {

    }

    Region::Region(int x, int y, int width, int height)
    : Region{Point{x, y}, Dimension{width, height}}
    {

    }

    const Point& Region::getPosition() const noexcept { return m_position; }

    const Dimension& Region::getSize() const noexcept { return m_size; }

    int Region::getX() const noexcept { return m_position.getX(); }
    int Region::getY() const noexcept { return m_position.getY(); }

    int Region::getWidth() const noexcept { return m_size.getWidth(); }
    int Region::getHeight() const noexcept { return m_size.getHeight(); }
}