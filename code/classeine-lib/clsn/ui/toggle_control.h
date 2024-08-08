#pragma once

#include "clickable_control.h"

namespace clsn::ui
{
    class toggle_control : public clickable_control
    {
    public:
        explicit toggle_control(std::string_view section_name);

        CLSN_BOOL_PROPERTY_VAL(checked, true, false);

        virtual void toggle();

    private:
        void init_events();
    };
}