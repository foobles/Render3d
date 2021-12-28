//
// Created by foobles on 12/19/2021.
//

#ifndef RENDER_VEC2_HPP
#define RENDER_VEC2_HPP

namespace engine {
    struct IVec2 {
        int x;
        int y;

        inline IVec2 operator+(IVec2 other) const {
            return { x + other.x, y + other.y };
        }

        inline IVec2 operator-(IVec2 other) const {
            return { x - other.x, y - other.y };
        }

        inline IVec2 operator-() const {
            return { -x, -y };
        }
    };
}

#endif //RENDER_VEC2_HPP

