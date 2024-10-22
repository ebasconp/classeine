// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/CaptionableControl.h>

#include <clsn/draw/Forward.h>

namespace clsn::ui
{
    class Label : public CaptionableControl
    {
        clsn::draw::TextHorizontalAlignment m_horizontalAlignment;
        clsn::draw::TextVerticalAlignment m_verticalAlignment;

    public:
        Label();

        auto getHorizontalAlignment() const -> clsn::draw::TextHorizontalAlignment;
        auto getVerticalAlignment() const -> clsn::draw::TextVerticalAlignment;

        void setHorizontalAlignment(clsn::draw::TextHorizontalAlignment horizontal_alignment);
        void setVerticalAlignment(clsn::draw::TextVerticalAlignment vertical_alignment);

    protected:
        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;

    };
}