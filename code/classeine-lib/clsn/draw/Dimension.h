// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <string>

namespace clsn::draw
{
    /// @brief Class representing 2D dimensions with width and height.
    class Dimension final
    {
        int m_width; ///< Width of the Dimension.
        int m_height; ///< Height of the Dimension.

    public:
        /// @brief Default constructor initializing dimensions to zero.
        Dimension();

        /// @brief Constructor initializing dimensions with specific width and height values.
        /// @param width Width of the Dimension.
        /// @param height Height of the Dimension.
        Dimension(int width, int height);

        /// @brief Gets the width of the Dimension.
        /// @return Integer representing the width.
        [[nodiscard]] auto getWidth() const noexcept -> int;

        /// @brief Gets the height of the Dimension.
        /// @return Integer representing the height.
        [[nodiscard]] auto getHeight() const noexcept -> int;

        /// @brief Equality operator to compare two Dimension objects.
        /// @param other The Dimension to compare with.
        /// @return True if dimensions are equal, false otherwise.
        auto operator==(const Dimension& other) const noexcept -> bool;

        /// @brief Addition operator to add two Dimension objects.
        /// @param other The Dimension to add.
        /// @return A new Dimension object representing the sum of both dimensions.
        auto operator+(const Dimension& other) const noexcept -> Dimension;

        /// @brief Converts the Dimension to a string representation.
        /// @return A std::string representing the Dimension.
        [[nodiscard]] auto toString() const -> std::string;
    };
}