#pragma once

namespace clsn::ui::controllers
{
    class VBoxContainerController final
    {
    public:
        [[nodiscard]] std::string_view getDefaultSectionName() const
        {
            return "VBoxContainer";
        }

        template <typename ContainerType>
        void initEvents(ContainerType& container)
        {
            container.addMouseClickListener([this, &container](auto& e)
            {
                const auto count = container.getModel().getVisibleCount();
                if (count == 0)
                    return;

                const auto y = e.getY();

                const int controlHeight = container.getSize().getHeight() / count;
                const int controlIndex = y / controlHeight;

                auto& control = container.getModel()[controlIndex];
                if (!control.isEnabled())
                    return;

                clsn::ui::events::MouseClickEvent mce{e.getStatus(), e.getX(), y % controlHeight};
                control.processMouseClickEvent(mce);
            });

            container.addSizeChangedListener([this, &container](auto& e)
            {
                const auto count = container.getModel().getCount();
                if (count == 0)
                    return;

                const int controlHeight = container.getSize().getHeight() / count;
                container.getModel().iterate([&container, &controlHeight](auto& control)
                {
                    control.setSize(Dimension{container.getSize().getWidth(), controlHeight});
                });
            });

            container.addInvalidatedChangedListener([&container](auto& e)
            {
                const bool isInvalidated = e.getNewValue();
                if (!isInvalidated)
                    return;

                container.getModel().iterate([&isInvalidated](auto& control)
                {
                    control.setInvalidated(isInvalidated);
                });
            });
        }
    };
}