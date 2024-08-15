#pragma once

#include "container.h"
#include "ui_manager.h"

#include "window.h"


namespace clsn::ui
{
    template <typename Constraint>
    struct list_container_control_and_constraint
    {
        std::shared_ptr<control> m_control;
        Constraint m_constraint;
    };

    template <typename Constraint>
    class list_container : public container<list_container_control_and_constraint<Constraint>>
    {
        using control_and_constraint = list_container_control_and_constraint<Constraint>;

        std::vector<control_and_constraint> m_controls;

    public:
        explicit list_container(std::string_view section_name)
        : container<control_and_constraint>{section_name}
        {
        }

        template <typename ControlType, typename... Args>
        std::shared_ptr<ControlType> make_and_add(Args&&... args)
        {
            Constraint constraint{std::forward<Args>(args)...};
            check_if_valid_before_adding(constraint);

            auto ptr = std::make_shared<ControlType>();
            m_controls.emplace_back(ptr, std::move(constraint));
            this->init_new_control(*ptr);
            return ptr;
        }

        void iterate_elements(std::function<void(control_and_constraint&)> func) override
        {
            const auto count = m_controls.size();
            for (auto i = 0U; i < count; i++)
            {
                func(m_controls[i]);
            }
        }

        void iterate_elements(std::function<void(const control_and_constraint&)> func) const override
        {
            const auto count = m_controls.size();
            for (auto i = 0U; i < count; i++)
            {
                func(m_controls[i]);
            }
        }

        void iterate_controls(std::function<void(control&)> func) override
        {
            const auto count = m_controls.size();
            for (auto i = 0U; i < count; i++)
            {
                func(*(m_controls[i].m_control));
            }
        }

        void iterate_controls(std::function<void(const control&)> func) const override
        {
            const auto count = m_controls.size();
            for (auto i = 0U; i < count; i++)
            {
                func(*(m_controls[i].m_control));
            }
        }

        auto get_count() const noexcept -> int override
        {
            return static_cast<int>(m_controls.size());
        }

        auto get_element_at(int index) -> control_and_constraint& override
        {
            return m_controls[index];
        }

        auto get_element_at(int index) const -> const control_and_constraint& override
        {
            return m_controls[index];
        }

        auto operator[](int index) noexcept -> control& override
        {
            return *(m_controls[index].m_control);
        }

        auto operator[](int index) const noexcept -> const control& override
        {
            return *(m_controls[index].m_control);
        }

    protected:
        virtual void check_if_valid_before_adding(const Constraint&) const
        {
            // Do nothing here
        }
    };
}
