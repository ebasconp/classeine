#pragma once


namespace clsn::draw
{
    class Point final
    {
        int m_x;
        int m_y;

    public:
        Point();
        Point(int x, int y);

        [[nodiscard]] auto getX() const noexcept -> int;
        [[nodiscard]] auto getY() const noexcept -> int;

        auto operator==(const Point& other) const -> bool;
    };
}