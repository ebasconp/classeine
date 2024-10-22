// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/ClickableControl.h>

namespace clsn::ui
{
    class Button : public ClickableControl
    {
    public:
        Button();

    protected:
        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;
    };
}