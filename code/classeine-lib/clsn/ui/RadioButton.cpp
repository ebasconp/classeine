#include "RadioButton.h"

namespace clsn::ui
{
    RadioButton::RadioButton()
    : ToggleControl("RadioButton")
    {

    }

    void RadioButton::toggle()
    {
        if (!is_checked())
            set_checked(true);
    }
}