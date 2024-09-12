// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "control.h"

namespace clsn::ui
{
    class empty_control final : public control
    {
    public:
        empty_control();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}