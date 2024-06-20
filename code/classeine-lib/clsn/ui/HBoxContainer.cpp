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
        addMouseClickListener(
            [this](auto& e)
            {
                const auto count = getVisibleCount();
                if (count == 0)
                    return;

                const auto x = e.getX();

                const int controlWidth = getSize().getWidth() / count;
                const int controlIndex = x / controlWidth;

                if (controlIndex >= count)
                {
                    e.consume();
                    return;
                }

                auto& control = *(getVisibleControls()[controlIndex]);
                if (!control.isEnabled())
                    return;

                clsn::ui::events::MouseClickEvent mce{
                    e.getStatus(), x % controlWidth, e.getY()};
                control.processMouseClickEvent(mce);
            });

        addSizeChangedListener(
            [this](auto& )
            {
                doLayout();
            });
    }

}