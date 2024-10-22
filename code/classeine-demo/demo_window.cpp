// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "demo_window.h"

#include "clsn/draw/Colors.h"
#include "clsn/draw/Dimension.h"

#include "clsn/ui/DualLayoutContainer.h"
#include "clsn/ui/DynamicContentPane.h"
#include "clsn/ui/Label.h"

#include "demo_option_container.h"

namespace clsn::demo
{
    using namespace clsn::draw;
    using namespace clsn::ui;
    using namespace clsn::ui::layouts;

    demo_window::demo_window()
    {
        setCaption("Classeine");
        setSize({800, 600});

        init_container();
    }

    auto demo_window::get_content_pane() -> DynamicContentPane&
    {
        return *m_content_pane;
    }

    void demo_window::init_container()
    {
        m_option_container = Control::make<demo_option_container>(*this);

        (*this)().add(m_option_container, DualLayoutConstraint::use_preferred_size);

        auto right_container = (*this)().add(Control::make<DualLayoutContainer>(), DualLayoutConstraint::use_all_available_space);
        right_container->setOrientation(DualLayoutOrientation::vertical);

        m_label = right_container->add(Control::make<Label>(), DualLayoutConstraint::use_preferred_size);
        m_label->setPreferredSize(Dimension{0, 40});
        m_label->setFont(UIManager::get_instance().getFont("", "defaultBoldFont").addSize(5));
        m_label->setBackgroundColor(Colors::makeWhite());
        m_label->setHorizontalAlignment(TextHorizontalAlignment::center);
        set_title("Classeine Demo");

        m_content_pane = right_container->add(Control::make<DynamicContentPane>(), DualLayoutConstraint::use_all_available_space);
        m_content_pane->setBackgroundColor(clsn::draw::Color{128, 0, 64});
    }

    void demo_window::set_title(const std::string& title)
    {
        m_label->setCaption(title);
    }
}