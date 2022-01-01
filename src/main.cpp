
#include "engine/engine.hpp"
#include "engine/session.hpp"

class Game : public engine::GameState {
public:
    void handle_update(engine::EngineController eg, Millis delta) override {

    }
    void handle_key_down(engine::EngineController eg, engine::KeyDownEvent event) override {
        if (event.key == engine::Scancode::Space) {
            std::swap(start_pos, end_pos);
        }
    }
    void handle_key_up(engine::EngineController eg, engine::KeyUpEvent event) override {}
    void handle_mouse_button_down(engine::EngineController eg, engine::MouseButtonDownEvent event) override {}
    void handle_mouse_button_up(engine::EngineController eg, engine::MouseButtonUpEvent event) override {}
    void handle_mouse_move(engine::EngineController eg, engine::MouseMoveEvent event) override {
        start_pos = event.pos;
    }

    void handle_graphics_update(engine::EngineController eg) const override {
        auto graphics = eg.get_graphics_controller();
        graphics.setColor({255, 0 ,0});
        graphics.drawLine(start_pos, end_pos);
    }

private:
    engine::IVec2 start_pos = {0, 0};
    engine::IVec2 end_pos = {0, 0};
};


int main(int argc, char **argv) {
    engine::InputConfig input_config {};
    engine::GraphicsConfig graphics_config {
        .window_title = "Hello world!",
        .window_width = 400,
        .window_height = 300,
    };
    engine::EngineConfig config {
        .frame_delay = 1000 / 60,
        .graphics_config = graphics_config,
        .input_config = input_config
    };

    engine::Session session;
    engine::Engine engine(session, config);
    engine.run(Game());

    return 0;
}