
#include "engine/engine.hpp"
#include "engine/session.hpp"

using namespace engine;

class Game : public GameState {
public:
    void handle_update(EngineController eg, Millis delta) override {}
    void handle_key_down(EngineController eg, KeyDownEvent event) override {}
    void handle_key_up(EngineController eg, KeyUpEvent event) override {}
    void handle_mouse_button_down(EngineController eg, MouseButtonDownEvent event) override {}
    void handle_mouse_button_up(EngineController eg, MouseButtonUpEvent event) override {}
    void handle_mouse_move(EngineController eg, MouseMoveEvent event) override {
        auto in = eg.get_input_controller();
        if (in.is_mouse_button_down(MouseButton::Left)) {
            p0 = event.pos;
        } else if (in.is_mouse_button_down(MouseButton::Right)) {
            p1 = event.pos;
        }
    }

    void handle_graphics_update(EngineController eg) const override {
        auto graphics = eg.get_graphics_controller();
        graphics.drawTri(p0, p1, p2,
            [](GraphicsController &graphics, IVec2 pos, int det, int a0, int a1, int a2) {
                graphics.setColor({uint8_t(a0 * 255 / det), uint8_t(a1 * 255 / det), uint8_t(a2 * 255 / det)});
                graphics.drawPixel(pos);
            });
    }

private:
    IVec2 p0 = {0, 0};
    IVec2 p1 = {0, 0};
    IVec2 p2 = {200, 280};
};


int main(int argc, char **argv) {
    InputConfig input_config {};
    GraphicsConfig graphics_config {
        .window_title = "Hello world!",
        .window_width = 400,
        .window_height = 300,
    };
    EngineConfig config {
        .frame_delay = 1000 / 60,
        .graphics_config = graphics_config,
        .input_config = input_config
    };

    Session session;
    Engine engine(session, config);
    engine.run(Game());

    return 0;
}