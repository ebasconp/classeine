#pragma once

#include "GraphicsSdl2Impl.h"

#include "clsn/ui/events/ControlResizedEvent.h"
#include "clsn/ui/events/MouseClickEvent.h"
#include "clsn/ui/events/MouseMovedEvent.h"

#include "clsn/draw/Dimension.h"
#include "clsn/draw/Point.h"
#include "clsn/draw/Region.h"

#include "clsn/core/Panic.h"

#include <SDL2/SDL.h>
#include <SDL_ttf.h>

namespace clsn::ui::impl::sdl2
{
    using clsn::draw::Dimension;

    template <typename WindowType>
    class MainWindowSdlImpl final
    {
        WindowType& m_parentWindow;

        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;
        SDL_Texture* m_texture = nullptr;

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
            using clsn::core::Panic;

            if (!m_sdlInitialized)
            {
                if (SDL_Init(SDL_INIT_VIDEO) != 0)
                {
                    SDL_Log("Error while initializing SDL: %s", SDL_GetError());
                    Panic("Error while initializing SDL: "s + SDL_GetError());
                    return;
                }

                TTF_Init();
                m_sdlInitialized = true;
            }

            const int resizable =
                m_parentWindow.isResizable() ? SDL_WINDOW_RESIZABLE : 0;

            m_window = SDL_CreateWindow(m_parentWindow.getText().c_str(),
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        m_parentWindow.getSize().getWidth(),
                                        m_parentWindow.getSize().getHeight(),
                                        SDL_WINDOW_SHOWN | resizable);
            if (m_window == nullptr)
            {
                SDL_Log("Error while creating window: %s", SDL_GetError());
                SDL_Quit();
                Panic("Error while creating window: "s + SDL_GetError());
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
                Panic("Error while creating renderer: "s + SDL_GetError());
                return;
            }

            m_texture = SDL_CreateTexture(
                m_renderer,
                SDL_PIXELFORMAT_RGBA8888,
                SDL_TEXTUREACCESS_TARGET,
                m_parentWindow.getSize().getWidth(),
                m_parentWindow.getSize().getHeight());
            if (m_texture == nullptr)
            {
                SDL_Log("Error while creating texture: %s", SDL_GetError());
                SDL_DestroyRenderer(m_renderer);
                SDL_DestroyWindow(m_window);
                Panic("Error while creating texture: "s + SDL_GetError());
                return;
            }

            auto& minimumSize = m_parentWindow.getMinimumSize();
            SDL_SetWindowMinimumSize(
                m_window, minimumSize.getWidth(), minimumSize.getHeight());

            runEventLoop();
        }

        void hide()
        {
            if (m_texture != nullptr)
            {
                SDL_DestroyTexture(m_texture);
                m_texture = nullptr;
            }

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
        void repaintAll(GraphicsSdl2Impl& graphics)
        {
            const Region region{Point{0, 0}, m_parentWindow.getActualSize()};
            m_parentWindow().paint(graphics, region);
            graphics.apply();
        }

        void runEventLoop()
        {
            m_parentWindow().doLayout();
            m_parentWindow().invalidate();

            GraphicsSdl2Impl graphics{*m_renderer, *m_texture};

            SDL_Event event;
            while (SDL_WaitEvent(&event))
            {
                switch (event.type)
                {
                    case SDL_QUIT: return;

                    case SDL_WINDOWEVENT:
                        if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                        {
                            processControlResizedEvent(event);
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

                const Region region{Point{0, 0}, m_parentWindow.getActualSize()};
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
                status, Point{e.button.x, e.button.y}};

            m_parentWindow.processMouseClickEvent(mouseClickEvent);
        }

        void triggerMouseMovedEvent(SDL_Event& e)
        {
            clsn::ui::events::MouseMovedEvent mouseMovedEvent{Point{e.motion.x, e.motion.y}};
            m_parentWindow.processMouseMovedEvent(mouseMovedEvent);
        }

        void processControlResizedEvent(const SDL_Event& e)
        {
            const int newWidth = e.window.data1;
            const int newHeight = e.window.data2;

            m_parentWindow.setActualSize(Dimension{newWidth, newHeight});
        }
    };
}