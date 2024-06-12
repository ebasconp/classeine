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

                auto& control = *(getVisibleControls()[controlIndex]);
                if (!control.isEnabled())
                    return;

                clsn::ui::events::MouseClickEvent mce{
                    e.getStatus(), x % controlWidth, e.getY()};
                control.processMouseClickEvent(mce);
            });

        addSizeChangedListener(
            [this](auto& e)
            {
                doLayout();
            });
    }

    void HBoxContainer::doLayout() noexcept
    {
        const auto visibleCount = this->getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto width = getSize().getWidth() / visibleCount;
        const auto height = getSize().getHeight();

        const auto count = this->getCount();
        for (int i = 0; i < count; i++)
        {
            auto& control = (*this)[i];
            if (!control.isVisible())
                continue;

            control.setSize({width, height});
        }
    }

}