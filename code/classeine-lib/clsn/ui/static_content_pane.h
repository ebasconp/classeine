// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/content_pane.h>

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
        /// @brief Constructs a static_content_pane with the provided arguments.
        ///
        /// This constructor initializes a static_content_pane object with the given arguments.
        /// The pane is labeled as "static_content_pane" and the arguments are forwarded to
        /// initialize the inner control component whose type is passed as
        /// argument of the class.
        ///
        /// @tparam Args The types of the arguments to forward to the inner control.
        /// @param args The arguments to forward to the inner control.
        template <typename... Args>
        explicit static_content_pane(Args&&... args)
        : content_pane{"static_content_pane"}
        , m_inner_control{std::forward<Args>(args)...}
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