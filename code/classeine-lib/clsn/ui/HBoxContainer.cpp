#include "HBoxContainer.h"

namespace clsn::ui
{
    HBoxContainer::HBoxContainer()
    : ListContainer("HBoxContainer")
    {
        initEvents();
    }

    void HBoxContainer::initEvents()
    {
        addActualSizeChangedListener(
            [this](auto& )
            {
                doLayout();
            });
    }
}