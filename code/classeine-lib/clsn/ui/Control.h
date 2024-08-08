#pragma once

#include "clsn/ui/Graphics.h"

#include "clsn/ui/events/ControlResizedEvent.h"
#include "clsn/ui/events/MouseClickEvent.h"
#include "clsn/ui/events/MouseMovedEvent.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"

#include "clsn/core/entity_wrapper.h"
#include "clsn/core/event_listener_list.h"
#include "clsn/core/property.h"

#include <functional>
#include <memory>
#include <optional>
#include <string_view>

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;
    using namespace clsn::ui::events;

    class IRenderer;
    class Window;

    class Control : public entity
    {
        event_listener_list<ControlResizedEvent> m_controlResizedListeners;
        event_listener_list<MouseClickEvent> m_mouseClickListeners;
        event_listener_list<MouseMovedEvent> m_mouseMovedListeners;

        std::shared_ptr<entity> m_tag;
        mutable std::shared_ptr<IRenderer> m_renderer;

        std::string m_defaultSectionName;

        mutable bool m_invalidated;

        std::optional<std::reference_wrapper<Window>> m_parentWindow;

    public:
        explicit Control(std::string_view section_name);

        Control(const Control&) = delete;
        Control(Control&&) = delete;

        Control& operator=(const Control&) = delete;
        Control& operator=(Control&&) = delete;

        CLSN_PROPERTY(actual_position, Point, true);
        CLSN_PROPERTY(actual_size, Dimension, true);
        CLSN_PROPERTY(background_color, std::optional<Color>, true);
        CLSN_BOOL_PROPERTY_VAL(enabled, true, true);
        CLSN_PROPERTY(font, std::optional<Font>, true);
        CLSN_PROPERTY(foreground_color, std::optional<Color>, true);
        CLSN_PROPERTY(preferred_size, std::optional<Dimension>, true);
        CLSN_PROPERTY(text, std::string, true);
        CLSN_BOOL_PROPERTY_VAL(visible, true, true);

        auto getActualBackgroundColor() const -> const Color&;
        auto getActualForegroundColor() const -> const Color&;
        auto getActualFont() const -> const Font&;
        auto getActualPreferredSize() const -> const Dimension&;

        auto operator==(const Control&) const -> bool;
        auto operator!=(const Control&) const -> bool;

        void addMouseClickListener(event_listener<MouseClickEvent> event);
        void notifyMouseClickEvent(MouseClickEvent& e);

        void addMouseMovedListener(event_listener<MouseMovedEvent> event);
        void notifyMouseMovedEvent(MouseMovedEvent& e);

        void paint(Graphics& graphics, const Region& region) const;

        auto getDefaultSectionName() const -> std::string_view;

        template <typename TagType, typename... Args>
        void makeTag(Args&... args)
        {
            m_tag = std::make_unique<EntityWrapper<TagType>>(
                std::forward<Args>(args)...);
        }

        template <typename TagType>
        auto getTagOrDefault(const TagType& defValue) const -> const TagType&
        {
            if (m_tag == nullptr)
                return defValue;

            return static_cast<EntityWrapper<TagType>&>(*m_tag).get();
        }

        void setRenderer(const std::shared_ptr<IRenderer>& renderer);

        auto getRenderer() const -> const IRenderer&;
        auto getRenderer() -> IRenderer&;

        virtual void doLayout();

        virtual void invalidate() const noexcept;
        virtual void validate() const noexcept;
        virtual auto isInvalidated() const noexcept -> bool;

        virtual void releaseMouse();

        void setParentWindow(std::optional<std::reference_wrapper<Window>>);
        auto getParentWindow() -> std::optional<std::reference_wrapper<Window>>;
        auto getParentWindow() const -> std::optional<std::reference_wrapper<const Window>>;

        auto isHovered() const -> bool;

        auto containsPoint(const Point& point) const -> bool;
        virtual auto getControlByPosition(const Point& point) const ->
                std::optional<std::reference_wrapper<const Control>>;

        template <typename Proc>
        void invokeInParentWindow(Proc proc)
        {
            if (!m_parentWindow.has_value())
                return;

            proc(m_parentWindow.value().get());
        }

        virtual void loadDefaults();

    protected:
        virtual void processMouseClickEvent(events::MouseClickEvent& e);
        virtual void processMouseMovedEvent(events::MouseMovedEvent& e);

    private:
        void initEvents();
    };

    using ConstControlOptionalReference =
            std::optional<std::reference_wrapper<const Control>>;

    using ControlOptionalReference =
        std::optional<std::reference_wrapper<Control>>;

}