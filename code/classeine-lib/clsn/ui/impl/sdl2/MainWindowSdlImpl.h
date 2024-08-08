#pragma once

#include "GraphicsSdl2Impl.h"

#include "clsn/ui/events/ControlResizedEvent.h"
#include "clsn/ui/events/MouseClickEvent.h"
#include "clsn/ui/events/MouseMovedEvent.h"

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
    class MainWindowSdlImpl final
    {
        WindowType& m_parentWindow;

        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;

        bool m_sdlInitialized = false;

    public:
        explicit MainWindowSdlImpl(WindowType& parentWindow)
        : m_parentWindow{parentWindow}
        {
        }

        ~MainWindowSdlImpl()
        {
            hide();

            if (m_sdlInitialized)
            {
                TTF_Quit();
                SDL_Quit();
            }
        }

        void show()
        {
            using namespace std::string_literals;
            using namespace clsn::core::system;

            if (!m_sdlInitialized)
            {
                if (SDL_Init(SDL_INIT_VIDEO) != 0)
                {
                    SDL_Log("Error while initializing SDL: %s", SDL_GetError());

                    //ETOTODO: Improve formatting
                    panic("Error while initializing SDL: "s + SDL_GetError());
                    return;
                }

                TTF_Init();
                m_sdlInitialized = true;
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

            runEventLoop();
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
        void resizeGraphics(GraphicsSdl2Impl& graphics, const dimension& newSize)
        {
            graphics.resize(newSize);
        }

        void repaintAll(GraphicsSdl2Impl& graphics)
        {
            const region region{point{0, 0}, m_parentWindow.get_actual_size()};
            m_parentWindow().paint(graphics, region);
            graphics.apply();
        }

        void runEventLoop()
        {
            m_parentWindow().do_layout();
            m_parentWindow().invalidate();

            GraphicsSdl2Impl graphics{*m_renderer, m_parentWindow.get_size()};

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
                            processControlResizedEvent(newSize);
                            repaintAll(graphics);
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

                const region region{point{0, 0}, m_parentWindow.get_actual_size()};
                m_parentWindow().paint(graphics, region);
                graphics.apply();
            }
        }

        void triggerMouseClickEvent(SDL_Event& e, Uint32 type)
        {
            const auto status =
                type == SDL_MOUSEBUTTONDOWN
                    ? clsn::ui::events::MouseClickStatus::pressed
                    : clsn::ui::events::MouseClickStatus::released;

            clsn::ui::events::MouseClickEvent mouseClickEvent{
                status, point{e.button.x, e.button.y}};

            m_parentWindow.process_mouse_click_event(mouseClickEvent);
        }

        void triggerMouseMovedEvent(SDL_Event& e)
        {
            clsn::ui::events::MouseMovedEvent mouseMovedEvent{point{e.motion.x, e.motion.y}};
            m_parentWindow.process_mouse_moved_event(mouseMovedEvent);
        }

        void processControlResizedEvent(const dimension& newSize)
        {
            m_parentWindow.set_actual_size(newSize);
        }
    };
}