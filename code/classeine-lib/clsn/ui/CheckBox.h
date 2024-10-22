// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "ToggleControl.h"

namespace clsn::ui
{
    class CheckBox : public ToggleControl
    {
    public:
        CheckBox();

    protected:
        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;
    };
}