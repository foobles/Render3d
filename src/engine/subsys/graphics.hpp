//
// Created by foobles on 11/6/2021.
//

#ifndef RENDER_GRAPHICS_HPP
#define RENDER_GRAPHICS_HPP

#include "SDL_video.h"
#include "SDL_render.h"
#include "engine/game_state.hpp"
#include "engine/engine_controller.hpp"

namespace engine {
    struct GraphicsConfig {
        char const *window_title;
        int window_width;
        int window_height;
    };

    class Session;

    class Graphics {
    public:
        Graphics(Session const &, GraphicsConfig config);

        Graphics(Graphics const &) = delete;
        Graphics &operator=(Graphics const &) = delete;

        Graphics(Graphics &&) noexcept;
        Graphics &operator=(Graphics &&) = delete;

        ~Graphics() noexcept;

        void render_present();
        void clear();

        SDL_Window *get_window();
        SDL_Renderer *get_renderer();

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
    };


    class Engine;

    class GraphicsEventDispatcher {
    public:
        explicit GraphicsEventDispatcher(Engine &engine);

        template<DeriveGameState GameT>
        void dispatch_events(GameT const &game);

    private:
        Graphics &get_graphics();

        Engine *engine;
    };


    template<DeriveGameState GameT>
    void GraphicsEventDispatcher::dispatch_events(GameT const &game) {
        auto &graphics = get_graphics();
        graphics.clear();
        game.handle_graphics_update(EngineController(*engine));
        graphics.render_present();
    }
}


#endif //RENDER_GRAPHICS_HPP
