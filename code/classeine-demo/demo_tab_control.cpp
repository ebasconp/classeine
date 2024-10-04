// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "demo_tab_control.h"

#include <clsn/ui/button.h>
#include <clsn/ui/label.h>
#include <clsn/ui/toggle_button.h>

namespace clsn::demo
{
    demo_tab_control::demo_tab_control()
    {
        auto [_1, tab1] = this->make_and_add<ui::button>("Tab 1");
        tab1->set_caption("Click me");

        auto [_2, tab2] = this->make_and_add<ui::label>("Tab 2");
        tab2->set_caption("I'm a label");
        tab2->set_enabled(false);

        auto [_3, tab3] = this->make_and_add<ui::toggle_button>("Tab 3");
        tab3->set_caption("Toggle me");
    }
}