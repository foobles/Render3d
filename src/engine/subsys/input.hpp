//
// Created by foobles on 12/5/2021.
//

#ifndef RENDER_INPUT_HPP
#define RENDER_INPUT_HPP

#include <utility>
#include "SDL_events.h"
#include "engine/engine_controller.hpp"
#include "engine/game_state.hpp"
#include "engine/io/mouse.hpp"
#include "engine/io/scancode.hpp"


namespace engine {
    class Session;

    struct InputConfig {

    };

    class Input {
    public:
        Input(Session const &, InputConfig config) {}
    };

    class Engine;

    class InputEventDispatcher {
    public:
        explicit InputEventDispatcher(Engine &engine);

        template<DeriveGameState GameT>
        void dispatch_events(GameT &game);

    private:
        Engine *engine;
    };

    template<DeriveGameState GameT>
    void InputEventDispatcher::dispatch_events(GameT &game) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            EngineController eg(*engine);
            switch (event.type) {
                case SDL_QUIT: {
                    eg.quit();
                    break;
                }

                case SDL_KEYDOWN: {
                    if (event.key.repeat) {
                        break;
                    }
                    KeyDownEvent key_down {
                        .key = static_cast<Scancode>(event.key.keysym.scancode)
                    };
                    game.handle_key_down(std::move(eg), key_down);
                    break;
                }

                case SDL_KEYUP: {
                    if (event.key.repeat) {
                        break;
                    }
                    KeyUpEvent key_up {
                        .key = static_cast<Scancode>(event.key.keysym.scancode)
                    };
                    game.handle_key_up(std::move(eg), key_up);
                    break;
                }

                case SDL_MOUSEMOTION: {
                    MouseMoveEvent mouse_move {
                        .pos = { event.motion.x, event.motion.y },
                        .delta = { event.motion.xrel, event.motion.yrel }
                    };
                    game.handle_mouse_move(std::move(eg), mouse_move);
                    break;
                }

                case SDL_MOUSEBUTTONDOWN: {
                    MouseButtonDownEvent button_down {
                        .pos = { event.button.x, event.button.y },
                        .button = static_cast<MouseButton>(event.button.button)
                    };
                    game.handle_mouse_button_down(std::move(eg), button_down);
                    break;
                }

                case SDL_MOUSEBUTTONUP: {
                    MouseButtonUpEvent button_up {
                        .pos = { event.button.x, event.button.y },
                        .button = static_cast<MouseButton>(event.button.button)
                    };
                    game.handle_mouse_button_up(std::move(eg), button_up);
                    break;
                }
            }
        }
    }
};


#endif //RENDER_INPUT_HPP
