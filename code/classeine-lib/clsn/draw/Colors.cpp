// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/draw/Colors.h>

namespace clsn::draw
{
    auto Colors::makeRed() -> Color         { return { 255, 0, 0 }; }
    auto Colors::makeGreen() -> Color       { return { 0, 255, 0 }; }
    auto Colors::makeBlue() -> Color        { return { 0, 0, 255 }; }
    auto Colors::makeWhite() -> Color       { return { 255, 255, 255 }; }
    auto Colors::makeBlack() -> Color       { return { 0, 0, 0 }; }
    auto Colors::makeYellow() -> Color      { return { 255, 255, 0 }; }
    auto Colors::makePurple() -> Color      { return { 255, 0, 255 }; }
    auto Colors::makeCyan() -> Color        { return { 0, 255, 255 }; }
}