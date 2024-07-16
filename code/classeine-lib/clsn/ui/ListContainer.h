#pragma once

#include "clsn/draw/Colors.h"

#include "Control.h"
#include "UIManager.h"

namespace clsn::ui
{
    template <typename Constraint>
    class ListContainer : public Control
    {
        using ControlAndConstraint =
            std::pair<std::shared_ptr<Control>, Constraint>;

        std::vector<ControlAndConstraint> m_controls;
        mutable bool m_needsToPaintTheContainer;

    public:
        explicit ListContainer(std::string_view sectionName)
        : Control{sectionName}
        , m_needsToPaintTheContainer{false}
        {
            loadContainerDefaults();
        }

        template <typename ControlType, typename... Args>
        std::shared_ptr<ControlType> makeAndAdd(Args&&... args)
        {
            auto ptr = std::make_shared<ControlType>();
            ptr->setParentWindow(getParentWindow());
            m_controls.emplace_back(ptr,
                                    Constraint{std::forward<Args>(args)...});
            initEvents(*ptr);
            return ptr;
        }

        int getCount() const noexcept
        {
            return static_cast<int>(m_controls.size());
        }

        auto getVisibleCount() const -> int
        {
            int count = getCount();
            int visibleCount = 0;
            for (int i = 0; i < count; i++)
            {
                if (m_controls[i].first->isVisible())
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

        auto& operator[](int index) { return *(m_controls[index].first); }

        const auto& operator[](int index) const noexcept
        {
            return *(m_controls[index].first);
        }

        template <typename Proc>
        void iterate(Proc proc)
        {
            for (auto& p : m_controls)
            {
                proc(*(p.first), p.second);
            }
        }

        template <typename Proc>
        void iterate(Proc proc) const
        {
            for (auto& p : m_controls)
            {
                proc(*(p.first), p.second);
            }
        }

        void invalidate() const noexcept override
        {
            m_needsToPaintTheContainer = true;

            int count = getCount();
            for (int i = 0; i < count; i++)
                m_controls[i].first->invalidate();
        }

        void validate() const noexcept override
        {
            m_needsToPaintTheContainer = false;

            int count = getCount();
            for (int i = 0; i < count; i++)
                m_controls[i].first->validate();
        }

        auto needsToPaintTheContainer() const noexcept -> bool
        {
            return m_needsToPaintTheContainer;
        }

        auto isInvalidated() const noexcept -> bool override
        {
            int count = getCount();
            for (int i = 0; i < count; i++)
                if (m_controls[i].first->isInvalidated())
                    return true;

            return false;
        }

        void loadDefaults() override
        {
            Control::loadDefaults();

            loadContainerDefaults();

            for (auto& e : m_controls)
            {
                e.first->loadDefaults();
            }
        }

    protected:
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

    private:
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
