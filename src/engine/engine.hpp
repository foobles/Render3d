//
// Created by foobles on 12/23/2021.
//

#ifndef RENDER_ENGINE_HPP
#define RENDER_ENGINE_HPP

#include "SDL_timer.h"
#include "engine/engine_controller.hpp"
#include "engine/game_state.hpp"
#include "engine/subsys/input.hpp"
#include "engine/subsys/graphics.hpp"
#include "engine/prim/units.hpp"


namespace engine {
    class Session;

    struct EngineConfig {
        Millis frame_delay;
        GraphicsConfig graphics_config;
        InputConfig input_config;
    };

    class Engine {
    public:
        Engine(Session const &session, EngineConfig config);
        ~Engine() noexcept = default;
        Engine(Engine const &) = delete;
        Engine &operator=(Engine const &) = delete;
        Engine(Engine &&) = delete;
        Engine &operator=(Engine &&) = delete;

        Graphics &get_graphics() noexcept;
        Input &get_input() noexcept;

        void quit() noexcept;

        template<DeriveGameState GameT>
        void run(GameT game);

    private:
        bool running;
        Millis frame_delay;
        Graphics graphics;
        Input input;
    };


    template<DeriveGameState GameT>
    void Engine::run(GameT game) {
        Millis prev_millis = SDL_GetTicks();
        while (running) {
            Millis cur_millis = SDL_GetTicks();
            Millis delta = cur_millis - prev_millis;

            InputEventDispatcher(*this).dispatch_events(game);
            game.handle_update(EngineController(*this), delta);
            GraphicsEventDispatcher(*this).dispatch_events(game);

            Millis process_elapsed_millis = SDL_GetTicks() - cur_millis;
            if (process_elapsed_millis < frame_delay) {
                SDL_Delay(frame_delay - process_elapsed_millis);
            }
            prev_millis = cur_millis;
        }
    }
}



#endif //RENDER_ENGINE_HPP
