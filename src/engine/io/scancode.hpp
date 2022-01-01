//
// Created by foobles on 11/18/2021.
//

#ifndef RENDER_SCANCODE_HPP
#define RENDER_SCANCODE_HPP

#include <cstddef>
#include "SDL_scancode.h"


namespace engine {
    enum class Scancode {
        A = SDL_SCANCODE_A,
        B = SDL_SCANCODE_B,
        C = SDL_SCANCODE_C,
        D = SDL_SCANCODE_D,
        E = SDL_SCANCODE_E,
        F = SDL_SCANCODE_F,
        G = SDL_SCANCODE_G,
        H = SDL_SCANCODE_H,
        I = SDL_SCANCODE_I,
        J = SDL_SCANCODE_J,
        K = SDL_SCANCODE_K,
        L = SDL_SCANCODE_L,
        M = SDL_SCANCODE_M,
        N = SDL_SCANCODE_N,
        O = SDL_SCANCODE_O,
        P = SDL_SCANCODE_P,
        Q = SDL_SCANCODE_Q,
        R = SDL_SCANCODE_R,
        S = SDL_SCANCODE_S,
        T = SDL_SCANCODE_T,
        U = SDL_SCANCODE_U,
        V = SDL_SCANCODE_V,
        W = SDL_SCANCODE_W,
        X = SDL_SCANCODE_X,
        Y = SDL_SCANCODE_Y,
        Z = SDL_SCANCODE_Z,

        Num0 = SDL_SCANCODE_0,
        Num1 = SDL_SCANCODE_1,
        Num2 = SDL_SCANCODE_2,
        Num3 = SDL_SCANCODE_3,
        Num4 = SDL_SCANCODE_4,
        Num5 = SDL_SCANCODE_5,
        Num6 = SDL_SCANCODE_6,
        Num7 = SDL_SCANCODE_7,
        Num8 = SDL_SCANCODE_8,
        Num9 = SDL_SCANCODE_9,

        Space = SDL_SCANCODE_SPACE,

        Up    = SDL_SCANCODE_UP,
        Down  = SDL_SCANCODE_DOWN,
        Left  = SDL_SCANCODE_LEFT,
        Right = SDL_SCANCODE_RIGHT,

        LeftShift = SDL_SCANCODE_LSHIFT,

        LeftControl = SDL_SCANCODE_LCTRL,
    };

    constexpr std::size_t SCANCODE_COUNT = SDL_NUM_SCANCODES;

    struct KeyDownEvent {
        Scancode key;
    };

    struct KeyUpEvent {
        Scancode key;
    };
}

#endif //RENDER_SCANCODE_HPP
