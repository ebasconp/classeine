// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/impl/sdl2/main_window_sdl2_impl.h>

namespace clsn::ui::impl
{
    template <typename WindowType>
    using main_window_impl = clsn::ui::impl::sdl2::main_window_sdl2_impl<WindowType>;
}