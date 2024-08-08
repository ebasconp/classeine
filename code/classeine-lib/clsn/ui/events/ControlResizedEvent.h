#pragma once

#include "clsn/core/event.h"

namespace clsn::ui::events
{
    class ControlResizedData
    {
    private:
        int m_width;
        int m_height;

    public:
        ControlResizedData(int width, int height)
        : m_width{width}
        , m_height{height}
        {
        }

        auto getWidth() const noexcept -> int { return m_width; }
        auto getHeight() const noexcept -> int { return m_height; }
    };

    using ControlResizedEvent = clsn::core::event<ControlResizedData>;
}