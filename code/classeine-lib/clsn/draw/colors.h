#pragma once

#include "color.h"

namespace clsn::draw::colors
{
    [[nodiscard]] auto make_red() -> clsn::draw::color;
    [[nodiscard]] auto make_green() -> clsn::draw::color;
    [[nodiscard]] auto make_blue() -> clsn::draw::color;
    [[nodiscard]] auto make_white() -> clsn::draw::color;
    [[nodiscard]] auto make_black() -> clsn::draw::color;
    [[nodiscard]] auto make_yellow() -> clsn::draw::color;
    [[nodiscard]] auto make_purple() -> clsn::draw::color;
    [[nodiscard]] auto make_cyan() -> clsn::draw::color;
}