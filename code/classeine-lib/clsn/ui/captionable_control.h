// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/paintable_control.h>

namespace clsn::ui
{
    /// @class captionable_control
    /// @brief This class represents a UI control that has a caption property.
    ///
    /// The `captionable_control` class inherits from `clsn::ui::paintable_control`
    /// and adds the capability to manage caption text. It exposes a `caption`
    /// property which can be used to get or set the text associated with the control.
    class captionable_control : public clsn::ui::paintable_control
    {
    public:
        /// @brief Constructs a captionable_control instance with the specified name.
        ///
        /// @param name The name of the control.
        explicit captionable_control(std::string_view name);

        /// @brief The caption property of the control.
        ///
        /// This property allows getting or setting the caption text of the control.
        CLSN_HEADER_PROPERTY(caption, std::string, true)

        /// @brief Converts the captionable control to a string representation.
        ///
        /// @return A string representing the captionable control.
        auto to_string() const -> std::string override;

    private:
        /// @brief Initializes the events associated with the captionable control.
        ///
        /// This method sets up any necessary event handlers or configurations
        /// specific to captionable controls.
        void init_captionable_control_events();
    };
}