// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/LayoutContainer.h>

#include <clsn/ui/layouts/XYLayout.h>

namespace clsn::ui
{
    class XYLayoutContainer : public LayoutContainer<layouts::XYLayout>
    {
    public:
        XYLayoutContainer();

    protected:
        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;
    };
}
