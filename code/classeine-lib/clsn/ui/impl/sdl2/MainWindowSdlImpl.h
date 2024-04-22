#pragma once

#include "GraphicsSdl2Impl.h"

#include "clsn/draw/Dimension.h"

#include "clsn/core/Panic.h"

#include <SDL2/SDL.h>

namespace clsn::ui::impl::sdl2
{
    using clsn::draw::Dimension;

    template <typename WindowType>
    class MainWindowSdlImpl final
    {
        WindowType& m_parentWindow;

        SDL_Window* m_window = nullptr;
        SDL_Renderer* m_renderer = nullptr;
        bool m_sdlInitialized = false;

    public:
        MainWindowSdlImpl(WindowType& parentWindow)
            : m_parentWindow{parentWindow}
        {

        }

        ~MainWindowSdlImpl()
        {
            hide();

            if (m_sdlInitialized) SDL_Quit();
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

                m_sdlInitialized = true;
            }

            m_window = SDL_CreateWindow("CLASSEINE",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        m_parentWindow.getSize().getWidth(),
                                        m_parentWindow.getSize().getHeight(),
                                        SDL_WINDOW_SHOWN);
            if (m_window == nullptr)
            {
                SDL_Log("Error while creating window: %s", SDL_GetError());
                SDL_Quit();
                Panic("Error while creating window: "s + SDL_GetError());
                return;
            }

            m_renderer = SDL_CreateRenderer(
                m_window, -1, SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
            if (m_renderer == nullptr)
            {
                SDL_Log("Error while creating renderer: %s", SDL_GetError());
                SDL_DestroyWindow(m_window);
                SDL_Quit();
                Panic("Error while creating renderer: "s + SDL_GetError());
                return;
            }

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
        void runEventLoop()
        {
            GraphicsSdl2Impl graphics{*m_renderer};

            SDL_Event event;
            while (SDL_WaitEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    return;
                }

                graphics.clear();
                m_parentWindow.paint(graphics);
                graphics.apply();
            }
        }

    };
}