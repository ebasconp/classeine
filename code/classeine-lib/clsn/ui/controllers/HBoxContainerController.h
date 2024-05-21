#pragma once

#include "clsn/ui/events/MouseClickEvent.h"

#include "clsn/draw/Dimension.h"

#include <string_view>

namespace clsn::ui::controllers
{
    class HBoxContainerController final
    {
    public:
        [[nodiscard]] std::string_view getDefaultSectionName() const
        {
            return "HBoxContainer";
        }

        template <typename ContainerType>
        void initEvents(ContainerType& container)
        {
            container.addMouseClickListener(
                [this, &container](auto& e)
                {
                    const auto count = container.getModel().getCount();
                    if (count == 0)
                        return;

                    const auto x = e.getX();

                    const int controlWidth =
                        container.getSize().getWidth() / count;
                    const int controlIndex = x / controlWidth;

                    clsn::ui::events::MouseClickEvent mce{
                        e.getStatus(), x % controlWidth, e.getY()};
                    container.getModel()[controlIndex].processMouseClickEvent(
                        mce);
                });

            container.addSizeChangedListener(
                [this, &container](auto& e)
                {
                    const auto count = container.getModel().getCount();
                    if (count == 0)
                        return;

                    const int controlWidth =
                        container.getSize().getWidth() / count;
                    container.getModel().iterate(
                        [&controlWidth, &container](auto& control)
                        {
                            control.setSize(clsn::draw::Dimension{
                                controlWidth, container.getSize().getHeight()});
                        });
                });
        }
    };
}