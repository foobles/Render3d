//
// Created by foobles on 12/22/2021.
//

#ifndef RENDER_MOUSE_HPP
#define RENDER_MOUSE_HPP

#include "SDL_mouse.h"
#include "ivec2.hpp"

namespace engine {
    enum class MouseButton {
        Left = SDL_BUTTON_LEFT,
        Right = SDL_BUTTON_RIGHT,
        Middle = SDL_BUTTON_MIDDLE,
    };

    struct MouseButtonDownEvent {
        IVec2 pos;
        MouseButton button;
    };

    struct MouseButtonUpEvent {
        IVec2 pos;
        MouseButton button;
    };

    struct MouseMoveEvent {
        IVec2 pos;
        IVec2 delta;
    };
}

#endif //RENDER_MOUSE_HPP
