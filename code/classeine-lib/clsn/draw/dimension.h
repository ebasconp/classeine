#pragma once

#include <string>

namespace clsn::draw
{
    class dimension final
    {
        int m_width;
        int m_height;

    public:
        dimension();
        dimension(int width, int height);

        [[nodiscard]] auto get_width() const noexcept -> int;
        [[nodiscard]] auto get_height() const noexcept -> int;

        auto operator==(const dimension& other) const noexcept -> bool;

        auto to_string() const -> std::string;
    };
}