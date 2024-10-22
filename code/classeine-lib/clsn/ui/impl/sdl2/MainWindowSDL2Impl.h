// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/impl/sdl2/GraphicsSDL2Impl.h>

#include <clsn/ui/events/ControlResizedEvent.h>
#include <clsn/ui/events/MouseClickEvent.h>
#include <clsn/ui/events/MouseMovedEvent.h>

#include <clsn/draw/Dimension.h>
#include <clsn/draw/Point.h>
#include <clsn/draw/Region.h>

#include <clsn/core/System.h>

#include <SDL.h>
#undef main

#include <SDL_ttf.h>

namespace clsn::ui::impl::sdl2
{
    template <typename WindowType>
    class MainWindowSDL2Impl final
    {
        WindowType& m_parentWindow;

        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;

        bool m_SDLInitialized = false;

    public:
        explicit MainWindowSDL2Impl(WindowType& parentWindow)
        : m_parentWindow{parentWindow}
        {
        }

        ~MainWindowSDL2Impl()
        {
            hide();

            if (m_SDLInitialized)
            {
                TTF_Quit();
                SDL_Quit();
            }
        }

        void show()
        {
            using namespace std::string_literals;
            using namespace clsn::core;

            if (!m_SDLInitialized)
            {
                if (SDL_Init(SDL_INIT_VIDEO) != 0)
                {
                    SDL_Log("Error while initializing SDL: %s", SDL_GetError());

                    System::panic("Error while initializing SDL: {}", SDL_GetError());
                    return;
                }

                TTF_Init();
                m_SDLInitialized = true;
            }

            const int resizable =
                m_parentWindow.isResizable() ? SDL_WINDOW_RESIZABLE : 0;

            m_window = SDL_CreateWindow(m_parentWindow.getCaption().c_str(),
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        m_parentWindow.getSize().getWidth(),
                                        m_parentWindow.getSize().getHeight(),
                                        SDL_WINDOW_SHOWN | resizable);
            if (m_window == nullptr)
            {
                SDL_Log("Error while creating Window: %s", SDL_GetError());
                SDL_Quit();

                System::panic("Error while creating Window: {}", SDL_GetError());
                return;
            }

            m_renderer = SDL_CreateRenderer(m_window,
                                            -1,
                                            SDL_RENDERER_ACCELERATED |
                                                SDL_RENDERER_PRESENTVSYNC);
            if (m_renderer == nullptr)
            {
                SDL_Log("Error while creating renderer: %s", SDL_GetError());
                SDL_DestroyWindow(m_window);
                SDL_Quit();

                System::panic("Error while creating renderer: {}", SDL_GetError());
                return;
            }

            auto& minimumSize = m_parentWindow.getMinimumSize();
            SDL_SetWindowMinimumSize(
                m_window, minimumSize.getWidth(), minimumSize.getHeight());

            run_event_loop();
        }

        void hide()
        {
            if (m_renderer != nullptr)
            {
                SDL_DestroyRenderer(m_renderer);
                m_renderer = nullptr;
            }

            if (m_window != nullptr)
            {
                SDL_DestroyWindow(m_window);
                m_window = nullptr;
            }
        }

        void repaint()
        {
            SDL_Event e;
            e.type = SDL_USEREVENT;
            SDL_PushEvent(&e);
        }

    private:
        void resizeGraphics(GraphicsSDL2Impl& Graphics, const draw::Dimension& new_size)
        {
            Graphics.resize(new_size);
        }

        void repaintAll(GraphicsSDL2Impl& Graphics)
        {
            const draw::Region rgn{{0, 0}, m_parentWindow.getActualSize()};
            m_parentWindow().paint(Graphics, rgn);
            Graphics.apply();
        }

        void run_event_loop()
        {
            m_parentWindow().doLayout();
            m_parentWindow().invalidate();

            GraphicsSDL2Impl Graphics{*m_renderer, m_parentWindow.getSize()};

            SDL_Event event;
            while (SDL_WaitEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT: return;

                    case SDL_WINDOWEVENT:
                        if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                        {
                            const draw::Dimension newSize{event.window.data1, event.window.data2};

                            resizeGraphics(Graphics, newSize);
                            processControlResizedEvent(newSize);
                            repaintAll(Graphics);
                        }

                        break;

                    case SDL_MOUSEBUTTONUP:
                    case SDL_MOUSEBUTTONDOWN:
                        triggerMouseClickEvent(event, event.type);
                        break;

                    case SDL_MOUSEMOTION:
                        triggerMouseMovedEvent(event);
                        break;

                    default:
                        break;
                }

                const draw::Region rgn{{0, 0}, m_parentWindow.getActualSize()};
                m_parentWindow().paint(Graphics, rgn);
                Graphics.apply();
            }
        }

        void triggerMouseClickEvent(const SDL_Event& e, Uint32 type)
        {
            const auto status =
                type == SDL_MOUSEBUTTONDOWN
                    ? clsn::ui::events::MouseClickStatus::pressed
                    : clsn::ui::events::MouseClickStatus::released;

            clsn::ui::events::MouseClickEvent mouseClickEvent{
                status, draw::Point{e.button.x, e.button.y}};

            m_parentWindow.processMouseClickEvent(mouseClickEvent);
        }

        void triggerMouseMovedEvent(SDL_Event& e)
        {
            events::MouseMovedEvent mouseMovedEvent{{e.motion.x, e.motion.y}};
            m_parentWindow.processMouseMovedEvent(mouseMovedEvent);
        }

        void processControlResizedEvent(const draw::Dimension& newSize)
        {
            m_parentWindow.setActualSize(newSize);
        }
    };
}