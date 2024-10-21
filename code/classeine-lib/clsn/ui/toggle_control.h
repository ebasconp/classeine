// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clickable_control.h"

namespace clsn::ui
{
    class toggle_control : public clickable_control
    {
    public:
        explicit toggle_control(std::string_view sectionName);

        CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(Checked, true, false)

        virtual void toggle();

    private:
        void init_events();
    };
}