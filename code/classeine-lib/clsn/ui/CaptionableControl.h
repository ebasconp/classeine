// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/PaintableControl.h>

namespace clsn::ui
{
    /// @class CaptionableControl
    /// @brief This class represents a UI Control that has a caption Property.
    ///
    /// The `CaptionableControl` class inherits from `clsn::ui::PaintableControl`
    /// and adds the capability to manage caption text. It exposes a `caption`
    /// Property which can be used to get or set the text associated with the Control.
    class CaptionableControl : public clsn::ui::PaintableControl
    {
    public:
        /// @brief Constructs a CaptionableControl instance with the specified name.
        ///
        /// @param name The name of the Control.
        explicit CaptionableControl(std::string_view name);

        /// @brief The caption Property of the Control.
        ///
        /// This Property allows getting or setting the caption text of the Control.
        CLSN_HEADER_PROPERTY(Caption, std::string, true)

        /// @brief Converts the captionable Control to a string representation.
        ///
        /// @return A string representing the captionable Control.
        auto toString() const -> std::string override;

    private:
        /// @brief Initializes the events associated with the captionable Control.
        ///
        /// This method sets up any necessary Event handlers or configurations
        /// specific to captionable controls.
        void initCaptionableControlEvents();
    };
}