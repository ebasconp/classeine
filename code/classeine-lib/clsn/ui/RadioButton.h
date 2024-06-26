#pragma once

#include "ToggleControl.h"

namespace clsn::ui
{
    class RadioButton : public ToggleControl
    {
    public:
        RadioButton();

        void toggle() override;
    };
}