#pragma once

#include "clsn/core/event.h"

namespace clsn::ui
{
    class control;
}

namespace clsn::ui::events
{
    class control_event : public core::event
    {
        control& m_control;

    protected:
        explicit control_event(control& ctrl);

    public:
        auto get_control() const -> const control&;
        auto get_control() -> control&;
    };
}
