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

        [[nodiscard]] auto getPosition() const noexcept -> const Point&;

        [[nodiscard]] auto getSize() const noexcept -> const Dimension&;

        [[nodiscard]] auto getX() const noexcept -> int;
        [[nodiscard]] auto getY() const noexcept -> int;

        [[nodiscard]] auto getWidth() const noexcept -> int;
        [[nodiscard]] auto getHeight() const noexcept -> int;

        [[nodiscard]] auto containsPoint(const Point& p) const noexcept -> bool;


        [[nodiscard]] auto operator+(const Point& p) const noexcept -> Region;
        [[nodiscard]] auto operator+(const Dimension& d) const noexcept -> Region;
        [[nodiscard]] auto operator+(const Region& r) const noexcept -> Region;
    };
}