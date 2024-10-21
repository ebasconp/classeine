// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/captionable_control.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(captionable_control, Caption, std::string)

    captionable_control::captionable_control(std::string_view sectionName)
    : paintable_control{sectionName}
    {
        init_captionable_control_events();
    }

    void captionable_control::init_captionable_control_events()
    {
        auto invalidate_proc = [this](auto&) { invalidate(); };

        addCaptionChangedListener(invalidate_proc);
    }

    auto captionable_control::toString() const -> std::string
    {
        using namespace clsn::core;
        return Strings::format(
            "{} [{}]", paintable_control::toString(), m_propertyCaption.get());
    }
}