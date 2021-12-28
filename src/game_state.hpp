//
// Created by foobles on 12/27/2021.
//

#ifndef RENDER_GAME_STATE_HPP
#define RENDER_GAME_STATE_HPP

#include <concepts>

#include "mouse.hpp"
#include "scancode.hpp"
#include "units.hpp"
#include "engine_controller.hpp"
namespace engine {

    class GameState {
    public:
        virtual void handle_update(EngineController eg, Millis delta) = 0;

        virtual void handle_key_down(EngineController eg, KeyDownEvent event) = 0;
        virtual void handle_key_up(EngineController eg, KeyUpEvent event) = 0;

        virtual void handle_mouse_button_down(EngineController eg, MouseButtonDownEvent event) = 0;
        virtual void handle_mouse_button_up(EngineController eg, MouseButtonUpEvent event) = 0;
        virtual void handle_mouse_move(EngineController eg, MouseMoveEvent event) = 0;

        virtual void handle_graphics_update(EngineController eg) const = 0;
    };

    template<typename GameT>
    concept DeriveGameState = std::derived_from<GameT, GameState>;
}

#endif //RENDER_GAME_STATE_HPP
