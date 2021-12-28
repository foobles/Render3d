//
// Created by foobles on 12/23/2021.
//

#include "engine.hpp"

using namespace engine;

Engine::Engine(engine::Session const &session, engine::EngineConfig config) :
    running(true),
    frame_delay(config.frame_delay),
    graphics(session, config.graphics_config),
    input(session, config.input_config)
{}

Graphics &Engine::get_graphics() noexcept {
    return graphics;
}

Input &Engine::get_input() noexcept {
    return input;
}

void Engine::quit() noexcept {
    running = false;
}