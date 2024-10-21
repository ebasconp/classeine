// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/graphics.h>

#include <clsn/ui/events/control_resized_event.h>
#include <clsn/ui/events/mouse_click_event.h>
#include <clsn/ui/events/mouse_moved_event.h>

#include <clsn/draw/dimension.h>

#include <clsn/core/Entity.h>
#include <clsn/core/EntityWrapper.h>
#include <clsn/core/EventListenerList.h>
#include <clsn/core/OptionalReference.h>
#include <clsn/core/Property.h>

#include <functional>
#include <memory>
#include <optional>
#include <string_view>

namespace clsn::ui
{
    class renderer_base;
    class window;

    /// Base class for all controls (referred to as UI widgets) in *classeine*.
    ///
    /// This class provides basic methods for handling events and
    /// offers the infrastructure for managing rendering and layouts.
    class control : public clsn::core::Entity
    {
        clsn::core::EventListenerList<clsn::ui::events::control_resized_event> m_control_resized_listeners;
        clsn::core::EventListenerList<clsn::ui::events::mouse_click_event> m_mouse_click_listeners;
        clsn::core::EventListenerList<clsn::ui::events::mouse_moved_event> m_mouse_moved_listeners;

        std::shared_ptr<clsn::core::Entity> m_tag;
        mutable std::unique_ptr<renderer_base> m_renderer;

        std::string m_default_section_name;

        mutable bool m_invalidated;

        core::OptionalReference<window>  m_parent_window;
        core::OptionalReference<control> m_parent_control;

    protected:
        /// Constructs a control with a specified section name.
        /// @param sectionName The section name to be used.
        explicit control(std::string_view sectionName);

    public:
        // Rule of five implementations for control
        control(const control&) = delete;
        control(control&&) = delete;

        auto operator=(const control&) -> control& = delete;
        auto operator=(control&&) -> control& = delete;

        /// Destructor for the control.
        ~control() override;

        /// Sets the parent control of this control.
        /// @param parent The parent control.
        virtual void set_parent_control(core::OptionalReference<control> parent);

        /// Gets the parent control of this control.
        /// @return The parent control.
        auto get_parent_control() -> core::OptionalReference<control>;

        /// Gets the parent control of this control (const version).
        /// @return The parent control.
        auto get_parent_control() const -> core::constOptionalReference<control>;

        /// Sets the parent window of this control.
        /// @param parent The parent window.
        virtual void set_parent_window(core::OptionalReference<window> parent);

        /// Gets the parent window of this control.
        /// @return The parent window.
        auto get_parent_window() -> core::OptionalReference<window>;

        /// Gets the parent window of this control (const version).
        /// @return The parent window.
        auto get_parent_window() const -> core::constOptionalReference<window>;

        /// Property for the actual position of the control.
        CLSN_HEADER_PROPERTY(ActualPosition, draw::point, true)

        /// Property for the actual size of the control.
        CLSN_HEADER_PROPERTY(ActualSize, draw::dimension, true)

        /// Boolean Property indicating whether the control is enabled.
        CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(Enabled, true, true)

        /// Boolean Property indicating whether the control is visible.
        CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(Visible, true, true)

        /// Property for the preferred size of the control.
        CLSN_HEADER_PROPERTY(PreferredSize, std::optional<clsn::draw::dimension>, true)

        /// Gets the actual preferred size of the control.
        /// @return The preferred size.
        auto get_actual_preferred_size() const -> const clsn::draw::dimension&;

        /// Gets the actual bounds of the control.
        /// @return The bounds of the control.
        auto get_actual_bounds() const -> clsn::draw::region;

        /// Equality operator.
        /// @param rhs The other control to compare.
        /// @return True if this control is equal to rhs.
        auto operator==(const control& rhs) const -> bool;

        /// Inequality operator.
        /// @param rhs The other control to compare.
        /// @return True if this control is not equal to rhs.
        auto operator!=(const control& rhs) const -> bool;

        /// Adds a mouse click Event listener.
        /// @param Event The Event listener to add.
        void add_mouse_click_listener(clsn::core::EventListener<events::mouse_click_event> Event);

        /// Notifies all registered listeners of a mouse click Event.
        /// @param e The mouse click Event to notify.
        void notify_mouse_click_event(events::mouse_click_event& e);

