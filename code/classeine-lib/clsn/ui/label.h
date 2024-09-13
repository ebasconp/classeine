// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "control.h"

#include "clsn/draw/forward.h"

namespace clsn::ui
{
    class label : public control
    {
        clsn::draw::text_horizontal_alignment m_horizontal_alignment;
        clsn::draw::text_vertical_alignment m_vertical_alignment;

    public:
        label();

        auto get_horizontal_alignment() const -> clsn::draw::text_horizontal_alignment;
        auto get_vertical_alignment() const -> clsn::draw::text_vertical_alignment;

        void set_horizontal_alignment(clsn::draw::text_horizontal_alignment horizontal_alignment);
        void set_vertical_alignment(clsn::draw::text_vertical_alignment vertical_alignment);

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;

    };
}