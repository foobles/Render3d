//
// Created by foobles on 12/20/2021.
//

#include "engine/subsys/graphics_controller.hpp"

#include <algorithm>
#include <cmath>
#include "SDL_render.h"
#include "engine/assert.hpp"
#include "engine/subsys/graphics.hpp"


using namespace engine;

GraphicsController::GraphicsController(Graphics &graphics) noexcept :
    window(graphics.get_window()),
    renderer(graphics.get_renderer())
{}

void GraphicsController::setColor(RgbaColor color) {
    int set_color_result = SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    engine_assert(set_color_result == 0);
}

void GraphicsController::drawPixel(IVec2 pos) {
    int draw_pixel_result = SDL_RenderDrawPoint(renderer, pos.x, pos.y);
    engine_assert(draw_pixel_result == 0);
}

int GraphicsController::get_window_width() const {
    int w;
    SDL_GetWindowSize(window, &w, nullptr);
    return w;
}


int GraphicsController::get_window_height() const {
    int h;
    SDL_GetWindowSize(window, nullptr, &h);
    return h;
}

void GraphicsController::drawLine(IVec2 p0, IVec2 p1) {
    int delta_x = p1.x - p0.x;
    int delta_y = p1.y - p0.y;
    if (std::abs(delta_x) > std::abs(delta_y)) {
        if (delta_x < 0) {
            std::swap(p0.x, p1.x);
            p0.y = p1.y;
            delta_x = -delta_x;
            delta_y = -delta_y;
        }
        int dir = (delta_y > 0)? +1 : -1;
        int err = 0;
        for (IVec2 cur = p0; cur.x <= p1.x; ++cur.x) {
            bool rollover = 2*err > delta_x;
            err += std::abs(delta_y) - delta_x * rollover;
            cur.y += dir * rollover;
            drawPixel(cur);
        }
    } else {
        if (delta_y < 0) {
            std::swap(p0.y, p1.y);
            p0.x = p1.x;
            delta_x = -delta_x;
            delta_y = -delta_y;
        }
        int dir = (delta_x > 0)? +1 : -1;
        int err = 0;
        for (IVec2 cur = p0; cur.y <= p1.y; ++cur.y) {
            bool rollover = 2*err > delta_y;
            err += std::abs(delta_x) - delta_y * rollover;
            cur.x += dir * rollover;
            drawPixel(cur);
        }
    }
}
