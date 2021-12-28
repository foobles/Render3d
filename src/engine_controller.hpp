//
// Created by foobles on 12/23/2021.
//

#ifndef RENDER_ENGINE_CONTROLLER_HPP
#define RENDER_ENGINE_CONTROLLER_HPP

#include "graphics_controller.hpp"
#include "input_controller.hpp"

namespace engine {
    class Engine;

    class EngineController {
    public:
        explicit EngineController(Engine &engine) noexcept;
        EngineController(EngineController const &) = delete;
        EngineController &operator=(EngineController const &) = delete;
        EngineController(EngineController &&) noexcept;
        EngineController &operator=(EngineController &&) = delete;

        [[nodiscard]] GraphicsController get_graphics_controller() noexcept;
        [[nodiscard]] InputController get_input_controller() noexcept;

        void quit() noexcept;

    private:
        Engine *engine;
    };
}


#endif //RENDER_ENGINE_CONTROLLER_HPP
