#pragma once

namespace clsn::draw
{
    class Dimension final
    {
        int m_width;
        int m_height;

    public:
        Dimension();
        Dimension(int width, int height);

        [[nodiscard]] auto getWidth() const noexcept -> int;
        [[nodiscard]] auto getHeight() const noexcept -> int;

        auto operator==(const Dimension& other) const noexcept -> bool;
    };
}