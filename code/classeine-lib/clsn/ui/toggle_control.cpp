#include "toggle_control.h"

namespace clsn::ui
{
    toggle_control::toggle_control(std::string_view section_name)
    : clickable_control{section_name}
    {
        init_events();
    }

    void toggle_control::toggle()
    {
        set_checked(!is_checked());
    }

    void toggle_control::init_events()
    {
        add_action_listener([this](auto& )
        {
            toggle();
        });
    }
}