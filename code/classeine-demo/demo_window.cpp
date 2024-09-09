#include "demo_window.h"

#include "clsn/draw/colors.h"
#include "clsn/draw/dimension.h"

#include "clsn/ui/dual_layout_container.h"
#include "clsn/ui/dynamic_pane.h"
#include "clsn/ui/label.h"

#include "demo_option_container.h"

namespace clsn::demo
{
    demo_window::demo_window()
    {
        set_text("Classeine");
        set_size({800, 600});

        init_container();
    }

    void demo_window::init_container()
    {
        m_option_container = (*this)().make_and_add<demo_option_container>(dual_layout_constraint::use_preferred_size);

        auto right_container = (*this)().make_and_add<dual_layout_container>(dual_layout_constraint::use_all_available_space);
        right_container->set_orientation(dual_layout_orientation::vertical);

        m_label = right_container->make_and_add<label>(dual_layout_constraint::use_preferred_size);
        m_label->set_preferred_size(dimension{24, 24});
        m_label->set_text("Classeine demo");
        m_label->set_background_color(colors::make_white());

        m_content_pane = right_container->make_and_add<dynamic_pane>(dual_layout_constraint::use_all_available_space);
        m_content_pane->set_background_color(clsn::draw::color{128, 0, 64});
    }
}