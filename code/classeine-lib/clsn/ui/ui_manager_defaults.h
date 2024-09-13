// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/core/configuration.h"

#include "clsn/draw/color.h"
#include "clsn/draw/dimension.h"
#include "clsn/draw/font.h"

#include <memory>

namespace clsn::ui
{
    using ui_manager_defaults = clsn::core::configuration<clsn::draw::color,
                                                        clsn::draw::dimension,
                                                        clsn::draw::font>;
}