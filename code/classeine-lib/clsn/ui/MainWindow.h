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
            m_control.processMouseClickEvent(e);
        }

    private:
        void initDefaults()
        {
            auto& dimension = UIManager::getInstance().getDefault(
                "MainWindow", "size", Dimension{300, 200});
            m_control.setSize(dimension);
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
            addSizeChangedListener(
                [this](const clsn::core::ValueChangedEvent<Dimension>& e)
                {
                    auto& newValue = e.getNewValue();
                    m_control.setSize(newValue);
                    m_control.invalidate();
                });
        }
    };
}