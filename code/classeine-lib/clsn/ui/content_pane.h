// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/paintable_control.h>

namespace clsn::ui
{
    /// @brief A base class representing a content pane with layout and
    /// event handling capabilities.
    ///
    /// This class provides methods for managing the layout and handling various
    /// events for a pane that contains content.
    class content_pane : public paintable_control
    {
    protected:
        /// @brief Constructs a content_pane with the given section name.
        ///
        /// @param section_name The name of the section.
        explicit content_pane(std::string_view section_name);

    public:
        /// @brief Perform layout arrangement for the content pane.
        void do_layout() override;

        /// @brief Invalidate the content pane, marking it as needing a refresh.
        void invalidate() const noexcept override;

        /// @brief Validate the content pane, confirming it no longer needs a refresh.
        void validate() const noexcept override;

        /// @brief Check if the content pane is invalidated.
        ///
        /// @return true if the content pane is invalidated, false otherwise.
        auto is_invalidated() const noexcept -> bool override;

        /// @brief Get the control at a specific position.
        ///
        /// @param point The position to check for a control.
        /// @return An optional reference to the control at the specified position.
        auto get_control_by_position(const clsn::draw::point& point) const
            -> core::const_optional_reference<control> override;

    protected:
        /// @brief Process a mouse click event.
        ///
        /// @param e The mouse click event to process.
        void process_mouse_click_event(events::mouse_click_event& e) override;

        /// @brief Process a mouse moved event.
        ///
        /// @param e The mouse moved event to process.
        void process_mouse_moved_event(events::mouse_moved_event& e) override;

        /// @brief Create the default renderer for the content pane.
        ///
        /// @return A unique pointer to the default renderer.
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;

    private:
        /// @brief Initialize the events for the content pane.
        void init_content_pane_events();

    public:
        /// @brief Get the actual inner control contained within the content pane.
        ///
        /// This is a pure virtual function that must be implemented by derived classes.
        ///
        /// @return An optional reference to the actual inner control.
        virtual auto get_actual_inner_control() -> core::optional_reference<control> = 0;

        /// @brief Get the actual inner control contained within the content pane (const version).
        ///
        /// This is a pure virtual function that must be implemented by derived classes.
        ///
        /// @return An optional reference to the actual inner control.
        virtual auto get_actual_inner_control() const -> core::const_optional_reference<control> = 0;
    };
}