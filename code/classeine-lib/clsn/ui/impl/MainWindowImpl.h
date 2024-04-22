#pragma once

#include "sdl2/MainWindowSdlImpl.h"

namespace clsn::ui::impl
{
    template <typename WindowType>
    using MainWindowImpl = clsn::ui::impl::sdl2::MainWindowSdlImpl<WindowType>;
}