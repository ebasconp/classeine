// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <string>

namespace clsn::draw
{
    /// @brief Class representing 2D dimensions with width and height.
    class dimension final
    {
        int m_width; ///< Width of the dimension.
        int m_height; ///< Height of the dimension.

    public:
        /// @brief Default constructor initializing dimensions to zero.
        dimension();

        /// @brief Constructor initializing dimensions with specific width and height values.
        /// @param width Width of the dimension.
        /// @param height Height of the dimension.
        dimension(int width, int height);

        /// @brief Gets the width of the dimension.
        /// @return Integer representing the width.
        [[nodiscard]] auto get_width() const noexcept -> int;

        /// @brief Gets the height of the dimension.
        /// @return Integer representing the height.
        [[nodiscard]] auto get_height() const noexcept -> int;

        /// @brief Equality operator to compare two dimension objects.
        /// @param other The dimension to compare with.
        /// @return True if dimensions are equal, false otherwise.
        auto operator==(const dimension& other) const noexcept -> bool;

        /// @brief Addition operator to add two dimension objects.
        /// @param other The dimension to add.
        /// @return A new dimension object representing the sum of both dimensions.
        auto operator+(const dimension& other) const noexcept -> dimension;

        /// @brief Converts the dimension to a string representation.
        /// @return A std::string representing the dimension.
        [[nodiscard]] auto toString() const -> std::string;
    };
}