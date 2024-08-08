#pragma once

#include "control.h"
#include "UIManager.h"

#include "window.h"

#include <iostream> //ETOTODO: REMOVE

namespace clsn::ui
{
    template <typename Constraint>
    class ListContainer : public control
    {
    public:
        struct ControlAndConstraint
        {
            std::shared_ptr<control> m_control;
            Constraint m_constraint;
        };

    private:
        std::vector<ControlAndConstraint> m_controls;
        mutable bool m_needsToPaintTheContainer;

    public:
        explicit ListContainer(std::string_view section_name)
        : control{section_name}
        , m_needsToPaintTheContainer{false}
        {
            loadContainerDefaults();
            initListContainerEvents();
        }

        template <typename ControlType, typename... Args>
        std::shared_ptr<ControlType> makeAndAdd(Args&&... args)
        {
            Constraint constraint{std::forward<Args>(args)...};
            checkIfValidBeforeAdding(constraint);

            auto ptr = std::make_shared<ControlType>();
            ptr->set_parent_window(get_parent_window());
            m_controls.emplace_back(ptr, std::move(constraint));
            init_events(*ptr);
            return ptr;
        }

        int getCount() const noexcept
        {
            return static_cast<int>(m_controls.size());
        }

        auto getControlAndConstraintAt(int index) -> ControlAndConstraint&
        {
            return m_controls[index];
        }

        auto getControlAndConstraintAt(int index) const -> const ControlAndConstraint&
        {
            return m_controls[index];
        }

        auto get_visible_count() const -> int
        {
            int count = getCount();
            int visibleCount = 0;
            for (int i = 0; i < count; i++)
            {
                if (m_controls[i].m_control->is_visible())
                    visibleCount++;
            }

            return visibleCount;
        }

        auto getVisibleControls() const
            -> std::vector<std::shared_ptr<const control>>
        {
            std::vector<std::shared_ptr<const control>> controls;

            for (auto& c : m_controls)
            {
                auto& control = c.first;
                if (!control->is_visible())
                    continue;

                controls.push_back(control);
            }

            return controls;
        }

        auto& operator[](int index) { return *(m_controls[index].m_control); }

        const auto& operator[](int index) const noexcept
        {
            return *(m_controls[index].m_control);
        }

        auto getConstraintAt(int index) const -> const Constraint&
        {
            return m_controls[index].m_constraint;
        }

        template <typename Proc>
        void iterate(Proc proc)
        {
            for (auto& p : m_controls)
            {
                proc(*(p.m_control), p.m_constraint);
            }
        }

        template <typename Proc>
        void iterate(Proc proc) const
        {
            for (auto& p : m_controls)
            {
                proc(*(p.m_control), p.m_constraint);
            }
        }

        void invalidate() const noexcept override
        {
            m_needsToPaintTheContainer = true;

            int count = getCount();
            for (int i = 0; i < count; i++)
                m_controls[i].m_control->invalidate();
        }

        void validate() const noexcept override
        {
            m_needsToPaintTheContainer = false;

            int count = getCount();
            for (int i = 0; i < count; i++)
                m_controls[i].m_control->validate();
        }

        auto needsToPaintTheContainer() const noexcept -> bool
        {
            return m_needsToPaintTheContainer;
        }

        auto is_invalidated() const noexcept -> bool override
        {
            int count = getCount();
            for (int i = 0; i < count; i++)
                if (m_controls[i].m_control->is_invalidated())
                    return true;

            return false;
        }

        void load_defaults() override
        {
            control::load_defaults();

            loadContainerDefaults();

            for (auto& e : m_controls)
            {
                e.m_control->load_defaults();
            }
        }

        auto get_control_by_position(const point &point) const
    -> std::optional<std::reference_wrapper<const control>> override
        {
            const auto count = getCount();
            for (int i = 0; i < count; i++)
            {
                auto& control = (*this)[i];
                if (!control.is_visible() || !control.is_enabled())
                    continue;

                auto result = control.get_control_by_position(point);
                if (result.has_value())
                    return result;
            }

            return std::nullopt;
        }

    protected:
        virtual void checkIfValidBeforeAdding(const Constraint&) const
        {
            // Do nothing here
        }

        void process_mouse_click_event(events::MouseClickEvent& e) override
        {
            const auto count = getCount();
            for (int i = 0; i < count; i++)
            {
                auto& control = (*this)[i];
                if (!control.is_visible() || !control.is_enabled())
                    continue;

                if (control.contains_point(e.getPoint()))
                {
                    control.notify_mouse_click_event(e);
                }
            }

            control::process_mouse_click_event(e);
        }

        void process_mouse_moved_event(events::MouseMovedEvent& e) override
        {
            control::process_mouse_moved_event(e);

            const auto count = getCount();
            for (int i = 0; i < count; i++)
            {
                auto& control = (*this)[i];
                if (!control.is_visible() || !control.is_enabled())
                    continue;

                if (control.contains_point(e.position))
                {
                    control.notify_mouse_moved_event(e);
                }
            }
        }

    private:
        void initListContainerEvents()
        {
            add_actual_size_changed_listener(
                [this](auto& )
                {
                    do_layout();
                });
        }


        void loadContainerDefaults()
        {
            auto& uiManager = clsn::ui::UIManager::getInstance();
            auto section_name = get_default_section_name();

            set_background_color(uiManager.getColor(
                section_name, "containerBackgroundColor"));

            set_foreground_color(uiManager.getColor(
                section_name, "containerForegroundColor"));
        }


        void init_events(control& control)
        {
            add_enabled_changed_listener([this](auto& e)
            {
                const auto count = getCount();
                for (int i = 0; i < count; i++)
                {
                    auto& control = (*this)[i];
                    control.set_enabled(e.get_new_value());
                }
            });

            control.add_visible_changed_listener(
                [this](auto&)
                {
                    do_layout();
                    invalidate();
                });
        }
    };
}
