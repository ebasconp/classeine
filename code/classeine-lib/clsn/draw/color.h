/// @file
/// @brief Defines the color class for the Classeine project, providing color manipulation utilities.
/// This file belongs to the Classeine project.
/// @details This class encapsulates color properties and provides methods to manipulate
///          and retrieve color information. Various constructors are offered to initialize
///          the color in different ways.
/// @license BSD-3-Clause
/// @copyright © 2024 Ernesto Bascón Pantoja

#pragma once

namespace clsn::draw
{
    /// @brief Class representing a color with red, green, blue, and alpha components.
    class color final
    {
        unsigned char r; ///< Red component of the color.
        unsigned char g; ///< Green component of the color.
        unsigned char b; ///< Blue component of the color.
        unsigned char a; ///< Alpha (transparency) component of the color, where 255 is fully opaque.

    public:
        /// @brief Default constructor initializing the color to black (rgba: 0, 0, 0, 255).
        color();

        /// @brief Constructor initializing the color with red, green, and blue values. Alpha is set to 255.
        /// @param r Red component.
        /// @param g Green component.
        /// @param b Blue component.
        color(int r, int g, int b);

        /// @brief Constructor initializing the color with red, green, blue, and alpha values.
        /// @param r Red component.
        /// @param g Green component.
        /// @param b Blue component.
        /// @param a Alpha component.
        color(int r, int g, int b, int a);

        /// @brief Constructor initializing the color with a hexadecimal code.
        /// @param hexaCode Hexadecimal value representing the color.
        explicit color(int hexaCode);

        /// @brief Gets the color as an integer in ARGB format.
        /// @return Integer representing the ARGB color.
        [[nodiscard]] auto get_color() const noexcept -> int;

        /// @brief Gets the red component of the color.
        /// @return Integer representing the red component.
        [[nodiscard]] auto get_red() const noexcept -> int;

        /// @brief Gets the green component of the color.
        /// @return Integer representing the green component.
        [[nodiscard]] auto get_green() const noexcept -> int;

        /// @brief Gets the blue component of the color.
        /// @return Integer representing the blue component.
        [[nodiscard]] auto get_blue() const noexcept -> int;

        /// @brief Gets the alpha component of the color.
        /// @return Integer representing the alpha component.
        [[nodiscard]] auto get_alpha() const noexcept -> int;

        /// @brief Equality operator to compare two color objects.
        /// @param other The color to compare with.
        /// @return True if colors are equal, false otherwise.
        auto operator==(const color& other) const noexcept -> bool;

        /// @brief Converts the color to its grayscale equivalent.
        /// @return A new color object representing the grayscale color.
        [[nodiscard]] auto to_gray() const noexcept -> color;

        /// @brief Converts the color to grayscale if the specified condition is true.
        /// @details This method helps simplify color decision logic by embedding the condition check
        ///          and the conversion in a single method. If the condition is true, the color is converted
        ///          to its grayscale equivalent.
        /// @param condition Boolean condition to trigger the grayscale conversion.
        /// @return A new color object in grayscale if condition is true, otherwise the original color.
        [[nodiscard]] auto to_gray_if(bool condition) const noexcept -> color;
    };
}