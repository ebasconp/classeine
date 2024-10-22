// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/ContentPane.h>
#include <memory>

namespace clsn::ui
{
    /// @brief A class representing a static content pane that holds a Control of a specific type.
    ///
    /// This class provides methods to get the inner Control and manages a Control of a specific type.
    ///
    /// @tparam ControlType The type of the Control that the pane will hold.
    template <typename ControlType>
    class StaticContentPane : public ContentPane
    {
        ControlType m_innerControl; ///< The Control of type ControlType.

    public:
        /// @brief Constructs a StaticContentPane with an optional section name.
        ///
        /// @param sectionName The name of the section (default is an empty string).
        StaticContentPane(std::string_view sectionName = "") : ContentPane{sectionName}
        {
        }

        /// @brief Gets a non-const reference to the inner Control.
        ///
        /// @return A reference to the inner Control.
        auto getInnerControl() -> Control&
        {
            return m_innerControl;
        }

        /// @brief Gets a const reference to the inner Control.
        ///
        /// @return A const reference to the inner Control.
        auto getInnerControl() const -> const Control&
        {
            return m_innerControl;
        }

        /// @brief Gets the actual inner Control as a core::OptionalReference.
        ///
        /// This method overrides the getActualInnerControl method from the base class.
        ///
        /// @return A core::OptionalReference to the inner Control.
        auto getActualInnerControl() -> core::OptionalReference<Control> override
        {
            return m_innerControl;
        }

        /// @brief Gets the actual inner Control as a core::constOptionalReference.
        ///
        /// This method overrides the getActualInnerControl method from the base class.
        ///
        /// @return A core::constOptionalReference to the inner Control.
        auto getActualInnerControl() const -> core::constOptionalReference<Control> override
        {
            return m_innerControl;
        }
    };
}