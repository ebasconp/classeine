#pragma once

namespace clsn::draw
{
    class Dimension final
    {
    public:
        Dimension();
        Dimension(int width, int height);

        [[nodiscard]] int getWidth() const noexcept;
        [[nodiscard]] int getHeight() const noexcept;

        bool operator==(const Dimension& other) const noexcept;

    private:
        int m_width;
        int m_height;
    };
}