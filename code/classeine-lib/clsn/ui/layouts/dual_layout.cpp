#include "dual_layout.h"

namespace clsn::ui::layouts
{
    dual_layout::dual_layout()
    : m_orientation{dual_layout_orientation::horizontal}
    {}

    auto dual_layout::get_orientation() const -> dual_layout_orientation { return m_orientation; }

    void dual_layout::layout_vertical(const point& position, const dimension& size)
    {
        const auto count = this->get_count();
        if (count == 1)
        {
            auto& cc = get_element_at(0);

            auto ch = cc.m_constraint == dual_layout_constraint::use_all_available_space
                ? size.get_height()
                : cc.m_region.get_size().get_height();

            cc.m_region = {position, {size.get_width(), ch}};
        }

        if (count == 2)
        {
            auto& cc0 = get_element_at(0);
            auto& cc1 = get_element_at(1);

            auto c0h = cc0.m_constraint == dual_layout_constraint::use_all_available_space
                            ? size.get_height() - cc1.m_region.get_height()
                            : cc0.m_region.get_height();

            auto c1h = size.get_height() - c0h;

            cc0.m_region = {position, {size.get_width(), c0h}};
            cc1.m_region = {{position.get_x(), position.get_y() + c0h}, {size.get_width(), c1h}};
        }
    }


    void dual_layout::layout_horizontal(const point& position, const dimension& size)
    {
        const auto count = get_count();
        if (count == 1)
        {
            auto& cc = get_element_at(0);

            auto cw = cc.m_constraint == dual_layout_constraint::use_all_available_space
                ? size.get_width()
                : cc.m_region.get_width();

            cc.m_region = { position, {cw, size.get_height()} };
        }

        if (count == 2)
        {
            auto& cc0 = get_element_at(0);
            auto& cc1 = get_element_at(1);

            auto c0w = cc0.m_constraint == dual_layout_constraint::use_all_available_space
                            ? size.get_width() - cc1.m_region.get_width()
                            : cc0.m_region.get_width();

            auto c1w = size.get_width() - c0w;

            cc0.m_region = {position, {c0w, size.get_height()}};
            cc1.m_region = { {position.get_x() + c0w, position.get_y()}, {c1w, size.get_height()} };
        }
    }


    void dual_layout::layout(const region& rgn)
    {
        if (this->is_empty())
            return;

        const auto& position = rgn.get_position();
        const auto& size = rgn.get_size();

        switch (m_orientation)
        {
            case dual_layout_orientation::horizontal:
                layout_horizontal(position, size);
                break;

            default:
                layout_vertical(position, size);
        }
    };
}