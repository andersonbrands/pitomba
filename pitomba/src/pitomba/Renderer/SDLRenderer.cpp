
#include "SDLRenderer.h"
#include "../Utils/Logger.h"
#include "../EventManager/EventManager.h"


namespace pitomba {

    SDLRenderer::SDLRenderer(const std::string& title, int width, int height)
        : WINDOW_TITLE(title), SCREEN_WIDTH(width), SCREEN_HEIGHT(height) {}

    SDLRenderer::~SDLRenderer() {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }


    bool SDLRenderer::initialize() {

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            Logger::getInstancePtr()->debug(
                boost::format("SDL could not initialize! SDL_Error: %1%\n") % SDL_GetError()
            );
            return false;
        } else {
            window = SDL_CreateWindow(
                WINDOW_TITLE.c_str(),
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
            );
            if (window == nullptr) {
                Logger::getInstancePtr()->debug(
                    boost::format("Window could not be created! SDL_Error: %1%\n") % SDL_GetError()
                );
                return false;
            } else {
                screenSurface = SDL_GetWindowSurface(window);
            }
        }

        return true;
    }

    void SDLRenderer::fillSurface(int red, int green, int blue) {
        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, red, green, blue));
    }

    void SDLRenderer::fillSurface(ColorRGB color) {
        fillSurface(color.r, color.g, color.b);
    }

    void SDLRenderer::update() {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                EventManager::getInstancePtr()->sendEvent(ev::id::APPLICATION_QUIT);
            }
        }
        SDL_UpdateWindowSurface(window);
    }

}
