// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/Forward.h>
#include <clsn/draw/Point.h>

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
    draw::Point m_position;

  public:
    /// @brief Constructs a new xy_layout_constraint with the specified position.
    ///
    /// @param position The position where the UI control will be placed.
    explicit xy_layout_constraint(const draw::Point& position);

    /// @brief Gets the current position of the constraint.
    ///
    /// @return const draw::Point& The position of the control in the layout.
    [[nodiscard]] auto getPosition() const -> const draw::Point&;

    /// @brief Sets a new position for the constraint.
    ///
    /// @param position The new position for the control in the layout.
    void set_position(const draw::Point& position);
  };
}