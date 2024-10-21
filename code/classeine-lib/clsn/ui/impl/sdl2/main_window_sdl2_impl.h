// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "graphics_sdl2_impl.h"

#include "clsn/ui/events/control_resized_event.h"
#include "clsn/ui/events/mouse_click_event.h"
#include "clsn/ui/events/mouse_moved_event.h"

#include "clsn/draw/Dimension.h"
#include "clsn/draw/Point.h"
#include "clsn/draw/Region.h"

#include "clsn/core/System.h"

#include <SDL.h>
#undef main

#include <SDL_ttf.h>

namespace clsn::ui::impl::sdl2
{
    template <typename WindowType>
    class main_window_sdl2_impl final
    {
        WindowType& m_parent_window;

        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;

        bool m_sdl_initialized = false;

    public:
        explicit main_window_sdl2_impl(WindowType& parent_window)
        : m_parent_window{parent_window}
        {
        }

        ~main_window_sdl2_impl()
        {
            hide();

            if (m_sdl_initialized)
            {
                TTF_Quit();
                SDL_Quit();
            }
        }

        void show()
        {
            using namespace std::string_literals;
            using namespace clsn::core;

            if (!m_sdl_initialized)
            {
                if (SDL_Init(SDL_INIT_VIDEO) != 0)
                {
                    SDL_Log("Error while initializing SDL: %s", SDL_GetError());

                    System::panic("Error while initializing SDL: {}", SDL_GetError());
                    return;
                }

                TTF_Init();
                m_sdl_initialized = true;
            }

            const int resizable =
                m_parent_window.isResizable() ? SDL_WINDOW_RESIZABLE : 0;

            m_window = SDL_CreateWindow(m_parent_window.getCaption().c_str(),
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        m_parent_window.getSize().getWidth(),
                                        m_parent_window.getSize().getHeight(),
                                        SDL_WINDOW_SHOWN | resizable);
            if (m_window == nullptr)
            {
                SDL_Log("Error while creating window: %s", SDL_GetError());
                SDL_Quit();

                System::panic("Error while creating window: {}", SDL_GetError());
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

            auto& minimumSize = m_parent_window.getMinimumSize();
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
        void resizeGraphics(graphics_sdl2_impl& graphics, const draw::Dimension& new_size)
        {
            graphics.resize(new_size);
        }

        void repaintAll(graphics_sdl2_impl& graphics)
        {
            const draw::Region rgn{{0, 0}, m_parent_window.getActualSize()};
            m_parent_window().paint(graphics, rgn);
            graphics.apply();
        }

        void run_event_loop()
        {
            m_parent_window().do_layout();
            m_parent_window().invalidate();

            graphics_sdl2_impl graphics{*m_renderer, m_parent_window.getSize()};

            SDL_Event Event;
            while (SDL_WaitEvent(&Event))
            {
                switch (Event.type)
                {
                    case SDL_QUIT: return;

                    case SDL_WINDOWEVENT:
                        if (Event.window.event == SDL_WINDOWEVENT_RESIZED)
                        {
                            const draw::Dimension newSize{Event.window.data1, Event.window.data2};

                            resizeGraphics(graphics, newSize);
                            process_control_resized_event(newSize);
                            repaintAll(graphics);
                        }

                        break;

                    case SDL_MOUSEBUTTONUP:
                    case SDL_MOUSEBUTTONDOWN:
                        trigger_mouse_click_event(Event, Event.type);
                        break;

                    case SDL_MOUSEMOTION:
                        trigger_mouse_moved_event(Event);
                        break;

                    default:
                        break;
                }

                const draw::Region rgn{{0, 0}, m_parent_window.getActualSize()};
                m_parent_window().paint(graphics, rgn);
                graphics.apply();
            }
        }

        void trigger_mouse_click_event(const SDL_Event& e, Uint32 type)
        {
            const auto status =
                type == SDL_MOUSEBUTTONDOWN
                    ? clsn::ui::events::mouse_click_status::pressed
                    : clsn::ui::events::mouse_click_status::released;

            clsn::ui::events::mouse_click_event mouseClickEvent{
                status, draw::Point{e.button.x, e.button.y}};

            m_parent_window.process_mouse_click_event(mouseClickEvent);
        }

        void trigger_mouse_moved_event(SDL_Event& e)
        {
            events::mouse_moved_event _mouse_moved_event{{e.motion.x, e.motion.y}};
            m_parent_window.process_mouse_moved_event(_mouse_moved_event);
        }

        void process_control_resized_event(const draw::Dimension& newSize)
        {
            m_parent_window.setActualSize(newSize);
        }
    };
}