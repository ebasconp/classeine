#include "ToggleControl.h"

namespace clsn::ui
{
    ToggleControl::ToggleControl(std::string_view sectionName)
    : ClickableControl{sectionName}
    {
        initEvents();
    }

    void ToggleControl::toggle()
    {
        setChecked(!isChecked());
    }

    void ToggleControl::initEvents()
    {
        addActionListener([this](auto& )
        {
            toggle();
        });
    }
}