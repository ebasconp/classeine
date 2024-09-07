#pragma once

#include <clsn/ui/forward.h>

#include <clsn/ui/vbox_layout_container.h>

namespace clsn::demo
{
    using namespace clsn::ui;

    class demo_option_container : public vbox_layout_container
    {
        std::shared_ptr<button> m_hbox_demo;
        std::shared_ptr<button> m_vbox_demo;
        std::shared_ptr<button> m_dual_demo;
        std::shared_ptr<button> m_flow_demo;
        std::shared_ptr<button> m_xy_demo;
        std::shared_ptr<button> m_controls;

    public:
        demo_option_container();

    private:
        void init_options();
    };
}