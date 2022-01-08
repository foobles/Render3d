
#include "engine/engine.hpp"
#include "engine/session.hpp"
#include "engine/media/texture.hpp"
using namespace engine;

class Game : public GameState {
public:
    Game() :
        tex("assets/test.bmp"),
        tw(tex.get_width()),
        th(tex.get_height())
    {}

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
        graphics.draw_tri(p0, p1, p2,
                          [this](GraphicsController &graphics, IVec2 pos, int det, int a0, int a1, int a2) {
                              int x = a1 * (tw-1) / det;
                              int y = (a1 + a2) * (th - 1) / det;
                              graphics.set_color(tex.get_color({x, y}));
                              graphics.draw_pixel(pos);
                          });
        graphics.draw_tri(p0, p3, p1,
                          [this](GraphicsController &graphics, IVec2 pos, int det, int a0, int a1, int a2) {
                              int x = (a1 + a2) * (tw-1) / det;
                              int y = (a2) * (th-1) / det;
                              graphics.set_color(tex.get_color({x, y}));
                              graphics.draw_pixel(pos);
                          });
    }

private:
    Texture tex;
    int tw;
    int th;
    IVec2 p0 = {0, 0};
    IVec2 p1 = {400, 300};
    IVec2 p2 = {80, 300-80};
    IVec2 p3 = {400-90, 80};
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