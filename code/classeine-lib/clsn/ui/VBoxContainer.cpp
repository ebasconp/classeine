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
        addMouseClickListener(
            [this](auto& e)
            {
                const auto count = getVisibleCount();
                if (count == 0)
                    return;

                const auto y = e.getY();

                const int controlHeight = getSize().getHeight() / count;
                const int controlIndex = y / controlHeight;

                if (controlIndex >= count)
                {
                    e.consume();
                    return;
                }

                auto& control = *(getVisibleControls()[controlIndex]);
                if (!control.isEnabled())
                    return;

                clsn::ui::events::MouseClickEvent mce{
                    e.getStatus(), e.getX(), y % controlHeight};
                control.processMouseClickEvent(mce);
            });

        addSizeChangedListener(
            [this](auto& )
            {
                doLayout();
            });
    }
}