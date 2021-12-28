//
// Created by foobles on 12/5/2021.
//

#include "input_controller.hpp"

#include "input.hpp"
#include "SDL_keyboard.h"
#include "SDL_mouse.h"

using namespace engine;

InputController::InputController(Input &input) noexcept :
    input(&input)
{}

bool InputController::is_key_down(Scancode sc) const noexcept {
    auto kb_state = SDL_GetKeyboardState(nullptr);
    return kb_state[static_cast<SDL_Scancode>(sc)];
}

bool InputController::is_mouse_button_down(MouseButton mb) const noexcept {
    auto mouse_state = SDL_GetMouseState(nullptr, nullptr);
    return mouse_state & SDL_BUTTON(static_cast<int>(mb));
}

IVec2 InputController::get_mouse_position() const noexcept {
    IVec2 ret {};
    SDL_GetMouseState(&ret.x, &ret.y);
    return ret;
}
