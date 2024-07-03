#include "XYContainer.h"

namespace clsn::ui
{
    XYContainer::XYContainer()
    : ListContainer("XYContainer")
    {
        initEvents();
    }

    void XYContainer::initEvents()
    {
        addActualSizeChangedListener([this](auto& )
        {
            doLayout();
        });
    }
}