// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/toggle_control_group.h>

#include <clsn/ui/toggle_control.h>

namespace clsn::ui
{
    void toggle_control_group::add(std::shared_ptr<toggle_control> _toggle_control)
    {
        init_events(*_toggle_control);
        m_toggle_controls.push_back(std::move(_toggle_control));
    }

    void toggle_control_group::init_events(toggle_control& _toggle_control)
    {
        _toggle_control.add_action_listener([this, &_toggle_control](auto&)
        {
            for (auto& ptr : m_toggle_controls)
            {
                if (ptr.get() == &_toggle_control)
                    continue;

                ptr->set_checked(false);
                ptr->invalidate();
            }
        });
    }
}