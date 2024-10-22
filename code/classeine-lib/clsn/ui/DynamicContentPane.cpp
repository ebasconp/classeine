// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "DynamicContentPane.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    DynamicContentPane::DynamicContentPane() : ContentPane("DynamicContentPane")
    {
    }

    auto DynamicContentPane::getInnerControl() -> std::shared_ptr<Control>&
    {
        return m_innerControl;
    }

    auto DynamicContentPane::getInnerControl() const -> const std::shared_ptr<Control>&
    {
        return m_innerControl;
    }

    void DynamicContentPane::setInnerControl(const std::shared_ptr<Control>& ctrl)
    {
        if (m_innerControl.get() == ctrl.get())
            return;

        if (m_innerControl != nullptr)
        {
            m_innerControl->setParentControl(std::nullopt);
            m_innerControl->setParentWindow(std::nullopt);
        }

        m_innerControl = ctrl;

        if (ctrl != nullptr)
        {
            m_innerControl->setParentWindow(this->getParentWindow());
            m_innerControl->setParentControl(*this);
        }

        doLayout();
        invalidate();
    }

    auto DynamicContentPane::getActualInnerControl() -> core::OptionalReference<Control>
    {
        if (m_innerControl == nullptr)
            return {};

        return *m_innerControl.get();
    }

    auto DynamicContentPane::getActualInnerControl() const -> core::constOptionalReference<Control>
    {
        if (m_innerControl == nullptr)
            return {};

        return *m_innerControl.get();
    }
}