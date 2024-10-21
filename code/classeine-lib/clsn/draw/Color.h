/// @file
/// @brief Defines the Color class for the Classeine project, providing Color manipulation utilities.
/// This file belongs to the Classeine project.
/// @details This class encapsulates Color properties and provides methods to manipulate
///          and retrieve Color information. Various constructors are offered to initialize
///          the Color in different ways.
/// @license BSD-3-Clause
/// @copyright © 2024 Ernesto Bascón Pantoja

#pragma once

namespace clsn::draw
{
    /// @brief Class representing a Color with red, green, blue, and alpha components.
    class Color final
    {
        unsigned char r; ///< Red component of the Color.
        unsigned char g; ///< Green component of the Color.
        unsigned char b; ///< Blue component of the Color.
        unsigned char a; ///< Alpha (transparency) component of the Color, where 255 is fully opaque.

    public:
        /// @brief Default constructor initializing the Color to black (rgba: 0, 0, 0, 255).
        Color();

        /// @brief Constructor initializing the Color with red, green, and blue values. Alpha is set to 255.
        /// @param r Red component.
        /// @param g Green component.
        /// @param b Blue component.
        Color(int r, int g, int b);

        /// @brief Constructor initializing the Color with red, green, blue, and alpha values.
        /// @param r Red component.
        /// @param g Green component.
        /// @param b Blue component.
        /// @param a Alpha component.
        Color(int r, int g, int b, int a);

        /// @brief Constructor initializing the Color with a hexadecimal code.
        /// @param hexaCode Hexadecimal value representing the Color.
        explicit Color(int hexaCode);

        /// @brief Gets the Color as an integer in ARGB format.
        /// @return Integer representing the ARGB Color.
        [[nodiscard]] auto getColor() const noexcept -> int;

        /// @brief Gets the red component of the Color.
        /// @return Integer representing the red component.
        [[nodiscard]] auto getRed() const noexcept -> int;

        /// @brief Gets the green component of the Color.
        /// @return Integer representing the green component.
        [[nodiscard]] auto getGreen() const noexcept -> int;

        /// @brief Gets the blue component of the Color.
        /// @return Integer representing the blue component.
        [[nodiscard]] auto getBlue() const noexcept -> int;

        /// @brief Gets the alpha component of the Color.
        /// @return Integer representing the alpha component.
        [[nodiscard]] auto getAlpha() const noexcept -> int;

        /// @brief Equality operator to compare two Color objects.
        /// @param other The Color to compare with.
        /// @return True if Colors are equal, false otherwise.
        auto operator==(const Color& other) const noexcept -> bool;

        /// @brief Converts the Color to its grayscale equivalent.
        /// @return A new Color object representing the grayscale Color.
        [[nodiscard]] auto toGray() const noexcept -> Color;

        /// @brief Converts the Color to grayscale if the specified condition is true.
        /// @details This method helps simplify Color decision logic by embedding the condition check
        ///          and the conversion in a single method. If the condition is true, the Color is converted
        ///          to its grayscale equivalent.
        /// @param condition Boolean condition to trigger the grayscale conversion.
        /// @return A new Color object in grayscale if condition is true, otherwise the original Color.
        [[nodiscard]] auto toGrayIf(bool condition) const noexcept -> Color;
    };
}