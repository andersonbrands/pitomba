#ifndef SDL_RENDERER_H_
#define SDL_RENDERER_H_

#include <SDL.h>
#include <string>
#include "iRenderer.h"


namespace pitomba {

    class SDLRenderer : public iRenderer {

    public:
        explicit SDLRenderer(const std::string&, int = 640, int = 480);
        ~SDLRenderer() final;

        bool initialize() final;
        void fillSurface(int, int, int) final;
        void fillSurface(ColorRGB) final;
        void update() final;

    private:
        const std::string WINDOW_TITLE;
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;

        SDL_Window* window = nullptr;
        SDL_Surface* screenSurface = nullptr;
    };

}

#endif // SDL_RENDERER_H_
