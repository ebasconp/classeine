// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/amatista/AmatistaUISkin.h>

#include <clsn/ui/amatista/DarkAmatistaUITheme.h>
#include <clsn/ui/amatista/LightAmatistaUITheme.h>

namespace
{
    using namespace clsn::ui;

    void load_themes(amatista::AmatistaUISkin& skin)
    {
        skin.makeThemeAndAdd<amatista::LightAmatistaUITheme>("light");
        skin.makeThemeAndAdd<amatista::DarkAmatistaUITheme>("dark");

        skin.installThemeByName("light");
    }
}

namespace clsn::ui::amatista
{
    AmatistaUISkin::AmatistaUISkin()
    {
        load_themes(*this);
    }
}