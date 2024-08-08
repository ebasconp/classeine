#pragma once

#include "toggle_control.h"

namespace clsn::ui
{
    class radio_button : public toggle_control
    {
    public:
        radio_button();

        void toggle() override;
    };
}