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
  /// within an XYLayout.
  ///
  /// This class defines the position constraint, which is necessary to
  /// position UI elements in specific locations within an XYLayout.
  /// Each Control within the Layout can have a unique constraint,
  /// specifying its position inside its Container.
  class XYLayoutConstraint final
  {
    draw::Point m_position;

  public:
    /// @brief Constructs a new XYLayoutConstraint with the specified position.
    ///
    /// @param position The position where the UI Control will be placed.
    explicit XYLayoutConstraint(const draw::Point& position);

    /// @brief Gets the current position of the constraint.
    ///
    /// @return const draw::Point& The position of the Control in the Layout.
    [[nodiscard]] auto getPosition() const -> const draw::Point&;

    /// @brief Sets a new position for the constraint.
    ///
    /// @param position The new position for the Control in the Layout.
    void setPosition(const draw::Point& position);
  };
}