//
// Created by foobles on 11/6/2021.
//

#include "engine/subsys/graphics.hpp"

#include "engine/assert.hpp"
#include "engine/engine.hpp"

using namespace engine;

Graphics::Graphics(Session const &, GraphicsConfig config) {
    int creation_result = SDL_CreateWindowAndRenderer(
            config.window_width,
            config.window_height,
            SDL_WINDOW_SHOWN,
            &window,
            &renderer);
    engine_assert(creation_result == 0);
    SDL_SetWindowTitle(window, config.window_title);
}

Graphics::~Graphics() noexcept {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
}

Graphics::Graphics(Graphics &&other) noexcept :
    window(other.window),
    renderer(other.renderer)
{
    other.window = nullptr;
    other.renderer = nullptr;
}

void Graphics::render_present() {
    SDL_RenderPresent(renderer);
}

void Graphics::clear() {
    int set_color_result = SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    engine_assert(set_color_result == 0);

    int render_clear_result = SDL_RenderClear(renderer);
    engine_assert(render_clear_result == 0);
}

SDL_Window *Graphics::get_window() {
    return window;
}

SDL_Renderer *Graphics::get_renderer() {
    return renderer;
}


GraphicsEventDispatcher::GraphicsEventDispatcher(Engine &engine)
    : engine(&engine)
{}

Graphics &GraphicsEventDispatcher::get_graphics() {
    return engine->get_graphics();
}

