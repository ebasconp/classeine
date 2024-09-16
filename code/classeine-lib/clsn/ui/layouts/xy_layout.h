// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "layout_base.h"

#include <clsn/draw/forward.h>

namespace clsn::ui::layouts
{
    class xy_layout : public layout_base<clsn::draw::point>
    {
    public:
        using constraint_type = clsn::draw::point;

        void layout(const clsn::draw::region& rgn) override;
    };
}