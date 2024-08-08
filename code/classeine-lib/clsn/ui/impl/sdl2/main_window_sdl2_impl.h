#pragma once

#include "graphics_sdl2_impl.h"

#include "clsn/ui/events/control_resized_event.h"
#include "clsn/ui/events/mouse_click_event.h"
#include "clsn/ui/events/mouse_moved_event.h"

#include "clsn/draw/dimension.h"
#include "clsn/draw/point.h"
#include "clsn/draw/region.h"

#include "clsn/core/system.h"

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

namespace clsn::ui::impl::sdl2
{
    using clsn::draw::dimension;

    template <typename WindowType>
    class main_window_sdl2_impl final
    {
        WindowType& m_parentWindow;

        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;

        bool m_sdl_initialized = false;

    public:
        explicit main_window_sdl2_impl(WindowType& parentWindow)
        : m_parentWindow{parentWindow}
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
            using namespace clsn::core::system;

            if (!m_sdl_initialized)
            {
                if (SDL_Init(SDL_INIT_VIDEO) != 0)
                {
                    SDL_Log("Error while initializing SDL: %s", SDL_GetError());

                    //ETOTODO: Improve formatting
                    panic("Error while initializing SDL: "s + SDL_GetError());
                    return;
                }

                TTF_Init();
                m_sdl_initialized = true;
            }

            const int resizable =
                m_parentWindow.is_resizable() ? SDL_WINDOW_RESIZABLE : 0;

            m_window = SDL_CreateWindow(m_parentWindow.get_text().c_str(),
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        m_parentWindow.get_size().get_width(),
                                        m_parentWindow.get_size().get_height(),
                                        SDL_WINDOW_SHOWN | resizable);
            if (m_window == nullptr)
            {
                SDL_Log("Error while creating window: %s", SDL_GetError());
                SDL_Quit();
                //ETOTODO: Improve formatting
                panic("Error while creating window: "s + SDL_GetError());
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
                //ETOTODO: Improve formatting
                panic("Error while creating renderer: "s + SDL_GetError());
                return;
            }

            auto& minimumSize = m_parentWindow.get_minimum_size();
            SDL_SetWindowMinimumSize(
                m_window, minimumSize.get_width(), minimumSize.get_height());

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
        void resizeGraphics(graphics_sdl2_impl& graphics, const dimension& newSize)
        {
            graphics.resize(newSize);
        }

        void repaintAll(graphics_sdl2_impl& graphics)
        {
            const region region{point{0, 0}, m_parentWindow.get_actual_size()};
            m_parentWindow().paint(graphics, region);
            graphics.apply();
        }

        void run_event_loop()
        {
            m_parentWindow().do_layout();
            m_parentWindow().invalidate();

            graphics_sdl2_impl graphics{*m_renderer, m_parentWindow.get_size()};

            SDL_Event event;
            while (SDL_WaitEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT: return;

                    case SDL_WINDOWEVENT:
                        if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                        {
                            const dimension newSize{event.window.data1, event.window.data2};

                            resizeGraphics(graphics, newSize);
                            process_control_resized_event(newSize);
                            repaintAll(graphics);
                        }

                        break;

                    case SDL_MOUSEBUTTONUP:
                    case SDL_MOUSEBUTTONDOWN:
                        trigger_mouse_click_event(event, event.type);
                        break;

                    case SDL_MOUSEMOTION:
                        trigger_mouse_moved_event(event);
                        break;

                    default:
                        break;
                }

                const region region{point{0, 0}, m_parentWindow.get_actual_size()};
                m_parentWindow().paint(graphics, region);
                graphics.apply();
            }
        }

        void trigger_mouse_click_event(SDL_Event& e, Uint32 type)
        {
            const auto status =
                type == SDL_MOUSEBUTTONDOWN
                    ? clsn::ui::events::mouse_click_status::pressed
                    : clsn::ui::events::mouse_click_status::released;

            clsn::ui::events::mouse_click_event mouseClickEvent{
                status, point{e.button.x, e.button.y}};

            m_parentWindow.process_mouse_click_event(mouseClickEvent);
        }

        void trigger_mouse_moved_event(SDL_Event& e)
        {
            clsn::ui::events::mouse_moved_event mouseMovedEvent{point{e.motion.x, e.motion.y}};
            m_parentWindow.process_mouse_moved_event(mouseMovedEvent);
        }

        void process_control_resized_event(const dimension& newSize)
        {
            m_parentWindow.set_actual_size(newSize);
        }
    };
}