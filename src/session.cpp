//
// Created by foobles on 11/6/2021.
//

#include "session.hpp"

#include "assert.hpp"
#include "SDL.h"

using namespace engine;

Session::Session() {
    int init_result = SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_VIDEO);
    engine_assert(init_result == 0);
}

Session::~Session() noexcept {
    SDL_Quit();
}


