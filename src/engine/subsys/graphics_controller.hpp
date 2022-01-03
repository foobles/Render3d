//
// Created by foobles on 12/19/2021.
//

#ifndef RENDER_GRAPHICS_CONTROLLER_HPP
#define RENDER_GRAPHICS_CONTROLLER_HPP

#include <utility>
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

        void setColor(Rgba24Color color);
        void drawPixel(IVec2 pos);

        [[nodiscard]] int get_window_width() const;
        [[nodiscard]] int get_window_height() const;

        void drawLine(IVec2 p0, IVec2 p1);

        template<typename VertexT, typename F>
        void drawTri(IVec2 p0, IVec2 p1, IVec2 p2, VertexT v0, VertexT v1, VertexT v2, F render_point);

    private:
        template<typename VertexT, typename F>
        void draw_scanline(int left, int right, VertexT left_vert, VertexT right_vert, int y, F &render_point);

        static int round_down(float f) { return static_cast<int>(f); }
        static float slope(int start, int end, int steps);

        SDL_Renderer *renderer;
        SDL_Window *window;
    };


    template<typename VertexT, typename F>
    void GraphicsController::drawTri(IVec2 p0, IVec2 p1, IVec2 p2, VertexT v0, VertexT v1, VertexT v2, F render_point) {
        VertexT vertices[3] = {std::move(v0), std::move(v1), std::move(v2)};
        IVec2 points[3] = {p0, p1, p2};
        int top, mid, bot;
        if (p0.y < p1.y) {
            if (p1.y < p2.y) {
                top = 0;
                mid = 1;
                bot = 2;
            } else if (p0.y < p2.y) {
                top = 0;
                mid = 2;
                bot = 1;
            } else {
                top = 2;
                mid = 0;
                bot = 1;
            }
        } else {
            if (p1.y < p2.y) {
                if (p0.y < p2.y) {
                    top = 1;
                    mid = 0;
                    bot = 2;
                } else {
                    top = 1;
                    mid = 2;
                    bot = 0;
                }
            } else {
                top = 2;
                mid = 1;
                bot = 0;
            }
        }

        bool mid_left = (points[mid].x - points[top].x)*(points[bot].y - points[top].y) < (points[mid].y - points[top].y)*(points[bot].x - points[top].x);

        int l_height = points[bot].y - points[top].y;
        int t_height = points[mid].y - points[top].y;
        int b_height = points[bot].y - points[mid].y;

        float l_slope = slope(points[top].x, points[bot].x, l_height);
        float t_slope = slope(points[top].x, points[mid].x, t_height);
        float b_slope = slope(points[mid].x, points[bot].x, b_height);

        auto cur_l_x = float(points[top].x);
        auto cur_t_x = float(points[top].x);
        auto cur_b_x = float(points[mid].x);

        auto l_interp_slope = 1.0f / float(l_height);
        auto t_interp_slope = 1.0f / float(t_height);
        auto b_interp_slope = 1.0f / float(b_height);

        float cur_l_interp = 0.0;
        float cur_t_interp = 0.0;
        float cur_b_interp = 0.0;

        if (mid_left) {
            for (int y = points[top].y; y < points[mid].y; ++y) {
                int left_x = round_down(cur_t_x);
                VertexT left_v = vertices[top].interp(vertices[mid], cur_t_interp);
                int right_x = round_down(cur_l_x);
                VertexT right_v = vertices[top].interp(vertices[bot], cur_l_interp);

                draw_scanline(left_x, right_x, left_v, right_v, y, render_point);

                cur_t_x += t_slope;
                cur_l_x += l_slope;
                cur_t_interp += t_interp_slope;
                cur_l_interp += l_interp_slope;
            }

            VertexT mid_right_v = vertices[top].interp(vertices[bot], cur_l_interp);
            draw_scanline(points[mid].x, round_down(cur_l_x), vertices[mid], mid_right_v, points[mid].y, render_point);

            for (int y = points[mid].y + 1; y <= points[bot].y; ++y) {
                cur_b_x += b_slope;
                cur_l_x += l_slope;
                cur_b_interp += b_interp_slope;
                cur_l_interp += l_interp_slope;

                int left_x = round_down(cur_b_x);
                VertexT left_v = vertices[mid].interp(vertices[bot], cur_b_interp);
                int right_x = round_down(cur_l_x);
                VertexT right_v = vertices[top].interp(vertices[bot], cur_l_interp);

                draw_scanline(left_x, right_x, left_v, right_v, y, render_point);
            }
        } else {
            for (int y = points[top].y; y < points[mid].y; ++y) {
                int left_x = round_down(cur_l_x);
                VertexT left_v = vertices[top].interp(vertices[bot], cur_l_interp);
                int right_x = round_down(cur_t_x);
                VertexT right_v = vertices[top].interp(vertices[mid], cur_t_interp);

                draw_scanline(left_x, right_x, left_v, right_v, y, render_point);

                cur_l_x += l_slope;
                cur_t_x += t_slope;
                cur_l_interp += l_interp_slope;
                cur_t_interp += t_interp_slope;
            }

            VertexT mid_left_v = vertices[top].interp(vertices[bot], cur_l_interp);
            draw_scanline(round_down(cur_l_x), points[mid].x, mid_left_v, vertices[mid], points[mid].y, render_point);

            for (int y = points[mid].y + 1; y <= points[bot].y; ++y) {
                cur_l_x += l_slope;
                cur_b_x += b_slope;
                cur_l_interp += l_interp_slope;
                cur_b_interp += b_interp_slope;

                int left_x = round_down(cur_l_x);
                VertexT left_v = vertices[top].interp(vertices[bot], cur_l_interp);
                int right_x = round_down(cur_b_x);
                VertexT right_v = vertices[mid].interp(vertices[bot], cur_b_interp);

                draw_scanline(left_x, right_x, left_v, right_v, y, render_point);
            }
        }
    }

    template<typename VertexT, typename F>
    void GraphicsController::draw_scanline(int left, int right, VertexT left_vert, VertexT right_vert, int y, F &render_point) {
        int dist = right - left;
        float cur_interp = 0.0;
        float slope = 1.0f / float(dist);
        for (int x = left; x <= right; ++x) {
            VertexT v = left_vert.interp(right_vert, cur_interp);
            render_point(*this, IVec2{x, y}, v);
            cur_interp += slope;
        }
    }

}

#endif //RENDER_GRAPHICS_CONTROLLER_HPP
