// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "window.h"

#include "ui_manager.h"

#include <clsn/core/console.h>

namespace clsn::ui
{
    window::window(std::string_view section_name)
    : captionable_control(section_name)
    {
        init_visibility();
        init_defaults();
    }

    void window::init_defaults()
    {
        //ETOTODO: MOVE THIS TO THE tHEME
/*        setMinimumSize(ui_manager::get_instance().getDefault(
            get_default_section_name(), "minimumSize", dimension{50, 50}));

        auto& dimension = ui_manager::get_instance().getDefault(
            get_default_section_name(), "size", dimension{300, 200});

        set_actual_size(dimension);*/

        set_minimum_size({50, 50});
        set_actual_position({300, 200});
    }

    void window::init_visibility()
    {
        set_visible(false);
    }

    void window::grab_mouse(control& ctrl)
    {
        m_mouse_grabber_control = ctrl;
    }

    void window::release_mouse()
    {
        if (m_mouse_grabber_control.has_value())
        {
            m_mouse_grabber_control.get_ref().release_mouse();
            m_mouse_grabber_control = std::nullopt;
        }
    }

    void window::process_mouse_moved_event(events::mouse_moved_event &e)
    {
        auto currently_hovered = get_control_by_position(e.get_position());
        if (m_hovered_control != currently_hovered)
        {
            if (m_hovered_control.has_value())
            {
                m_hovered_control.get_ref().invalidate();
            }

            m_hovered_control = currently_hovered;

            if (m_hovered_control.has_value())
            {
                clsn::core::console::debug("window::process_mouse_moved_event: Ctrl: {}", m_hovered_control.get_ref());
                m_hovered_control.get_ref().invalidate();
            }
        }
    }

    auto window::is_hovered(const control& control) const -> bool
    {
        if (!m_hovered_control.has_value())
            return false;

        return control == m_hovered_control.get_ref();
    }

}