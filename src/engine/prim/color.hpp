//
// Created by foobles on 12/19/2021.
//

#ifndef RENDER_COLOR_HPP
#define RENDER_COLOR_HPP

#include <cstdint>


namespace engine {
    struct RgbaColor {
        RgbaColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) noexcept :
            r(r),
            g(g),
            b(b),
            a(a)
        {}

        RgbaColor(std::uint8_t r, std::uint8_t g, std::uint8_t b) noexcept :
                r(r),
                g(g),
                b(b),
                a(255)
        {}

        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
        std::uint8_t a;
    };
}

#endif //RENDER_COLOR_HPP
