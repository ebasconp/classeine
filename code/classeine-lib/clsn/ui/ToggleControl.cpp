#include "ToggleControl.h"

namespace clsn::ui
{
    ToggleControl::ToggleControl(std::string_view section_name)
    : ClickableControl{section_name}
    {
        initEvents();
    }

    void ToggleControl::toggle()
    {
        set_checked(!is_checked());
    }

    void ToggleControl::initEvents()
    {
        add_action_listener([this](auto& )
        {
            toggle();
        });
    }
}