        /// Adds a mouse moved Event listener.
        /// @param Event The Event listener to add.
        void add_mouse_moved_listener(clsn::core::EventListener<events::mouse_moved_event> Event);

        /// Notifies all registered listeners of a mouse moved Event.
        /// @param e The mouse moved Event to notify.
        void notify_mouse_moved_event(events::mouse_moved_event& e);

        /// Paints the control within a given region.
        /// @param gfx The graphics context.
        /// @param rgn The region to paint.
        void paint(graphics& gfx, const clsn::draw::region& rgn) const;

        /// Gets the default section name for the control.
        /// @return The default section name.
        auto get_default_section_name() const -> std::string_view;

        /// Creates and sets a tag of the specified type with arguments.
        /// @tparam TagType The type of the tag.
        /// @tparam Args The arguments to forward to the tag's constructor.
        /// @param args The arguments.
        ///
        /// A tag is a programmer-defined element that is stored inside the control.
        /// It can be used to provide additional metadata or detailed information specific to the application.
        template <typename TagType, typename... Args>
        void make_tag(Args&... args)
        {
            m_tag = std::make_unique<clsn::core::EntityWrapper<TagType>>(
                std::forward<Args>(args)...);
        }

        /// Gets a tag of the specified type or a default value if the tag does not exist.
        /// @tparam TagType The type of the tag.
        /// @param defValue The default value.
        /// @return The tag or the default value.
        template <typename TagType>
        auto get_tag_or_default(const TagType& defValue) const -> const TagType&
        {
            if (m_tag == nullptr)
                return defValue;

            return static_cast<clsn::core::EntityWrapper<TagType>&>(*m_tag).get();
        }

        /// Sets the renderer for the control.
        /// @param renderer The renderer to set.
        void set_renderer(std::unique_ptr<renderer_base>&& renderer) const;

        /// Gets the renderer for the control (const version).
        /// @return The renderer.
        auto get_renderer() const -> const renderer_base&;

        /// Gets the renderer for the control.
        /// @return The renderer.
        auto get_renderer() -> renderer_base&;

        /// Performs the control's layout.
        virtual void do_layout();

        /// Invalidates the control.
        virtual void invalidate() const noexcept;

        /// Validates the control.
        virtual void validate() const noexcept;

        /// Checks if the control is invalidated.
        /// @return True if the control is invalidated.
        virtual auto is_invalidated() const noexcept -> bool;

        /// Releases the mouse capture for the control.
        virtual void release_mouse();

        /// Checks if the control is hovered by the mouse.
        /// @return True if the control is hovered.
        auto is_hovered() const -> bool;

        /// Checks if the control contains a point.
        /// @param point The point to check.
        /// @return True if the point is within the control's bounds.
        auto contains_point(const clsn::draw::point& point) const -> bool;

        /// Gets the control at a specific position.
        /// @param point The position to check.
        /// @return The control at the position, or a null reference if none exists.
        virtual auto get_control_by_position(const clsn::draw::point& point) const ->
                core::constOptionalReference<control>;

        /// Invokes a procedure in the context of the parent window.
        /// @tparam Proc The type of the procedure.
        /// @param proc The procedure to invoke.
        template <typename Proc>
        void invoke_in_parent_window(Proc proc)
        {
            m_parent_window.safeInvoke(proc);
        }

        /// Loads the default settings for the control.
        virtual void load_defaults();

        /// Converts the control to a string representation.
        /// @return The string representation.
        auto toString() const -> std::string override;

    protected:
        /// Processes a mouse click Event for the control.
        /// @param e The mouse click Event.
        virtual void process_mouse_click_event(events::mouse_click_event& e);

        /// Processes a mouse moved Event for the control.
        /// @param e The mouse moved Event.
        virtual void process_mouse_moved_event(events::mouse_moved_event& e);

    private:
        /// Creates a default renderer for the control.
        /// @return The default renderer.
        [[nodiscard]] virtual auto make_default_renderer() const -> std::unique_ptr<renderer_base>;

        /// Initializes control events such as mouse and keyboard events.
        void init_control_events();

    public:
        /// Creates and returns a shared pointer to a control of the specified type.
        /// @tparam T The type of control.
        /// @tparam Args The arguments to forward to the control's constructor.
        /// @param args The arguments.
        /// @return A shared pointer to the control.
        template <typename T, typename... Args>
        static auto make(Args&&... args) -> std::shared_ptr<T>
        {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
    };

}