// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/forward.h>
#include <clsn/draw/point.h>

namespace clsn::ui::layouts
{
  /// @brief Represents the constraints for placing UI controls arbitrarily
  /// within an xy_layout.
  ///
  /// This class defines the position constraint, which is necessary to
  /// position UI elements in specific locations within an xy_layout.
  /// Each control within the layout can have a unique constraint,
  /// specifying its position inside its container.
  class xy_layout_constraint final
  {
    draw::point m_position;

  public:
    /// @brief Constructs a new xy_layout_constraint with the specified position.
    ///
    /// @param position The position where the UI control will be placed.
    explicit xy_layout_constraint(const draw::point& position);

    /// @brief Gets the current position of the constraint.
    ///
    /// @return const draw::point& The position of the control in the layout.
    [[nodiscard]] auto get_position() const -> const draw::point&;

    /// @brief Sets a new position for the constraint.
    ///
    /// @param position The new position for the control in the layout.
    void set_position(const draw::point& position);
  };
}