#include "Colors.h"

namespace clsn::draw::Colors
{
    auto makeRed() -> clsn::draw::Color         { return { 255, 0, 0 }; }
    auto makeGreen() -> clsn::draw::Color       { return { 0, 255, 0 }; }
    auto makeBlue() -> clsn::draw::Color        { return { 0, 0, 255 }; }
    auto makeWhite() -> clsn::draw::Color       { return { 255, 255, 255 }; }
    auto makeBlack() -> clsn::draw::Color       { return { 0, 0, 0 }; }
    auto makeYellow() -> clsn::draw::Color      { return { 255, 255, 0 }; }
    auto makePurple() -> clsn::draw::Color      { return { 255, 0, 255 }; }
    auto makeCyan() -> clsn::draw::Color        { return { 0, 255, 255 }; }
}