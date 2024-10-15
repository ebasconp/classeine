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
        auto tab1 = this->make_and_add<ui::button>("Tab 1");
        tab1->get_control_ptr()->set_caption("Click me");

        auto tab2 = this->make_and_add<ui::label>("Tab 2");
        tab2->get_control_ptr()->set_caption("I'm a label");

        auto tab3 = this->make_and_add<ui::toggle_button>("Tab 3");
        tab3->get_control_ptr()->set_caption("Toggle me");
    }
}