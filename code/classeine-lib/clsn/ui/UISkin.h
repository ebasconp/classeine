#pragma once

#include "clsn/core/Lazy.h"

#include "clsn/ui/Control.h" //FORWARD
#include "clsn/ui/IRenderer.h"

#include "clsn/ui/renderers/NullRenderer.h"

#include <typeindex>
#include <unordered_map>


namespace clsn::ui
{
    using namespace clsn::ui::renderers;

    using LazyRenderer = Lazy<std::shared_ptr<IRenderer>>;

    template <typename RendererType>
    LazyRenderer makeLazyRendererX()
    {
        return LazyRenderer
        {
            []() { return std::make_shared<RendererType>(); }
        };
    }

    class UISkin
    {
        std::unordered_map<std::type_index, LazyRenderer> m_renderersByControlType;

    public:
        virtual ~UISkin() = default;

        template <typename ControlType, typename RendererType>
        void makeAndAdd()
        {
            m_renderersByControlType.emplace(std::type_index(typeid(ControlType)), makeLazyRendererX<RendererType>());
        }

        std::shared_ptr<IRenderer> getRendererByControl(const clsn::ui::Control& ctrl) const
        {
            auto it = m_renderersByControlType.find(std::type_index(typeid(ctrl)));
            if (it == nullptr)
                return std::make_shared<NullRenderer>();

            return it->second.get();
        }
    };
}