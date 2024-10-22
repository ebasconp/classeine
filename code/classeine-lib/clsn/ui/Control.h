// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/Graphics.h>

#include <clsn/ui/events/ControlResizedEvent.h>
#include <clsn/ui/events/MouseClickEvent.h>
#include <clsn/ui/events/MouseMovedEvent.h>

#include <clsn/draw/Dimension.h>

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
    class IRenderer;
    class Window;

    /// Base class for all controls (referred to as UI widgets) in *classeine*.
    ///
    /// This class provides basic methods for handling events and
    /// offers the infrastructure for managing rendering and layouts.
    class Control : public clsn::core::Entity
    {
        clsn::core::EventListenerList<clsn::ui::events::ControlResizedEvent> m_control_resized_listeners;
        clsn::core::EventListenerList<clsn::ui::events::MouseClickEvent> m_mouse_click_listeners;
        clsn::core::EventListenerList<clsn::ui::events::MouseMovedEvent> m_mouse_moved_listeners;

        std::shared_ptr<clsn::core::Entity> m_tag;
        mutable std::unique_ptr<IRenderer> m_renderer;

        std::string m_defaultSectionName;

        mutable bool m_invalidated;

        core::OptionalReference<Window>  m_parentWindow;
        core::OptionalReference<Control> m_parentControl;

    protected:
        /// Constructs a Control with a specified section name.
        /// @param sectionName The section name to be used.
        explicit Control(std::string_view sectionName);

    public:
        // Rule of five implementations for Control
        Control(const Control&) = delete;
        Control(Control&&) = delete;

        auto operator=(const Control&) -> Control& = delete;
        auto operator=(Control&&) -> Control& = delete;

        /// Destructor for the Control.
        ~Control() override;

        /// Sets the parent Control of this Control.
        /// @param parent The parent Control.
        virtual void setParentControl(core::OptionalReference<Control> parent);

        /// Gets the parent Control of this Control.
        /// @return The parent Control.
        auto getParentControl() -> core::OptionalReference<Control>;

        /// Gets the parent Control of this Control (const version).
        /// @return The parent Control.
        auto getParentControl() const -> core::constOptionalReference<Control>;

        /// Sets the parent Window of this Control.
        /// @param parent The parent Window.
        virtual void setParentWindow(core::OptionalReference<Window> parent);

        /// Gets the parent Window of this Control.
        /// @return The parent Window.
        auto getParentWindow() -> core::OptionalReference<Window>;

        /// Gets the parent Window of this Control (const version).
        /// @return The parent Window.
        auto getParentWindow() const -> core::constOptionalReference<Window>;

        /// Property for the actual position of the Control.
        CLSN_HEADER_PROPERTY(ActualPosition, draw::Point, true)

        /// Property for the actual size of the Control.
        CLSN_HEADER_PROPERTY(ActualSize, draw::Dimension, true)

        /// Boolean Property indicating whether the Control is enabled.
        CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(Enabled, true, true)

        /// Boolean Property indicating whether the Control is visible.
        CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(Visible, true, true)

        /// Property for the preferred size of the Control.
        CLSN_HEADER_PROPERTY(PreferredSize, std::optional<clsn::draw::Dimension>, true)

        /// Gets the actual preferred size of the Control.
        /// @return The preferred size.
        auto getActualPreferredSize() const -> const clsn::draw::Dimension&;

        /// Gets the actual bounds of the Control.
        /// @return The bounds of the Control.
        auto getActualBounds() const -> clsn::draw::Region;

        /// Equality operator.
        /// @param rhs The other Control to compare.
        /// @return True if this Control is equal to rhs.
        auto operator==(const Control& rhs) const -> bool;

        /// Inequality operator.
        /// @param rhs The other Control to compare.
        /// @return True if this Control is not equal to rhs.
        auto operator!=(const Control& rhs) const -> bool;

        /// Adds a mouse click Event listener.
        /// @param Event The Event listener to add.
        void addMouseClickListener(clsn::core::EventListener<events::MouseClickEvent> Event);

        /// Notifies all registered listeners of a mouse click Event.
        /// @param e The mouse click Event to notify.
        void notifyMouseClickEvent(events::MouseClickEvent& e);

        /// Adds a mouse moved Event listener.
        /// @param Event The Event listener to add.
        void addMouseMovedListener(clsn::core::EventListener<events::MouseMovedEvent> Event);

        /// Notifies all registered listeners of a mouse moved Event.
        /// @param e The mouse moved Event to notify.
        void notifyMouseMovedEvent(events::MouseMovedEvent& e);

        /// Paints the Control within a given Region.
        /// @param gfx The Graphics context.
        /// @param rgn The Region to paint.
        void paint(Graphics& gfx, const clsn::draw::Region& rgn) const;

        /// Gets the default section name for the Control.
        /// @return The default section name.
        auto getDefaultSectionName() const -> std::string_view;

        /// Creates and sets a tag of the specified type with arguments.
        /// @tparam TagType The type of the tag.
        /// @tparam Args The arguments to Forward to the tag's constructor.
        /// @param args The arguments.
        ///
        /// A tag is a programmer-defined element that is stored inside the Control.
        /// It can be used to provide additional metadata or detailed information specific to the application.
        template <typename TagType, typename... Args>
        void makeTag(Args&... args)
        {
            m_tag = std::make_unique<clsn::core::EntityWrapper<TagType>>(
                std::forward<Args>(args)...);
        }

        /// Gets a tag of the specified type or a default value if the tag does not exist.
        /// @tparam TagType The type of the tag.
        /// @param defValue The default value.
        /// @return The tag or the default value.
        template <typename TagType>
        auto getTagOrDefault(const TagType& defValue) const -> const TagType&
        {
            if (m_tag == nullptr)
                return defValue;

            return static_cast<clsn::core::EntityWrapper<TagType>&>(*m_tag).get();
        }

        /// Sets the renderer for the Control.
        /// @param renderer The renderer to set.
        void setRenderer(std::unique_ptr<IRenderer>&& renderer) const;

        /// Gets the renderer for the Control (const version).
        /// @return The renderer.
        auto getRenderer() const -> const IRenderer&;

        /// Gets the renderer for the Control.
        /// @return The renderer.
        auto getRenderer() -> IRenderer&;

        /// Performs the Control's Layout.
        virtual void doLayout();

        /// Invalidates the Control.
        virtual void invalidate() const noexcept;

        /// Validates the Control.
        virtual void validate() const noexcept;

        /// Checks if the Control is invalidated.
        /// @return True if the Control is invalidated.
        virtual auto isInvalidated() const noexcept -> bool;

        /// Releases the mouse capture for the Control.
        virtual void releaseMouse();

        /// Checks if the Control is hovered by the mouse.
        /// @return True if the Control is hovered.
        auto isHovered() const -> bool;

        /// Checks if the Control contains a Point.
        /// @param Point The Point to check.
        /// @return True if the Point is within the Control's bounds.
        auto containsPoint(const clsn::draw::Point& Point) const -> bool;

        /// Gets the Control at a specific position.
        /// @param Point The position to check.
        /// @return The Control at the position, or a null reference if none exists.
        virtual auto getControlByPosition(const clsn::draw::Point& Point) const ->
                core::constOptionalReference<Control>;

        /// Invokes a procedure in the context of the parent Window.
        /// @tparam Proc The type of the procedure.
        /// @param proc The procedure to invoke.
        template <typename Proc>
        void invokeInParentWindow(Proc proc)
        {
            m_parentWindow.safeInvoke(proc);
        }

        /// Loads the default settings for the Control.
        virtual void loadDefaults();

        /// Converts the Control to a string representation.
        /// @return The string representation.
        auto toString() const -> std::string override;

    protected:
        /// Processes a mouse click Event for the Control.
        /// @param e The mouse click Event.
        virtual void processMouseClickEvent(events::MouseClickEvent& e);

        /// Processes a mouse moved Event for the Control.
        /// @param e The mouse moved Event.
        virtual void processMouseMovedEvent(events::MouseMovedEvent& e);

    private:
        /// Creates a default renderer for the Control.
        /// @return The default renderer.
        [[nodiscard]] virtual auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer>;

        /// Initializes Control events such as mouse and keyboard events.
        void initControlEvents();

    public:
        /// Creates and returns a shared pointer to a Control of the specified type.
        /// @tparam T The type of Control.
        /// @tparam Args The arguments to Forward to the Control's constructor.
        /// @param args The arguments.
        /// @return A shared pointer to the Control.
        template <typename T, typename... Args>
        static auto make(Args&&... args) -> std::shared_ptr<T>
        {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
    };

}