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

                const auto x = e.getPoint().getX();

                const int controlWidth = getActualSize().getWidth() / count;
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
                    e.getStatus(), Point{x % controlWidth, e.getPoint().getY()}};
                control.processMouseClickEvent(mce);
            });

        addActualSizeChangedListener(
            [this](auto& )
            {
                doLayout();
            });
    }

}