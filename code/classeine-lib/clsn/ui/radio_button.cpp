#include "radio_button.h"

namespace clsn::ui
{
    radio_button::radio_button()
    : toggle_control("radio_button")
    {

    }

    void radio_button::toggle()
    {
        if (!is_checked())
            set_checked(true);
    }
}