#pragma once

#include "clsn/core/event.h"

namespace clsn::ui::events
{
    class control_resized_data
    {
    private:
        int m_width;
        int m_height;

    public:
        control_resized_data(int width, int height)
        : m_width{width}
        , m_height{height}
        {
        }

        auto get_width() const noexcept -> int { return m_width; }
        auto get_height() const noexcept -> int { return m_height; }
    };

    using control_resized_event = clsn::core::event<control_resized_data>;
}