// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "window.h"

#include "ui_manager.h"

#include <clsn/core/Console.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(window, Position, clsn::draw::Point)
    CLSN_CPP_PROPERTY(window, MinimumSize, clsn::draw::Dimension)
    CLSN_CPP_PROPERTY(window, Size, clsn::draw::Dimension)
    CLSN_CPP_BOOL_PROPERTY(window, Resizable)

    window::window(std::string_view sectionName)
    : captionable_control(sectionName)
    {
        init_visibility();
        init_defaults();
    }

    void window::init_defaults()
    {
        //ETOTODO: MOVE THIS TO THE tHEME
/*        setMinimumSize(ui_manager::get_instance().getDefault(
            get_default_section_name(), "minimumSize", Dimension{50, 50}));

        auto& Dimension = ui_manager::get_instance().getDefault(
            get_default_section_name(), "size", Dimension{300, 200});

        setActualSize(Dimension);*/

        setMinimumSize({50, 50});
        setActualPosition({300, 200});
    }

    void window::init_visibility()
    {
        setVisible(false);
    }

    void window::grab_mouse(control& ctrl)
    {
        m_mouse_grabber_control = ctrl;
    }

    void window::release_mouse()
    {
        if (m_mouse_grabber_control.hasValue())
        {
            m_mouse_grabber_control.getRef().release_mouse();
            m_mouse_grabber_control = std::nullopt;
        }
    }

    void window::process_mouse_moved_event(events::mouse_moved_event &e)
    {
        auto currently_hovered = get_control_by_position(e.getPosition());
        if (m_hovered_control != currently_hovered)
        {
            if (m_hovered_control.hasValue())
            {
                m_hovered_control.getRef().invalidate();
            }

            m_hovered_control = currently_hovered;

            if (m_hovered_control.hasValue())
            {
                clsn::core::Console::debug("window::process_mouse_moved_event: Ctrl: {}", m_hovered_control.getRef());
                m_hovered_control.getRef().invalidate();
            }
        }
    }

    auto window::is_hovered(const control& control) const -> bool
    {
        if (!m_hovered_control.hasValue())
            return false;

        return control == m_hovered_control.getRef();
    }

}