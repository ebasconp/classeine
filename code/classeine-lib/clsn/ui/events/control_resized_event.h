#pragma once

#include "clsn/core/event.h"

namespace clsn::ui::events
{
    class control_resized_event : public core::event
    {
        int m_width;
        int m_height;

    public:
        control_resized_event(int width, int height);

        auto get_width() const noexcept -> int;
        auto get_height() const noexcept -> int;
    };
}