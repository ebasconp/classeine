#pragma once

#include "sdl2/main_window_sdl2_impl.h"

namespace clsn::ui::impl
{
    template <typename WindowType>
    using main_window_impl = clsn::ui::impl::sdl2::main_window_sdl2_impl<WindowType>;
}