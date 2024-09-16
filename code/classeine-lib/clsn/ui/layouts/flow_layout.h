// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "layout_base.h"

#include <clsn/draw/forward.h>

#include <clsn/core/empty.h>


namespace clsn::ui::layouts
{
    class flow_layout : public layout_base<core::empty>
    {
    public:
        using constraint_type = core::empty;

        void layout(const clsn::draw::region& rgn) override;

    private:
        void layout_vertical(const clsn::draw::point& position, const clsn::draw::dimension& size);
        void layout_horizontal(const clsn::draw::point& position, const clsn::draw::dimension& size);
    };
}