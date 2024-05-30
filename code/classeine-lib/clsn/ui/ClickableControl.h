#pragma once

#include "clsn/ui/Control.h"

#include "clsn/core/EmptyEvent.h"
#include "clsn/core/EventListenerList.h"

#include <memory>

namespace clsn::ui
{
    class ClickableControl : public Control
    {
        bool m_pressed = false;
        EventListenerList<EmptyEvent> m_actionListeners;

    public:
        ClickableControl(std::string_view sectionName)
        : Control{sectionName}
        {
            initEvents();
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

    private:
        void initEvents()
        {
            addMouseClickListener([this](auto& e)
            {
                auto pressedNow = e.getStatus() == clsn::ui::events::MouseClickStatus::pressed;
                if (m_pressed == pressedNow)
                  return;

                m_pressed = pressedNow;
                this->setInvalidated(true);

                if (!m_pressed) // Button has been released, then Action
                {
                   EmptyEvent actionEvent;
                   notifyActionEvent(actionEvent);
                }
            });

            addTextChangedListener([this](auto& )
            {
                this->setInvalidated(true);
            });
        }
    };
}