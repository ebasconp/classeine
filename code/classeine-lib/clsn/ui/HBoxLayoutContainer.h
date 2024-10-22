// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/LayoutContainer.h>

#include <clsn/ui/layouts/HBoxLayout.h>

namespace clsn::ui
{
    class HBoxLayoutContainer : public LayoutContainer<layouts::HBoxLayout>
    {
    public:
        HBoxLayoutContainer();

    protected:
        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;
    };
}
