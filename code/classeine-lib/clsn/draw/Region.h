#pragma once

#include "Dimension.h"
#include "Point.h"

namespace clsn::draw
{
    class Region
    {
        Point m_position;
        Dimension m_size;

    public:
        Region(int x, int y, int width, int height);
        Region(const Point& position, const Dimension& size);

        const Point& getPosition() const noexcept;

        const Dimension& getSize() const noexcept;

        int getX() const noexcept;
        int getY() const noexcept;

        int getWidth() const noexcept;
        int getHeight() const noexcept;

        Region operator+(const Point& p) const noexcept;
        Region operator+(const Dimension& d) const noexcept;
        Region operator+(const Region& r) const noexcept;
    };
}