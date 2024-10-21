// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <functional>

namespace clsn::core
{
    template <typename EventType>
    using EventListener = std::function<void(EventType&)>;
}
