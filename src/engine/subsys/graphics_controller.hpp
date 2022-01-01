//
// Created by foobles on 12/19/2021.
//

#ifndef RENDER_GRAPHICS_CONTROLLER_HPP
#define RENDER_GRAPHICS_CONTROLLER_HPP

#include "engine/prim/ivec2.hpp"
#include "engine/prim/color.hpp"


struct SDL_Renderer;
struct SDL_Window;

namespace engine {
    class Graphics;

    class GraphicsController {
    public:
        explicit GraphicsController(Graphics &graphics) noexcept;
        GraphicsController(GraphicsController const &) = delete;
        GraphicsController &operator=(GraphicsController const &) = delete;
        GraphicsController(GraphicsController &&) = delete;
        GraphicsController &operator=(GraphicsController &&) = delete;

        void setColor(RgbaColor color);
        void drawPixel(IVec2 pos);

        [[nodiscard]] int get_window_width() const;
        [[nodiscard]] int get_window_height() const;

        void drawLine(IVec2 p0, IVec2 p1);

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;
    };
}

#endif //RENDER_GRAPHICS_CONTROLLER_HPP
