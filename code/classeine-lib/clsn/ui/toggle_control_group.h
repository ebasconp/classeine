// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <memory>
#include <vector>

namespace clsn::ui
{
    class toggle_control;

    class toggle_control_group final
    {
        std::vector<std::shared_ptr<toggle_control>> m_toggle_controls;

    public:
        void add(std::shared_ptr<toggle_control> _toggle_control);

    private:
        void init_events(toggle_control& _toggle_control);
    };
}