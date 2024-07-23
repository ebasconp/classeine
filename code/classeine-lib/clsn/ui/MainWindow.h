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
            loadWindowDefaults();

            UIManager::getInstance().addThemeChangedListener([this](auto&)
            {
                updateTheme();
            });

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

        void processMouseMovedEvent(events::MouseMovedEvent& e)
        {
            Window::processMouseMovedEvent(e);
            m_control.notifyMouseMovedEvent(e);
        }

        auto getControlByPosition(const Point& point) const ->
            std::optional<std::reference_wrapper<const Control>> override
        {
            return m_control.getControlByPosition(point);
        }

    private:
        void loadWindowDefaults()
        {

        }

        void updateTheme()
        {
            loadWindowDefaults();
            loadDefaults();

            m_control.loadDefaults();
            m_control.invalidate();
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
            //auto& dimension = UIManager::getInstance().getDefault(
            //                "MainWindow", "size", Dimension{300, 200});
            //ETOTODO: MOVE THIS TO THE THEME

            m_control.setActualSize(Dimension{800, 600});

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