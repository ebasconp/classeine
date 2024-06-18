#include "Window.h"

namespace clsn::ui
{
    Window::Window(std::string_view sectionName)
    : Control(sectionName)
    {
        initVisibility();
        initDefaults();
    }

    void Window::initDefaults()
    {
        setMinimumSize(UIManager::getInstance().getDefault(
            getDefaultSectionName(), "minimumSize", Dimension{50, 50}));

        auto& dimension = UIManager::getInstance().getDefault(
            getDefaultSectionName(), "size", Dimension{300, 200});

        setSize(dimension);
    }

    void Window::initVisibility()
    {
        setVisible(false);
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
}