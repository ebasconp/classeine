#pragma once

#include "clsn/core/Event.h"

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

        int getWidth() const noexcept { return m_width; }
        int getHeight() const noexcept { return m_height; }
    };

    using ControlResizedEvent = clsn::core::Event<ControlResizedData>;
}