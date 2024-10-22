// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "CheckBox.h"

#include "renderers/CheckBoxRenderer.h"

namespace clsn::ui
{
    CheckBox::CheckBox()
    : ToggleControl("CheckBox")
    {

    }

    auto CheckBox::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::CheckBoxRenderer>();
    }
}