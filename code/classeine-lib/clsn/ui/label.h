// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/captionable_control.h>

#include <clsn/draw/Forward.h>

namespace clsn::ui
{
    class label : public captionable_control
    {
        clsn::draw::TextHorizontalAlignment m_horizontal_alignment;
        clsn::draw::TextVerticalAlignment m_vertical_alignment;

    public:
        label();

        auto get_horizontal_alignment() const -> clsn::draw::TextHorizontalAlignment;
        auto get_vertical_alignment() const -> clsn::draw::TextVerticalAlignment;

        void set_horizontal_alignment(clsn::draw::TextHorizontalAlignment horizontal_alignment);
        void set_vertical_alignment(clsn::draw::TextVerticalAlignment vertical_alignment);

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;

    };
}