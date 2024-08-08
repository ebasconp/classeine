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

    auto Region::getPosition() const noexcept -> const Point& { return m_position; }

    auto Region::get_size() const noexcept -> const Dimension& { return m_size; }

    auto Region::getX() const noexcept -> int { return m_position.getX(); }
    auto Region::getY() const noexcept -> int { return m_position.getY(); }

    int Region::getWidth() const noexcept { return m_size.getWidth(); }
    int Region::getHeight() const noexcept { return m_size.getHeight(); }

    auto Region::operator+(const Point& p) const noexcept -> Region
    {
        return operator+(Region{p, Dimension{0, 0}});
    }

    auto Region::operator+(const Dimension& d) const noexcept -> Region
    {
        return operator+(Region{Point{0, 0}, d});
    }

    auto Region::operator+(const Region& r) const noexcept -> Region
    {
        return {getX() + r.getX(),
                getY() + r.getY(),
                getWidth() + r.getWidth(),
                getHeight() + r.getHeight()};
    }

    auto Region::containsPoint(const Point& p) const noexcept -> bool
    {
        auto px = p.getX();
        auto py = p.getY();

        return px > getX() && px < getX() + getWidth()
            && py > getY() && py < getY() + getHeight();
    }
}