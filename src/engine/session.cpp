//
// Created by foobles on 11/6/2021.
//

#include "engine/session.hpp"

#include "SDL.h"
#include "engine/assert.hpp"


using namespace engine;

Session::Session() {
    int init_result = SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_VIDEO);
    engine_assert(init_result == 0);
}

Session::~Session() noexcept {
    SDL_Quit();
}


