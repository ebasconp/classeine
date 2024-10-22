// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/impl/sdl2/MainWindowSDL2Impl.h>

namespace clsn::ui::impl
{
    template <typename WindowType>
    using MainWindowImpl = sdl2::MainWindowSDL2Impl<WindowType>;
}