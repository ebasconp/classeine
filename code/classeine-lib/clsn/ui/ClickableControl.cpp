#include "ClickableControl.h"

namespace clsn::ui
{
    ClickableControl::ClickableControl(std::string_view sectionName)
    : Control{sectionName}
    {
        initEvents();
    }

    [[nodiscard]] auto ClickableControl::isPressed() const noexcept -> bool
    {
        return m_pressed;
    }

    void ClickableControl::addActionListener(EventListener<EmptyEvent> event)
    {
        m_actionListeners.add(std::move(event));
    }

    void ClickableControl::notifyActionEvent(EmptyEvent& e)
    {
        m_actionListeners.notify(e);
    }

    void ClickableControl::initEvents()
    {
        addMouseClickListener(
            [this](auto& e)
            {
                auto pressedNow = e.getStatus() ==
                                  clsn::ui::events::MouseClickStatus::pressed;
                if (m_pressed == pressedNow)
                    return;

                m_pressed = pressedNow;
                this->invalidate();

                if (!m_pressed) // Button has been released, then Action
                {
                    EmptyEvent actionEvent;
                    notifyActionEvent(actionEvent);
                }
            });

        addTextChangedListener([this](auto&) { invalidate(); });
    }
}