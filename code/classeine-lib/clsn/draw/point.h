#pragma once


namespace clsn::draw
{
    class point final
    {
        int m_x;
        int m_y;

    public:
        point();
        point(int x, int y);

        [[nodiscard]] auto get_x() const noexcept -> int;
        [[nodiscard]] auto get_y() const noexcept -> int;

        auto operator==(const point& other) const -> bool;
    };
}