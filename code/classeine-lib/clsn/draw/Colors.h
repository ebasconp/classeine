// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/Color.h>

#include <clsn/core/NonInstantiable.h>

namespace clsn::draw
{
    class Colors : public core::NonInstantiable
    {
    public:
        [[nodiscard]] static auto makeRed() -> Color;
        [[nodiscard]] static auto makeGreen() -> Color;
        [[nodiscard]] static auto makeBlue() -> Color;
        [[nodiscard]] static auto makeWhite() -> Color;
        [[nodiscard]] static auto makeBlack() -> Color;
        [[nodiscard]] static auto makeYellow() -> Color;
        [[nodiscard]] static auto makePurple() -> Color;
        [[nodiscard]] static auto makeCyan() -> Color;
    };
}