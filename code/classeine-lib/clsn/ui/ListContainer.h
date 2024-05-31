#pragma once

#include "Control.h"

namespace clsn::ui
{
    template <typename Constraint>
    class ListContainer : public Control
    {
        using ControlAndConstraint = std::pair<std::shared_ptr<Control>, Constraint>;

        std::vector<ControlAndConstraint> m_controls;

    public:
        ListContainer(std::string_view sectionName)
        : Control{sectionName}
        {
        }

        template <typename ControlType, typename... Args>
        std::shared_ptr<ControlType> makeAndAdd(Args&&... args)
        {
            auto ptr = std::make_shared<ControlType>();
            m_controls.emplace_back(ptr, Constraint{std::forward<Args>(args)...});
            return ptr;
        }

        int getCount() const noexcept
        {
            return static_cast<int>(m_controls.size());
        }

        int getVisibleCount() const noexcept
        {
            auto n = 0;

            int count = getCount();
            for (auto i = 0; i < count; i++)
            {
                if (m_controls[i].first->isVisible())
                    n++;
            }

            return n;
        }

        auto& operator[](int index)
        {
            return *(m_controls[index].first);
        }

        const auto& operator[](int index) const noexcept
        {
            return *(m_controls[index].first);
        }

        template <typename Proc>
        void iterate(Proc proc)
        {
            for (auto& p : m_controls)
            {
                proc(*(p.first));
            }
        }
    };
}

//
//#include "Container.h"
//
//#include "controllers/VBoxContainerController.h"
//#include "models/BoxContainerModel.h"
//#include "renderers/VBoxContainerRenderer.h"
//
//namespace clsn::ui
//{
//    template <typename Model = models::BoxContainerModel,
//              typename Renderer = renderers::VBoxContainerRenderer,
//              typename Controller = controllers::VBoxContainerController>
//    using BasicVBoxContainer = Container<Model, Renderer, Controller>;
//
//    using VBoxContainer = BasicVBoxContainer<>;
//}