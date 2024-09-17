// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/paintable_control.h>

namespace clsn::ui
{
    /// This class exposes the *text* property
    class captionable_control : public clsn::ui::paintable_control
    {
    public:
        captionable_control(std::string_view name);

        CLSN_PROPERTY(text, std::string, true);

        auto to_string() const -> std::string override;

    private:
        void init_captionable_control_events();
    };
}
