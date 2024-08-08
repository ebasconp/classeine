#pragma once

#include "ClickableControl.h"

namespace clsn::ui
{
    class ToggleControl : public ClickableControl
    {
    public:
        explicit ToggleControl(std::string_view section_name);

        CLSN_BOOL_PROPERTY_VAL(checked, true, false);

        virtual void toggle();

    private:
        void initEvents();
    };
}