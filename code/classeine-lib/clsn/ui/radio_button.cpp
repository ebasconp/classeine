// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "radio_button.h"

#include "renderers/radio_button_renderer.h"

namespace clsn::ui
{
    radio_button::radio_button()
    : toggle_control("radio_button")
    {

    }

    void radio_button::toggle()
    {
        if (!isChecked())
            setChecked(true);
    }

    auto radio_button::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::radio_button_renderer>();
    }
}