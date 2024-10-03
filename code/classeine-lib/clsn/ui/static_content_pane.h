// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/content_pane.h>
#include <memory>

namespace clsn::ui
{
    /// @brief A class representing a static content pane that holds a control of a specific type.
    ///
    /// This class provides methods to get the inner control and manages a control of a specific type.
    ///
    /// @tparam ControlType The type of the control that the pane will hold.
    template <typename ControlType>
    class static_content_pane : public content_pane
    {
        ControlType m_inner_control; ///< The control of type ControlType.

    public:
        /// @brief Constructs a static_content_pane with an optional section name.
        ///
        /// @param section_name The name of the section (default is an empty string).
        static_content_pane(std::string_view section_name = "") : content_pane{section_name}
        {
        }

        /// @brief Gets a non-const reference to the inner control.
        ///
        /// @return A reference to the inner control.
        auto get_inner_control() -> ControlType&
        {
            return m_inner_control;
        }

        /// @brief Gets a const reference to the inner control.
        ///
        /// @return A const reference to the inner control.
        auto get_inner_control() const -> const ControlType&
        {
            return m_inner_control;
        }

        /// @brief Gets the actual inner control as a core::optional_reference.
        ///
        /// This method overrides the get_actual_inner_control method from the base class.
        ///
        /// @return A core::optional_reference to the inner control.
        auto get_actual_inner_control() -> core::optional_reference<control> override
        {
            return m_inner_control;
        }

        /// @brief Gets the actual inner control as a core::const_optional_reference.
        ///
        /// This method overrides the get_actual_inner_control method from the base class.
        ///
        /// @return A core::const_optional_reference to the inner control.
        auto get_actual_inner_control() const -> core::const_optional_reference<control> override
        {
            return m_inner_control;
        }
    };
}