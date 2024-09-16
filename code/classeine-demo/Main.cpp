// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja


#include "demo_window.h"

void test()
{
    clsn::demo::demo_window dw;
    dw.set_visible(true);
}

int main()
{
    clsn::ui::ui_manager::run(test);

    return 0;
}