// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/Window.h>

#include <clsn/ui/impl/MainWindowImpl.h>

namespace clsn::ui
{
    template <typename ControlType>
    class MainWindow : public Window
    {
        clsn::ui::impl::MainWindowImpl<MainWindow<ControlType>> m_impl;
        ControlType m_control;

    public:
        MainWindow()
        : Window("MainWindow")
        , m_impl{*this}
        {
            initMainWindowVisibility();
            initSize();
            loadWindowDefaults();

            UIManager::get_instance().addThemeChangedListener([this](auto&)
            {
                update_theme();
            });

            m_control.setParentWindow(*this);
            m_control.setParentControl(*this);
        }

        [[nodiscard]] auto operator()() noexcept -> ControlType&
        {
            return m_control;
        }

        [[nodiscard]] auto operator()() const noexcept -> const ControlType&
        {
            return m_control;
        }

        void processMouseClickEvent(events::MouseClickEvent& e) override
        {
            m_control.notifyMouseClickEvent(e);
        }

        void processMouseMovedEvent(events::MouseMovedEvent& e) override
        {
            Window::processMouseMovedEvent(e);
            m_control.notifyMouseMovedEvent(e);
        }

        auto getControlByPosition(const draw::Point& Point) const ->
            core::constOptionalReference<Control> override
        {
            return m_control.getControlByPosition(Point);
        }

    private:
        void loadWindowDefaults()
        {

        }

        void update_theme()
        {
            loadWindowDefaults();
            loadDefaults();

            m_control.loadDefaults();
            m_control.invalidate();
        }


        void initMainWindowVisibility()
        {
            addVisibleChangedListener(
                [this](auto& e)
                {
                    if (e.get_new_value())
                    {
                        m_impl.show();
                    }
                    else
                    {
                        m_impl.hide();
                    }
                });
        }

        void initSize()
        {
            //auto& Dimension = UIManager::get_instance().getDefault(
            //                "MainWindow", "size", Dimension{300, 200});
            //ETOTODO: MOVE THIS TO THE THEME

            m_control.setActualSize(draw::Dimension{800, 600});

            addSizeChangedListener([this](auto& e)
            {
                auto& new_value = e.get_new_value();

                setActualSize(new_value);
                m_control.setActualSize(new_value);
                m_control.invalidate();
            });

            addActualSizeChangedListener([this](auto& e)
            {
                auto& newValue = e.get_new_value();
                m_control.setActualSize(newValue);
                m_control.invalidate();
            });
        }
    };
}