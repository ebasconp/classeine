#pragma once

#include "clsn/draw/region.h"

#include <vector>

namespace clsn::ui::layouts
{
    using namespace clsn::draw;

    template <typename Constraint>
    class layout_base
    {
        struct region_and_constraint
        {
            region m_region;
            Constraint m_constraint;
        };

        std::vector<region_and_constraint> m_elements;

    public:
        virtual ~layout_base() = default;

        void add(const region& rgn, const Constraint& constraint)
        {
            m_elements.push_back(region_and_constraint{rgn, constraint});
        }

        [[nodiscard]] auto is_empty() const noexcept -> bool { return m_elements.empty(); }

        [[nodiscard]] auto get_count() const noexcept -> int
        {
            return static_cast<int>(m_elements.size());
        }

        auto get_element_at(int index) -> region_and_constraint&
        {
            return m_elements[index];
        }

        auto get_element_at(int index) const -> const region_and_constraint&
        {
            return m_elements[index];
        }

        virtual void layout(const region& rgn) = 0;
    };
}