// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/core/Configuration.h"

#include "clsn/draw/forward.h"

#include <memory>

namespace clsn::ui
{
    using ui_manager_defaults = clsn::core::Configuration<clsn::draw::color,
                                                        clsn::draw::dimension,
                                                        clsn::draw::font>;
}