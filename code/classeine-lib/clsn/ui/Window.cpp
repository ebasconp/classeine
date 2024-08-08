#include "Window.h"

#include "UIManager.h"

#include <iostream> //ETOTODO: REMOVE THIS

namespace
{
    using namespace clsn::ui;

    auto areEqual(
            const ConstControlOptionalReference& a,
            const ConstControlOptionalReference& b) -> bool
    {
        if (a.has_value() != b.has_value())
            return false;

        if (!a.has_value())
            return true;

        return a.value().get() == b.value().get();
    }
}
namespace clsn::ui
{
    Window::Window(std::string_view section_name)
    : Control(section_name)
    {
        initVisibility();
        initDefaults();
    }

    void Window::initDefaults()
    {
        //ETOTODO: MOVE THIS TO THE tHEME
/*        setMinimumSize(UIManager::getInstance().getDefault(
            getDefaultSectionName(), "minimumSize", dimension{50, 50}));

        auto& dimension = UIManager::getInstance().getDefault(
            getDefaultSectionName(), "size", dimension{300, 200});

        set_actual_size(dimension);*/

        set_minimum_size({50, 50});
        set_actual_position({300, 200});
    }

    void Window::initVisibility()
    {
        set_visible(false);
    }

    void Window::grabMouse(Control& control)
    {
        m_mouseGrabberControl = std::ref(control);
    }

    void Window::releaseMouse()
    {
        if (m_mouseGrabberControl.has_value())
        {
            m_mouseGrabberControl.value().get().releaseMouse();
            m_mouseGrabberControl = std::nullopt;
        }
    }

    void Window::processMouseMovedEvent(events::MouseMovedEvent &e)
    {
        auto currentlyHovered = getControlByPosition(e.position);
        if (!areEqual(m_hoveredControl, currentlyHovered))
        {
            if (m_hoveredControl.has_value())
            {
                m_hoveredControl.value().get().invalidate();
            }

            m_hoveredControl = currentlyHovered;

            if (m_hoveredControl.has_value())
            {
                m_hoveredControl.value().get().invalidate();
            }

        }
    }

    auto Window::isHovered(const Control& control) const -> bool
    {
        if (!m_hoveredControl.has_value())
            return false;

        return control == m_hoveredControl.value().get();
    }

}