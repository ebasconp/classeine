// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "colors.h"

namespace clsn::draw::colors
{
    auto make_red() -> color         { return { 255, 0, 0 }; }
    auto make_green() -> color       { return { 0, 255, 0 }; }
    auto make_blue() -> color        { return { 0, 0, 255 }; }
    auto make_white() -> color       { return { 255, 255, 255 }; }
    auto make_black() -> color       { return { 0, 0, 0 }; }
    auto make_yellow() -> color      { return { 255, 255, 0 }; }
    auto make_purple() -> color      { return { 255, 0, 255 }; }
    auto make_cyan() -> color        { return { 0, 255, 255 }; }
}