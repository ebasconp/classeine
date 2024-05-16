#pragma once


namespace clsn::draw
{
    class Point final
    {
        int m_x;
        int m_y;

    public:
        Point(int x, int y);

        int getX() const noexcept;
        int getY() const noexcept;
    };
}