// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/captionable_control.h>

namespace clsn::ui
{
    captionable_control::captionable_control(std::string_view section_name)
    : paintable_control{section_name}
    {
        init_captionable_control_events();
    }

    void captionable_control::init_captionable_control_events()
    {
        auto invalidate_proc = [this](auto&) { invalidate(); };

        add_text_changed_listener(invalidate_proc);
    }

    auto captionable_control::to_string() const -> std::string
    {
        using namespace clsn::core;
        return strings::format("{} [{}]", paintable_control::to_string(), m_text.get());
    }
}