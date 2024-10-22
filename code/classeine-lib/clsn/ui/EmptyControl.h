// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/Control.h>

namespace clsn::ui
{
    class EmptyControl final : public Control
    {
    public:
        EmptyControl();

    protected:
        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;
    };
}