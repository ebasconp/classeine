// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "Label.h"

#include "renderers/LabelRenderer.h"

namespace clsn::ui
{
    Label::Label()
    : CaptionableControl{"Label"}
    , m_horizontalAlignment{clsn::draw::TextHorizontalAlignment::left}
    , m_verticalAlignment{clsn::draw::TextVerticalAlignment::middle}
    {
    }

    auto Label::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::LabelRenderer>();
    }

    auto Label::getHorizontalAlignment() const -> clsn::draw::TextHorizontalAlignment
    {
        return m_horizontalAlignment;
    }

    auto Label::getVerticalAlignment() const -> clsn::draw::TextVerticalAlignment
    {
        return m_verticalAlignment;
    }

    void Label::setHorizontalAlignment(clsn::draw::TextHorizontalAlignment horizontal_alignment)
    {
        m_horizontalAlignment = horizontal_alignment;
    }

    void Label::setVerticalAlignment(clsn::draw::TextVerticalAlignment vertical_alignment)
    {
        m_verticalAlignment = vertical_alignment;
    }
}