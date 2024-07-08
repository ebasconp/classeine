#pragma once

#include "Color.h"

namespace clsn::draw::Colors
{
    [[nodiscard]] auto makeRed() -> clsn::draw::Color;
    [[nodiscard]] auto makeGreen() -> clsn::draw::Color;
    [[nodiscard]] auto makeBlue() -> clsn::draw::Color;
    [[nodiscard]] auto makeWhite() -> clsn::draw::Color;
    [[nodiscard]] auto makeBlack() -> clsn::draw::Color;
    [[nodiscard]] auto makeYellow() -> clsn::draw::Color;
    [[nodiscard]] auto makePurple() -> clsn::draw::Color;
    [[nodiscard]] auto makeCyan() -> clsn::draw::Color;
}