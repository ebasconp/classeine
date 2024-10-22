// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja


#include "demo_window.h"

void test()
{
    clsn::demo::demo_window dw;
    dw.setVisible(true);
}

int main()
{
    clsn::ui::UIManager::run(test);

    return 0;
}