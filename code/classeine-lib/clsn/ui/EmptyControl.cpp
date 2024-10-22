// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "EmptyControl.h"

#include "renderers/EmptyControlRenderer.h"

namespace clsn::ui
{
    EmptyControl::EmptyControl()
    : Control{""}
    {
    }

    auto EmptyControl::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::EmptyControlRenderer>();
    }
}