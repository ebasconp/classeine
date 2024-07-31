#pragma once

#include "Control.h"
#include "UIManager.h"

#include "Window.h"

#include <iostream> //ETOTODO: REMOVE

namespace clsn::ui
{
    template <typename Constraint>
    class ListContainer : public Control
    {
    public:
        struct ControlAndConstraint
        {
            std::shared_ptr<Control> control;
            Constraint constraint;
        };

    private:
        std::vector<ControlAndConstraint> m_controls;
        mutable bool m_needsToPaintTheContainer;

    public:
        explicit ListContainer(std::string_view sectionName)
        : Control{sectionName}
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
            ptr->setParentWindow(getParentWindow());
            m_controls.emplace_back(ptr, std::move(constraint));
            initEvents(*ptr);
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

        auto getVisibleCount() const -> int
        {
            int count = getCount();
            int visibleCount = 0;
            for (int i = 0; i < count; i++)
            {
                if (m_controls[i].control->isVisible())
                    visibleCount++;
            }

            return visibleCount;
        }

        auto getVisibleControls() const
            -> std::vector<std::shared_ptr<const Control>>
        {
            std::vector<std::shared_ptr<const Control>> controls;

            for (auto& c : m_controls)
            {
                auto& control = c.first;
                if (!control->isVisible())
                    continue;

                controls.push_back(control);
            }

            return controls;
        }

        auto& operator[](int index) { return *(m_controls[index].control); }

        const auto& operator[](int index) const noexcept
        {
            return *(m_controls[index].control);
        }

        auto getConstraintAt(int index) const -> const Constraint&
        {
            return m_controls[index].constraint;
        }

        template <typename Proc>
        void iterate(Proc proc)
        {
            for (auto& p : m_controls)
            {
                proc(*(p.control), p.constraint);
            }
        }

        template <typename Proc>
        void iterate(Proc proc) const
        {
            for (auto& p : m_controls)
            {
                proc(*(p.control), p.constraint);
            }
        }

        void invalidate() const noexcept override
        {
            m_needsToPaintTheContainer = true;

            int count = getCount();
            for (int i = 0; i < count; i++)
                m_controls[i].control->invalidate();
        }

        void validate() const noexcept override
        {
            m_needsToPaintTheContainer = false;

            int count = getCount();
            for (int i = 0; i < count; i++)
                m_controls[i].control->validate();
        }

        auto needsToPaintTheContainer() const noexcept -> bool
        {
            return m_needsToPaintTheContainer;
        }

        auto isInvalidated() const noexcept -> bool override
        {
            int count = getCount();
            for (int i = 0; i < count; i++)
                if (m_controls[i].control->isInvalidated())
                    return true;

            return false;
        }

        void loadDefaults() override
        {
            Control::loadDefaults();

            loadContainerDefaults();

            for (auto& e : m_controls)
            {
                e.control->loadDefaults();
            }
        }

        auto getControlByPosition(const Point &point) const
    -> std::optional<std::reference_wrapper<const Control>> override
        {
            const auto count = getCount();
            for (int i = 0; i < count; i++)
            {
                auto& control = (*this)[i];
                if (!control.isVisible() || !control.isEnabled())
                    continue;

                auto result = control.getControlByPosition(point);
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

        void processMouseClickEvent(events::MouseClickEvent& e) override
        {
            const auto count = getCount();
            for (int i = 0; i < count; i++)
            {
                auto& control = (*this)[i];
                if (!control.isVisible() || !control.isEnabled())
                    continue;

                if (control.containsPoint(e.getPoint()))
                {
                    control.notifyMouseClickEvent(e);
                }
            }

            Control::processMouseClickEvent(e);
        }

        void processMouseMovedEvent(events::MouseMovedEvent& e) override
        {
            Control::processMouseMovedEvent(e);

            const auto count = getCount();
            for (int i = 0; i < count; i++)
            {
                auto& control = (*this)[i];
                if (!control.isVisible() || !control.isEnabled())
                    continue;

                if (control.containsPoint(e.position))
                {
                    control.notifyMouseMovedEvent(e);
                }
            }
        }

    private:
        void initListContainerEvents()
        {
            addActualSizeChangedListener(
                [this](auto& )
                {
                    doLayout();
                });
        }


        void loadContainerDefaults()
        {
            auto& uiManager = clsn::ui::UIManager::getInstance();
            auto sectionName = getDefaultSectionName();

            setBackgroundColor(uiManager.getColor(
                sectionName, "containerBackgroundColor"));

            setForegroundColor(uiManager.getColor(
                sectionName, "containerForegroundColor"));
        }


        void initEvents(Control& control)
        {
            addEnabledChangedListener([this](auto& e)
            {
                const auto count = getCount();
                for (int i = 0; i < count; i++)
                {
                    auto& control = (*this)[i];
                    control.setEnabled(e.getNewValue());
                }
            });

            control.addVisibleChangedListener(
                [this](auto&)
                {
                    doLayout();
                    invalidate();
                });
        }
    };
}
