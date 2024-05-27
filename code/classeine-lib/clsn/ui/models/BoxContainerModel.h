#pragma once

#include "clsn/ui/ControlBase.h"

#include <memory>
#include <vector>

namespace clsn::ui::models
{
    class BoxContainerModel final
    {
        std::vector<std::shared_ptr<ControlBase>> m_controls;

    public:
        template <typename ControlType>
        std::shared_ptr<ControlType> createAndAdd()
        {
            auto control = std::make_shared<ControlType>();
            m_controls.push_back(control);
            return control;
        }

        ControlBase& operator[](int index) noexcept
        {
            return *m_controls[index];
        }

        const ControlBase& operator[](int index) const noexcept
        {
            return *m_controls[index];
        }

        int getCount() const noexcept
        {
            return static_cast<int>(m_controls.size());
        }

        int getVisibleCount() const noexcept
        {
            auto count = 0;

            this->iterate([this, &count](auto& control)
            {
               count += control.isVisible() ? 1 : 0;
            });

            return count;
        }

        template <typename Proc>
        void iterate(Proc proc)
        {
            const auto count = getCount();
            for (auto i = 0; i < count; i++)
                proc(*m_controls[i]);
        }

        template <typename Proc>
        void iterate(Proc proc) const
        {
            const auto count = getCount();
            for (auto i = 0; i < count; i++)
                proc(*m_controls[i]);
        }
    };
}