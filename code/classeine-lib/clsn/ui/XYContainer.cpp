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
        addMouseClickListener(
            [this](auto& e)
            {
                const auto count = getCount();
                for (int i = 0; i < count; i++)
                {
                    auto& control = (*this)[i];

                    if (control.containsPoint(e.getPoint()))
                    {
                        clsn::ui::events::MouseClickEvent mce{ e.getStatus(), e.getPoint()};
                        control.processMouseClickEvent(mce);
                    }
                }

            });

        addActualSizeChangedListener([this](auto& )
        {
            doLayout();
        });
    }
}