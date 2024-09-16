// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "color.h"

namespace clsn::draw::colors
{
    [[nodiscard]] auto make_red() -> color;
    [[nodiscard]] auto make_green() -> color;
    [[nodiscard]] auto make_blue() -> color;
    [[nodiscard]] auto make_white() -> color;
    [[nodiscard]] auto make_black() -> color;
    [[nodiscard]] auto make_yellow() -> color;
    [[nodiscard]] auto make_purple() -> color;
    [[nodiscard]] auto make_cyan() -> color;
}