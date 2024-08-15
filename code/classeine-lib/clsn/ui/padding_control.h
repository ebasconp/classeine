#pragma once

#include "mono_container.h"

#include "renderers/padding_control_renderer.h"

namespace clsn::ui
{
    using namespace clsn::ui::renderers;

    template <typename InnerControlType>
    class padding_control : public mono_container<InnerControlType>
    {
        CLSN_PROPERTY_VAL(size, int, true, 4)

    public:
        padding_control() : mono_container<InnerControlType>("padding_control")
        {
            init_padding_control_events();
        }

        void do_layout() override
        {
            const auto size = m_size.get();

            auto& ctrl = this->get_inner_control();
            ctrl.set_actual_position(this->get_actual_position() + point{size, size});
            ctrl.set_actual_size(this->get_actual_size() + dimension(-size * 2, -size * 2));

            ctrl.do_layout();
        }

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override
        {
            return std::make_unique<padding_control_renderer<InnerControlType>>();
        }

    private:
        void init_padding_control_events()
        {
            m_size.add_value_changed_listener([this](auto&)
            {
                do_layout();
                this->invalidate();
            });
        }
    };
}