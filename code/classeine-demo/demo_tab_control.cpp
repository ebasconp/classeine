// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "demo_tab_control.h"

#include <clsn/ui/label.h>
#include <clsn/ui/button.h>

namespace clsn::demo
{
    demo_tab_control::demo_tab_control()
    {
        auto [_2, tab1] = this->make_and_add<ui::button>("Tab 1");
        tab1->set_text("Click me");

        auto [_1, tab2] = this->make_and_add<ui::label>("Tab 1");
        tab2->set_text("I'm a label");
        tab2->set_enabled(false);
    }
}