//
// Created by foobles on 12/20/2021.
//

#include "assert.hpp"
#include "SDL_error.h"
#include <stdexcept>

void engine_throw() {
    throw std::runtime_error(SDL_GetError());
}