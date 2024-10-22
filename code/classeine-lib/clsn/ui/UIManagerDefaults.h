// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Configuration.h>

#include <clsn/draw/Forward.h>

#include <memory>

namespace clsn::ui
{
    using UIManagerDefaults = clsn::core::Configuration<clsn::draw::Color,
                                                        clsn::draw::Dimension,
                                                        clsn::draw::Font>;
}