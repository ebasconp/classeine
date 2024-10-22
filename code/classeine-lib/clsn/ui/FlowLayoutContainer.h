// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "LayoutContainer.h"

#include "layouts/FlowLayout.h"

namespace clsn::ui
{
    class FlowLayoutContainer : public LayoutContainer<layouts::FlowLayout>
    {
    public:
        FlowLayoutContainer();

    protected:
        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;
    };
}
