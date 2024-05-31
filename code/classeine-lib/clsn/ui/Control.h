#pragma once

#include "clsn/ui/Graphics.h"
#include "clsn/ui/IRenderer.h"
#include "clsn/ui/UIManager.h"

#include "clsn/ui/events/ControlResizedEvent.h"
#include "clsn/ui/events/MouseClickEvent.h"

#include "IRenderer.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Colors.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Region.h"

#include "clsn/core/Entity.h"
#include "clsn/core/EventListenerList.h"
#include "clsn/core/Property.h"

#include <memory>
#include <string_view>

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;
    using namespace clsn::ui::events;

    class Control : public IEntity
    {
        EventListenerList<MouseClickEvent> m_mouseClickListeners;
        EventListenerList<ControlResizedEvent> m_controlResizedListeners;

        std::shared_ptr<IEntity> m_tag;
        std::shared_ptr<IRenderer> m_renderer;

        std::string m_defaultSectionName;

        mutable bool m_invalidated;

    public:
        explicit Control(std::string_view sectionName);

        virtual ~Control() = default;

        CLSN_PROPERTY(BackgroundColor, Color, true);
        CLSN_BOOL_PROPERTY_VAL(Enabled, true, true);
        CLSN_PROPERTY(Font, Font, true);
        CLSN_PROPERTY(ForegroundColor, Color, true);
        CLSN_PROPERTY_VAL(Size, Dimension, true, (Dimension{600, 400}));
        CLSN_PROPERTY(Text, std::string, true);
        CLSN_BOOL_PROPERTY_VAL(Visible, true, true);

        void addMouseClickListener(EventListener<MouseClickEvent> event);
        void paint(Graphics& graphics, const Region& region) const;
        void processMouseClickEvent(events::MouseClickEvent& e);

        auto getDefaultSectionName() const -> std::string_view;

        template <typename TagType, typename... Args>
        void makeTag(Args&... args)
        {
            m_tag =
                std::make_unique<Entity<TagType>>(std::forward<Args>(args)...);
        }

        template <typename TagType>
        auto getTagOrDefault(const TagType& defValue) const -> const TagType&
        {
            if (m_tag == nullptr)
                return defValue;

            return static_cast<Entity<TagType>&>(*m_tag).get();
        }

        void setRenderer(const std::shared_ptr<IRenderer>& renderer);

        virtual void invalidate() const noexcept;
        virtual void validate() const noexcept;
        virtual auto isInvalidated() const noexcept -> bool;

    private:
        void initEvents();
    };
}