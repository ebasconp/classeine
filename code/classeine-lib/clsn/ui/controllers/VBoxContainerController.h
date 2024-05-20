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
                const auto count = container.getModel().getCount();
                if (count == 0)
                    return;

                const auto y = e.getY();

                const int controlHeight = container.getSize().getHeight() / count;
                const int controlIndex = y / controlHeight;

                clsn::ui::events::MouseClickEvent mce{e.getStatus(), e.getX(), y % controlHeight};
                container.getModel()[controlIndex].processMouseClickEvent(mce);
            });
        }
    };
}