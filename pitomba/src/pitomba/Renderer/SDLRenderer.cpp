
#include "SDLRenderer.h"
#include "../Utils/Logger.h"


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

    void SDLRenderer::update() {
        SDL_Event e;
        while (SDL_PollEvent(&e));
        SDL_UpdateWindowSurface(window);
    }

}
