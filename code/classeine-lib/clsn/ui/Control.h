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

    class Control
    {
        EventListenerList<MouseClickEvent> m_mouseClickListeners;
        EventListenerList<ControlResizedEvent> m_controlResizedListeners;

        std::shared_ptr<IEntity> m_tag;
        std::shared_ptr<IRenderer> m_renderer;

        CLSN_BOOL_PROPERTY_VAL  (Invalidated, true, false)

    public:
        explicit Control(std::string_view sectionName);

        virtual ~Control() = default;

        CLSN_PROPERTY           (BackgroundColor, Color, true);
        CLSN_BOOL_PROPERTY_VAL  (Enabled, true, true);
        CLSN_PROPERTY           (Font, Font, true);
        CLSN_PROPERTY           (ForegroundColor, Color, true);
        CLSN_PROPERTY_VAL       (Size, Dimension, true, (Dimension{600, 400}));
        CLSN_PROPERTY           (Text, std::string, true);
        CLSN_BOOL_PROPERTY_VAL  (Visible, true, true);

        std::string m_defaultSectionName;

        void addMouseClickListener(EventListener<MouseClickEvent> event);
        void paint(Graphics& graphics, const Region& region);
        void processMouseClickEvent(events::MouseClickEvent& e);

        std::string_view getDefaultSectionName() const;

        template <typename TagType, typename... Args>
        void makeTag(Args&... args)
        {
            m_tag = std::make_unique<Entity<TagType>>(std::forward<Args>(args)...);
        }

        template <typename TagType>
        const TagType& getTagOrDefault(const TagType& defValue) const
        {
            if (m_tag == nullptr)
                return defValue;

            return static_cast<Entity<TagType>&>(*m_tag).get();
        }

        void setRenderer(const std::shared_ptr<IRenderer>& renderer);
    };
}