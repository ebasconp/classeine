#pragma once

#include "Window.h"

#include "impl/MainWindowImpl.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    template <typename ControlType>
    class MainWindow final : public Window
    {
        clsn::ui::impl::MainWindowImpl<MainWindow<ControlType>> m_impl;
        ControlType m_control;

    public:
        MainWindow()
        : Window("MainWindow")
        , m_impl{*this}
        {
            initVisibility();
            initSize();
            initDefaults();

            m_control.setParentWindow(*this);
        }

        [[nodiscard]] auto operator()() noexcept -> ControlType&
        {
            return m_control;
        }

        [[nodiscard]] auto operator()() const noexcept -> const ControlType&
        {
            return m_control;
        }

        void processMouseClickEvent(events::MouseClickEvent& e)
        {
            m_control.notifyMouseClickEvent(e);
        }

    private:
        void initDefaults()
        {
            //auto& dimension = UIManager::getInstance().getDefault(
//                "MainWindow", "size", Dimension{300, 200});
            //ETOTODO: MOVE THIS TO THE THEME

            m_control.setActualSize(Dimension{800, 600});
        }

        void initVisibility()
        {
            addVisibleChangedListener(
                [this](auto& e)
                {
                    if (e.getNewValue())
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
            addSizeChangedListener([this](auto& e)
            {
                auto& newValue = e.getNewValue();
                m_control.setActualSize(newValue);
                m_control.invalidate();
            });

            addActualSizeChangedListener([this](auto& e)
            {
                auto& newValue = e.getNewValue();
                m_control.setActualSize(newValue);
                m_control.invalidate();
            });
        }
    };
}