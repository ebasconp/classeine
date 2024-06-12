#pragma once

#include "clsn/ui/Graphics.h"
#include "clsn/ui/IRenderer.h"
#include "clsn/ui/UIManager.h"

#include "clsn/ui/events/ControlResizedEvent.h"
#include "clsn/ui/events/MouseClickEvent.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"

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

    class Window;

    class Control : public Entity
    {
        EventListenerList<MouseClickEvent> m_mouseClickListeners;
        EventListenerList<ControlResizedEvent> m_controlResizedListeners;

        std::shared_ptr<Entity> m_tag;
        std::shared_ptr<IRenderer> m_renderer;

        std::string m_defaultSectionName;

        mutable bool m_invalidated;

        std::optional<std::reference_wrapper<Window>> m_parentWindow;

    public:
        explicit Control(std::string_view sectionName);

        CLSN_PROPERTY(BackgroundColor, Color, true);
        CLSN_BOOL_PROPERTY_VAL(Enabled, true, true);
        CLSN_PROPERTY(Font, Font, true);
        CLSN_PROPERTY(ForegroundColor, Color, true);
        CLSN_PROPERTY(Size, Dimension, true);
        CLSN_PROPERTY(Text, std::string, true);
        CLSN_BOOL_PROPERTY_VAL(Visible, true, true);

        void addMouseClickListener(EventListener<MouseClickEvent> event);
        void paint(Graphics& graphics, const Region& region) const;
        void processMouseClickEvent(events::MouseClickEvent& e);

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

        virtual void doLayout() noexcept;
        virtual void invalidate() const noexcept;
        virtual void validate() const noexcept;
        virtual auto isInvalidated() const noexcept -> bool;

        void setParentWindow(std::optional<std::reference_wrapper<Window>>);
        std::optional<std::reference_wrapper<Window>> getParentWindow();
        std::optional<std::reference_wrapper<const Window>> getParentWindow()
            const;

    private:
        void initEvents();
    };
}