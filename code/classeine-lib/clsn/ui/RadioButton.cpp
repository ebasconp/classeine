#include "RadioButton.h"

namespace clsn::ui
{
    RadioButton::RadioButton()
    : ToggleControl("RadioButton")
    {

    }

    void RadioButton::toggle()
    {
        if (!isChecked())
            setChecked(true);
    }
}