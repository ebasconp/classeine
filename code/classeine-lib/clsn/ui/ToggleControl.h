// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/ClickableControl.h>

namespace clsn::ui
{
    class ToggleControl : public ClickableControl
    {
    public:
        explicit ToggleControl(std::string_view sectionName);

        CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(Checked, true, false)

        virtual void toggle();

    private:
        void initToggleControlEvents();
    };
}