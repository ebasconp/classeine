#pragma once

#include "clsn/ui/events/control_event.h"

namespace clsn::ui::events
{
    class control_resized_event : public control_event
    {
        int m_width;
        int m_height;

    public:
        control_resized_event(control&, int width, int height);

        auto get_width() const noexcept -> int;
        auto get_height() const noexcept -> int;
    };
}