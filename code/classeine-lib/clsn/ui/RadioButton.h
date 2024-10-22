// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/ToggleControl.h>

namespace clsn::ui
{
    class RadioButton : public ToggleControl
    {
    public:
        RadioButton();

        void toggle() override;

    protected:
        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;
    };
}