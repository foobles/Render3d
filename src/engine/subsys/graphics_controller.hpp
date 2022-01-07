//
// Created by foobles on 12/19/2021.
//

#ifndef RENDER_GRAPHICS_CONTROLLER_HPP
#define RENDER_GRAPHICS_CONTROLLER_HPP

#include <algorithm>
#include "engine/prim/ivec2.hpp"
#include "engine/prim/color.hpp"


struct SDL_Renderer;
struct SDL_Window;

namespace engine {
    class Graphics;

    class GraphicsController {
    public:
        explicit GraphicsController(Graphics &graphics) noexcept;
        GraphicsController(GraphicsController const &) = delete;
        GraphicsController &operator=(GraphicsController const &) = delete;
        GraphicsController(GraphicsController &&) = delete;
        GraphicsController &operator=(GraphicsController &&) = delete;

        void set_color(Rgba24Color color);
        void draw_pixel(IVec2 pos);

        [[nodiscard]] int get_window_width() const;
        [[nodiscard]] int get_window_height() const;

        void draw_line(IVec2 p0, IVec2 p1);

        template<typename F>
        void draw_tri(IVec2 p0, IVec2 p1, IVec2 p2, F render_point);

    private:
        static inline int tri_det(IVec2 p0, IVec2 p1, IVec2 p2) noexcept {
            return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
        }

        SDL_Renderer *renderer;
        SDL_Window *window;
    };


    template<typename F>
    void GraphicsController::draw_tri(IVec2 p0, IVec2 p1, IVec2 p2, F render_point) {
        int det = tri_det(p0, p1, p2);
        if (det <= 0) {
            return;
        }

        int min_x = std::max(std::min({p0.x, p1.x, p2.x}), 0);
        int max_x = std::min(std::max({p0.x, p1.x, p2.x}), get_window_width()-1);
        int min_y = std::max(std::min({p0.y, p1.y, p2.y}), 0);
        int max_y = std::min(std::max({p0.y, p1.y, p2.y}), get_window_height() - 1);

        int d_row0 = (p2.x - p1.x);
        int d_row1 = (p0.x - p2.x);
        int d_row2 = (p1.x - p0.x);

        int d_col0 = (p1.y - p2.y);
        int d_col1 = (p2.y - p0.y);
        int d_col2 = (p0.y - p1.y);


        IVec2 pos = {min_x, min_y};
        int row_a0 = tri_det(p1, p2, pos);
        int row_a1 = tri_det(p2, p0, pos);
        int row_a2 = tri_det(p0, p1, pos);

        for (; pos.y <= max_y; ++pos.y) {
            int a0 = row_a0;
            int a1 = row_a1;
            int a2 = row_a2;

            for (; pos.x <= max_x; ++pos.x) {
                if ((a0 | a1 | a2) >= 0) {
                    render_point(*this, pos, det, a0, a1, a2);
                }

                a0 += d_col0;
                a1 += d_col1;
                a2 += d_col2;
            }

            row_a0 += d_row0;
            row_a1 += d_row1;
            row_a2 += d_row2;
            pos.x = min_x;
        }
    }
}

#endif //RENDER_GRAPHICS_CONTROLLER_HPP
