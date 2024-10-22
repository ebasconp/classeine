// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/PaintableControl.h>

namespace clsn::ui
{
    /// @brief A base class representing a content pane with Layout and
    /// Event handling capabilities.
    ///
    /// This class provides methods for managing the Layout and handling various
    /// events for a pane that contains content.
    class ContentPane : public PaintableControl
    {
    protected:
        /// @brief Constructs a ContentPane with the given section name.
        ///
        /// @param sectionName The name of the section.
        explicit ContentPane(std::string_view sectionName);

    public:
        /// @brief Perform Layout arrangement for the content pane.
        void doLayout() override;

        /// @brief Invalidate the content pane, marking it as needing a refresh.
        void invalidate() const noexcept override;

        /// @brief Validate the content pane, confirming it no longer needs a refresh.
        void validate() const noexcept override;

        /// @brief Check if the content pane is invalidated.
        ///
        /// @return true if the content pane is invalidated, false otherwise.
        auto isInvalidated() const noexcept -> bool override;

        /// @brief Get the Control at a specific position.
        ///
        /// @param Point The position to check for a Control.
        /// @return An optional reference to the Control at the specified position.
        auto getControlByPosition(const clsn::draw::Point& Point) const
            -> core::constOptionalReference<Control> override;

    protected:
        /// @brief Process a mouse click Event.
        ///
        /// @param e The mouse click Event to process.
        void processMouseClickEvent(events::MouseClickEvent& e) override;

        /// @brief Process a mouse moved Event.
        ///
        /// @param e The mouse moved Event to process.
        void processMouseMovedEvent(events::MouseMovedEvent& e) override;

        /// @brief Create the default renderer for the content pane.
        ///
        /// @return A unique pointer to the default renderer.
        auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override;

    private:
        /// @brief Initialize the events for the content pane.
        void initContentPaneEvents();

    public:
        /// @brief Get the actual inner Control contained within the content pane.
        ///
        /// This is a pure virtual function that must be implemented by derived classes.
        ///
        /// @return An optional reference to the actual inner Control.
        virtual auto getActualInnerControl() -> core::OptionalReference<Control> = 0;

        /// @brief Get the actual inner Control contained within the content pane (const version).
        ///
        /// This is a pure virtual function that must be implemented by derived classes.
        ///
        /// @return An optional reference to the actual inner Control.
        virtual auto getActualInnerControl() const -> core::constOptionalReference<Control> = 0;
    };
}