#include "VBoxContainer.h"

namespace clsn::ui
{
    VBoxContainer::VBoxContainer()
    : ListContainer("VBoxContainer")
    {
        initEvents();
    }

    void VBoxContainer::initEvents()
    {
         addActualSizeChangedListener(
            [this](auto& )
            {
                doLayout();
            });
    }
}