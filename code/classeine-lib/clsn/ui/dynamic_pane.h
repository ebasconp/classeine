#pragma once

#include "control.h"

#include <memory>

namespace clsn::ui
{
    class dynamic_pane : public control
    {
        std::shared_ptr<control> m_inner_control;

    public:
        dynamic_pane();

        void do_layout() override;

        auto get_inner_control() -> std::shared_ptr<control>&;
        auto get_inner_control() const -> const std::shared_ptr<control>&;

        void set_inner_control(std::shared_ptr<control> ctrl);

        void invalidate() const noexcept override;
        void validate() const noexcept override;

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}