// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/CaptionableControl.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(CaptionableControl, Caption, std::string)

    CaptionableControl::CaptionableControl(std::string_view sectionName)
    : PaintableControl{sectionName}
    {
        initCaptionableControlEvents();
    }

    void CaptionableControl::initCaptionableControlEvents()
    {
        auto invalidate_proc = [this](auto&) { invalidate(); };

        addCaptionChangedListener(invalidate_proc);
    }

    auto CaptionableControl::toString() const -> std::string
    {
        using namespace clsn::core;
        return Strings::format(
            "{} [{}]", PaintableControl::toString(), m_propertyCaption.get());
    }
}