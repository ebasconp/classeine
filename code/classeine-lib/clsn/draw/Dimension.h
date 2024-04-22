#pragma once

namespace clsn::draw
{
    class Dimension final
    {
    public:
        Dimension(int width = 0, int height = 0);

        int getWidth() const noexcept;
        int getHeight() const noexcept;

        bool operator==(const Dimension& other) const noexcept;

    private:
        int m_width;
        int m_height;
    };
}