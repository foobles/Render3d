//
// Created by foobles on 12/20/2021.
//

#include "engine/assert.hpp"

#include <stdexcept>
#include "SDL_error.h"


void engine_throw() {
    throw std::runtime_error(SDL_GetError());
}