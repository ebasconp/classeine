#pragma once


namespace clsn::draw
{
    class Point final
    {
        int m_x;
        int m_y;

    public:
        Point(int x, int y);

        auto getX() const noexcept -> int;
        auto getY() const noexcept -> int;
    };
}