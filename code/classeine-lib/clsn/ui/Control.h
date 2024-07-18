#pragma once

#include "clsn/ui/Graphics.h"

#include "clsn/ui/events/ControlResizedEvent.h"
#include "clsn/ui/events/MouseClickEvent.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Point.h"
#include "clsn/draw/Region.h"

#include "clsn/core/EntityWrapper.h"
#include "clsn/core/EventListenerList.h"
#include "clsn/core/Property.h"

#include <memory>
#include <string_view>

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;
    using namespace clsn::ui::events;

    class IRenderer;
    class Window;

    class Control : public Entity
    {
        EventListenerList<MouseClickEvent> m_mouseClickListeners;
        EventListenerList<ControlResizedEvent> m_controlResizedListeners;

        std::shared_ptr<Entity> m_tag;
        mutable std::shared_ptr<IRenderer> m_renderer;

        std::string m_defaultSectionName;

        mutable bool m_invalidated;

        std::optional<std::reference_wrapper<Window>> m_parentWindow;

    public:
        explicit Control(std::string_view sectionName);

        CLSN_PROPERTY(ActualPosition, Point, true);
        CLSN_PROPERTY(ActualSize, Dimension, true);
        CLSN_PROPERTY(BackgroundColor, std::optional<Color>, true);
        CLSN_BOOL_PROPERTY_VAL(Enabled, true, true);
        CLSN_PROPERTY(Font, std::optional<Font>, true);
        CLSN_PROPERTY(ForegroundColor, std::optional<Color>, true);
        CLSN_PROPERTY(Text, std::string, true);
        CLSN_BOOL_PROPERTY_VAL(Visible, true, true);

        auto getActualBackgroundColor() const -> const Color&;
        auto getActualForegroundColor() const -> const Color&;
        auto getActualFont() const -> const Font&;

        void addMouseClickListener(EventListener<MouseClickEvent> event);
        void notifyMouseClickEvent(MouseClickEvent& e);

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

        void doLayout() noexcept;

        virtual void invalidate() const noexcept;
        virtual void validate() const noexcept;
        virtual auto isInvalidated() const noexcept -> bool;

        virtual void releaseMouse();

        void setParentWindow(std::optional<std::reference_wrapper<Window>>);
        auto getParentWindow() -> std::optional<std::reference_wrapper<Window>>;
        auto getParentWindow() const -> std::optional<std::reference_wrapper<const Window>>;

        void setBounds(const Region& bounds);
        auto getBounds() const -> Region;

        auto containsPoint(const Point& point) const -> bool;

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

    private:
        void initEvents();
    };
}