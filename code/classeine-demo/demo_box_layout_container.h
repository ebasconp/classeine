#pragma once

// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/Button.h>
#include <clsn/ui/EmptyControl.h>
#include <clsn/ui/Label.h>

#include <clsn/ui/renderers/CustomizableRenderer.h>

#include <clsn/draw/Colors.h>

namespace clsn::demo
{
    template <typename LayoutContainer>
    class demo_box_layout_container : public LayoutContainer
    {
        std::shared_ptr<clsn::ui::Button> m_button;
        std::shared_ptr<clsn::ui::EmptyControl> m_control;
        std::shared_ptr<clsn::ui::Label> m_label;

    public:
        demo_box_layout_container()
        {
            m_button  = this->add(Control::make<Button>());
            m_button->setCaption("Click me to toggle UI theme");
            m_button->setBackgroundColor(draw::Colors::makeRed());
            m_button->setForegroundColor(draw::Colors::makeWhite());
            m_button->addActionListener([](auto&)
            {
                auto& _ui_mgr = ui::UIManager::get_instance();
                const auto& theme_name = _ui_mgr.getCurrentThemeName();
                _ui_mgr.installTheme(theme_name == "light" ? "dark" : "light");
            });

            m_control = this->add(Control::make<EmptyControl>());
            m_control->setRenderer(std::make_unique<renderers::CustomizableRenderer>([](auto& gfx, auto& rgn, auto&)
            {
                gfx.setDrawColor(draw::Colors::makeYellow());
                gfx.drawFillRectangle(rgn);
            }));

            m_label = this->add(Control::make<Label>());
            m_label->setCaption("This is a Label");
            m_label->setBackgroundColor(draw::Colors::makeBlue());
            m_label->setForegroundColor(draw::Colors::makeWhite());
        }
    };
}