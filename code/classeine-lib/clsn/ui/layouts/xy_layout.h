// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/layouts/layout_base.h>

#include <clsn/draw/forward.h>

namespace clsn::ui::layouts
{
    class xy_layout_constraint final
    {
        draw::point m_position;

    public:
        explicit xy_layout_constraint(const draw::point& position);

        [[nodiscard]] auto get_position() const -> const draw::point&;
        void set_position(const draw::point& position);
    };

    class xy_layout final : public layout_base<xy_layout_constraint>
    {
    public:
        using constraint_type = xy_layout_constraint;

        void layout(const clsn::draw::region& rgn) override;
    };
}