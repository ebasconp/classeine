#include "region.h"

namespace clsn::draw
{
    region::region(const point& position, const dimension& size)
    : m_position{position}
    , m_size{size}
    {
    }

    region::region(int x, int y, int width, int height)
    : region{point{x, y}, dimension{width, height}}
    {
    }

    auto region::get_position() const noexcept -> const point& { return m_position; }

    auto region::get_size() const noexcept -> const dimension& { return m_size; }

    auto region::get_x() const noexcept -> int { return m_position.get_x(); }
    auto region::get_y() const noexcept -> int { return m_position.get_y(); }

    int region::get_width() const noexcept { return m_size.get_width(); }
    int region::get_height() const noexcept { return m_size.get_height(); }

    auto region::operator+(const point& p) const noexcept -> region
    {
        return operator+(region{p, dimension{0, 0}});
    }

    auto region::operator+(const dimension& d) const noexcept -> region
    {
        return operator+(region{point{0, 0}, d});
    }

    auto region::operator+(const region& r) const noexcept -> region
    {
        return {get_x() + r.get_x(),
                get_y() + r.get_y(),
                get_width() + r.get_width(),
                get_height() + r.get_height()};
    }

    auto region::contains_point(const point& p) const noexcept -> bool
    {
        auto px = p.get_x();
        auto py = p.get_y();

        return px > get_x() && px < get_x() + get_width()
            && py > get_y() && py < get_y() + get_height();
    }
}