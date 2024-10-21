// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/content_pane.h>
#include <clsn/draw/forward.h>
#include <memory>

namespace clsn::ui
{
    /// @brief A class representing a dynamic content pane that can hold a control.
    ///
    /// This class provides methods to set and get an inner control, dynamically
    // managing the content of the pane.
    class dynamic_content_pane : public content_pane
    {
        std::shared_ptr<control> m_inner_control; ///< A shared pointer to the inner control.

    public:
        /// @brief Constructs a dynamic_content_pane.
        dynamic_content_pane();

        /// @brief Gets a non-const reference to the inner control.
        ///
        /// @return A reference to a shared pointer holding the inner control.
        auto get_inner_control() -> std::shared_ptr<control>&;

        /// @brief Gets a const reference to the inner control.
        ///
        /// @return A const reference to a shared pointer holding the inner control.
        auto get_inner_control() const -> const std::shared_ptr<control>&;

        /// @brief Sets the inner control.
        ///
        /// @param ctrl The shared pointer holding the control to set as the inner control.
        void set_inner_control(const std::shared_ptr<control>& ctrl);

    public:
        /// @brief Gets the actual inner control as a core::OptionalReference.
        ///
        /// This method overrides the get_actual_inner_control method from the base class.
        ///
        /// @return A core::OptionalReference to the inner control.
        auto get_actual_inner_control() -> core::OptionalReference<control> override;

        /// @brief Gets the actual inner control as a core::constOptionalReference.
        ///
        /// This method overrides the get_actual_inner_control method from the base class.
        ///
        /// @return A core::constOptionalReference to the inner control.
        auto get_actual_inner_control() const -> core::constOptionalReference<control> override;
    };
}