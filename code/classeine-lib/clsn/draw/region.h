#pragma once

#include "dimension.h"
#include "point.h"

namespace clsn::draw
{
    class region
    {
        point m_position;
        dimension m_size;

    public:
        region(int x, int y, int width, int height);
        region(const point& position, const dimension& size);

        [[nodiscard]] auto get_position() const noexcept -> const point&;

        [[nodiscard]] auto get_size() const noexcept -> const dimension&;

        [[nodiscard]] auto get_x() const noexcept -> int;
        [[nodiscard]] auto get_y() const noexcept -> int;

        [[nodiscard]] auto get_width() const noexcept -> int;
        [[nodiscard]] auto get_height() const noexcept -> int;

        [[nodiscard]] auto contains_point(const point& p) const noexcept -> bool;


        [[nodiscard]] auto operator+(const point& p) const noexcept -> region;
        [[nodiscard]] auto operator+(const dimension& d) const noexcept -> region;
        [[nodiscard]] auto operator+(const region& r) const noexcept -> region;
    };
}