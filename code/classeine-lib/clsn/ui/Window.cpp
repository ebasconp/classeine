// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "Window.h"

#include "UIManager.h"

#include <clsn/core/Console.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(Window, Position, clsn::draw::Point)
    CLSN_CPP_PROPERTY(Window, MinimumSize, clsn::draw::Dimension)
    CLSN_CPP_PROPERTY(Window, Size, clsn::draw::Dimension)
    CLSN_CPP_BOOL_PROPERTY(Window, Resizable)

    Window::Window(std::string_view sectionName)
    : CaptionableControl(sectionName)
    {
        initWindowDefaults();
        initWindowVisibility();
    }

    void Window::initWindowDefaults()
    {
        //ETOTODO: MOVE THIS TO THE tHEME
/*        setMinimumSize(UIManager::get_instance().getDefault(
            getDefaultSectionName(), "minimumSize", Dimension{50, 50}));

        auto& Dimension = UIManager::get_instance().getDefault(
            getDefaultSectionName(), "size", Dimension{300, 200});

        setActualSize(Dimension);*/

        setMinimumSize({50, 50});
        setActualPosition({300, 200});
    }

    void Window::initWindowVisibility()
    {
        setVisible(false);
    }

    void Window::grabMouse(Control& ctrl)
    {
        m_mouseGrabberControl = ctrl;
    }

    void Window::releaseMouse()
    {
        if (m_mouseGrabberControl.hasValue())
        {
            m_mouseGrabberControl.getRef().releaseMouse();
            m_mouseGrabberControl = std::nullopt;
        }
    }

    void Window::processMouseMovedEvent(events::MouseMovedEvent &e)
    {
        auto currently_hovered = getControlByPosition(e.getPosition());
        if (m_hoveredControl != currently_hovered)
        {
            if (m_hoveredControl.hasValue())
            {
                m_hoveredControl.getRef().invalidate();
            }

            m_hoveredControl = currently_hovered;

            if (m_hoveredControl.hasValue())
            {
                clsn::core::Console::debug("Window::processMouseMovedEvent: Ctrl: {}", m_hoveredControl.getRef());
                m_hoveredControl.getRef().invalidate();
            }
        }
    }

    auto Window::isHovered(const Control& Control) const -> bool
    {
        if (!m_hoveredControl.hasValue())
            return false;

        return Control == m_hoveredControl.getRef();
    }

}