// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/static_content_pane.h>

#include "renderers/padding_control_renderer.h"

namespace clsn::ui
{
    template <typename InnerControlType>
    class padding_control : public static_content_pane<InnerControlType>
    {
        CLSN_FULL_PROPERTY_WITH_DEFAULT_VALUE(Size, int, true, 4)

    public:
        padding_control() : static_content_pane<InnerControlType>("padding_control")
        {
            init_padding_control_events();
        }

        void do_layout() override
        {
            const auto size = m_propertySize.get();

            auto& ctrl = this->get_inner_control();
            ctrl.setActualPosition(this->getActualPosition() + draw::Point{size, size});
            ctrl.setActualSize(this->getActualSize() + draw::Dimension(-size * 2, -size * 2));

            ctrl.do_layout();
        }

    protected:
        [[nodiscard]] auto make_default_renderer() const -> std::unique_ptr<renderer_base> override
        {
            return std::make_unique<renderers::padding_control_renderer<InnerControlType>>();
        }

    private:
        void init_padding_control_events()
        {
            m_propertySize.addValueChangedListener([this](auto&)
            {
                do_layout();
                this->invalidate();
            });
        }
    };
}