#pragma once

#include "ClickableControl.h"

namespace clsn::ui
{
    class ToggleControl : public ClickableControl
    {
    public:
        explicit ToggleControl(std::string_view sectionName);

        CLSN_BOOL_PROPERTY_VAL(Checked, true, false);

        void toggle();

    private:
        void initEvents();
    };
}