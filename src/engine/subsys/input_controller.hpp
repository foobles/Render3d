//
// Created by foobles on 12/5/2021.
//

#ifndef RENDER_INPUT_CONTROLLER_HPP
#define RENDER_INPUT_CONTROLLER_HPP

#include "engine/io/scancode.hpp"
#include "engine/io/mouse.hpp"


namespace engine {
    class Input;

    class InputController {
    public:
        explicit InputController(Input &input) noexcept;
        InputController(InputController const &) = delete;
        InputController &operator=(InputController const &) = delete;
        InputController(InputController &&) = delete;
        InputController &operator=(InputController &&) = delete;

        [[nodiscard]] bool is_key_down(Scancode sc) const noexcept;
        [[nodiscard]] bool is_mouse_button_down(MouseButton mb) const noexcept;
        [[nodiscard]] IVec2 get_mouse_position() const noexcept;

    private:
        Input *input;
    };
}



#endif //RENDER_INPUT_CONTROLLER_HPP
