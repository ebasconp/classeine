// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/amatista/amatista_ui_skin.h>

#include <clsn/ui/amatista/dark_amatista_ui_theme.h>
#include <clsn/ui/amatista/light_amatista_ui_theme.h>

namespace
{
    using namespace clsn::ui;

    void load_themes(amatista::amatista_ui_skin& skin)
    {
        skin.make_theme_and_add<amatista::light_amatista_ui_theme>("light");
        skin.make_theme_and_add<amatista::dark_amatista_ui_theme>("dark");

        skin.install_theme_by_name("light");
    }
}

namespace clsn::ui::amatista
{
    amatista_ui_skin::amatista_ui_skin()
    {
        load_themes(*this);
    }
}