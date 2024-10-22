// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/ContentPane.h>
#include <clsn/draw/Forward.h>

#include <memory>

namespace clsn::ui
{
    /// @brief A class representing a dynamic content pane that can hold a Control.
    ///
    /// This class provides methods to set and get an inner Control, dynamically
    // managing the content of the pane.
    class DynamicContentPane : public ContentPane
    {
        std::shared_ptr<Control> m_innerControl; ///< A shared pointer to the inner Control.

    public:
        /// @brief Constructs a DynamicContentPane.
        DynamicContentPane();

        /// @brief Gets a non-const reference to the inner Control.
        ///
        /// @return A reference to a shared pointer holding the inner Control.
        auto getInnerControl() -> std::shared_ptr<Control>&;

        /// @brief Gets a const reference to the inner Control.
        ///
        /// @return A const reference to a shared pointer holding the inner Control.
        auto getInnerControl() const -> const std::shared_ptr<Control>&;

        /// @brief Sets the inner Control.
        ///
        /// @param ctrl The shared pointer holding the Control to set as the inner Control.
        void setInnerControl(const std::shared_ptr<Control>& ctrl);

    public:
        /// @brief Gets the actual inner Control as a core::OptionalReference.
        ///
        /// This method overrides the getActualInnerControl method from the base class.
        ///
        /// @return A core::OptionalReference to the inner Control.
        auto getActualInnerControl() -> core::OptionalReference<Control> override;

        /// @brief Gets the actual inner Control as a core::constOptionalReference.
        ///
        /// This method overrides the getActualInnerControl method from the base class.
        ///
        /// @return A core::constOptionalReference to the inner Control.
        auto getActualInnerControl() const -> core::constOptionalReference<Control> override;
    };
}