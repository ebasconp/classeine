#pragma once

#include "clsn/core/EmptyEvent.h"
#include "clsn/core/EventListenerList.h"

#include <string_view>

namespace clsn::ui::controllers
{
    using namespace clsn::core;

    class ButtonController
    {
    private:
        bool m_pressed = false;
        EventListenerList<EmptyEvent> m_actionListeners;

    public:
        ButtonController() = default;

        [[nodiscard]] std::string_view getDefaultSectionName() const
        {
            return "Button";
        }

        [[nodiscard]] bool isPressed() const noexcept { return m_pressed; }

        void addActionListener(EventListener<EmptyEvent> event)
        {
            m_actionListeners.add(std::move(event));
        }

        void notifyActionEvent(EmptyEvent& e)
        {
            m_actionListeners.notify(e);
        }

        template <typename ControlType>
        void initEvents(ControlType& control)
        {
            control.addMouseClickListener([this, &control](auto& e)
            {
                auto pressedNow = e.getStatus() == clsn::ui::events::MouseClickStatus::pressed;
                if (m_pressed == pressedNow)
                    return;

                m_pressed = pressedNow;
                // control.repaint(); //ETOTODO
            });
        }
    };
}