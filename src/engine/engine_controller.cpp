//
// Created by foobles on 12/23/2021.
//

#include "engine/engine_controller.hpp"

#include "engine/engine.hpp"


using namespace engine;

EngineController::EngineController(engine::Engine &engine) noexcept :
    engine(&engine)
{}

GraphicsController EngineController::get_graphics_controller() noexcept {
    return GraphicsController(engine->get_graphics());
}

InputController EngineController::get_input_controller() noexcept {
    return InputController(engine->get_input());
}

void EngineController::quit() noexcept {
    engine->quit();
}

EngineController::EngineController(EngineController &&other) noexcept :
    engine(other.engine)
{
    other.engine = nullptr;
}
