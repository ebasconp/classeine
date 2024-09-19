// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/color.h>

#include <clsn/core/non_instantiable.h>

namespace clsn::draw
{
    class colors : public core::non_instantiable
    {
    public:
        [[nodiscard]] static auto make_red() -> color;
        [[nodiscard]] static auto make_green() -> color;
        [[nodiscard]] static auto make_blue() -> color;
        [[nodiscard]] static auto make_white() -> color;
        [[nodiscard]] static auto make_black() -> color;
        [[nodiscard]] static auto make_yellow() -> color;
        [[nodiscard]] static auto make_purple() -> color;
        [[nodiscard]] static auto make_cyan() -> color;
    };
}