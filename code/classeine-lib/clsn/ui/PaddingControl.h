// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/StaticContentPane.h>

#include <clsn/ui/renderers/PaddingControlRenderer.h>

namespace clsn::ui
{
    template <typename InnerControlType>
    class PaddingControl : public StaticContentPane<InnerControlType>
    {
        CLSN_FULL_PROPERTY_WITH_DEFAULT_VALUE(Size, int, true, 4)

    public:
        PaddingControl() : StaticContentPane<InnerControlType>("PaddingControl")
        {
            initPaddingControlEvents();
        }

        void doLayout() override
        {
            const auto size = m_propertySize.get();

            auto& ctrl = this->getInnerControl();
            ctrl.setActualPosition(this->getActualPosition() + draw::Point{size, size});
            ctrl.setActualSize(this->getActualSize() + draw::Dimension(-size * 2, -size * 2));

            ctrl.doLayout();
        }

    protected:
        [[nodiscard]] auto makeDefaultRenderer() const -> std::unique_ptr<IRenderer> override
        {
            return std::make_unique<renderers::PaddingControlRenderer<InnerControlType>>();
        }

    private:
        void initPaddingControlEvents()
        {
            m_propertySize.addValueChangedListener([this](auto&)
            {
                doLayout();
                this->invalidate();
            });
        }
    };
}