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

                auto& control = *(getVisibleControls()[controlIndex]);
                if (!control.isEnabled())
                    return;

                clsn::ui::events::MouseClickEvent mce{
                    e.getStatus(), e.getX(), y % controlHeight};
                control.processMouseClickEvent(mce);
            });

        addSizeChangedListener(
            [this](auto& e)
            {
                doLayout();
            });
    }

    void VBoxContainer::doLayout() noexcept
    {
        const auto visibleCount = this->getVisibleCount();
        if (visibleCount == 0)
            return;

        const auto width = getSize().getWidth();
        const auto height = getSize().getHeight() / visibleCount;

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