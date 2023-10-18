#pragma once


namespace clsn::gfx
{
    class Dimension final
    {
    public:
        Dimension(int width, int height);

        int getWidth() const noexcept;
        int getHeight() const noexcept;

    private:
        const int m_width;
        const int m_height;
    };
}