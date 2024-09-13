// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "colors.h"

namespace clsn::draw::colors
{
    auto make_red() -> clsn::draw::color         { return { 255, 0, 0 }; }
    auto make_green() -> clsn::draw::color       { return { 0, 255, 0 }; }
    auto make_blue() -> clsn::draw::color        { return { 0, 0, 255 }; }
    auto make_white() -> clsn::draw::color       { return { 255, 255, 255 }; }
    auto make_black() -> clsn::draw::color       { return { 0, 0, 0 }; }
    auto make_yellow() -> clsn::draw::color      { return { 255, 255, 0 }; }
    auto make_purple() -> clsn::draw::color      { return { 255, 0, 255 }; }
    auto make_cyan() -> clsn::draw::color        { return { 0, 255, 255 }; }
}