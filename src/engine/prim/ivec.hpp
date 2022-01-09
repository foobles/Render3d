//
// Created by foobles on 12/19/2021.
//

#ifndef RENDER_VEC2_HPP
#define RENDER_VEC2_HPP

namespace engine {
    struct IVec2 {
        int x;
        int y;
    };

    inline IVec2 operator+(IVec2 lhs, IVec2 rhs) noexcept {
        return { lhs.x + rhs.x, lhs.y + rhs.y };
    }

    inline IVec2 &operator+=(IVec2 &lhs, IVec2 rhs) noexcept {
        lhs.x += rhs.x;
        lhs.y += rhs.x;
        return lhs;
    }

    inline IVec2 operator-(IVec2 lhs, IVec2 rhs) noexcept {
        return { lhs.x - rhs.x, lhs.y - rhs.y };
    }

    inline IVec2 &operator-=(IVec2 &lhs, IVec2 rhs) noexcept {
        lhs.x -= rhs.x;
        lhs.x -= rhs.y;
        return lhs;
    }

    inline IVec2 operator-(IVec2 vec) noexcept {
        return { -vec.x, -vec.y };
    }

    inline IVec2 operator*(IVec2 lhs, int rhs) noexcept {
        return { lhs.x * rhs, lhs.y * rhs };
    }

    inline IVec2 &operator*=(IVec2 &lhs, int rhs) noexcept {
        lhs.x *= rhs;
        lhs.y *= rhs;
        return lhs;
    }

    inline IVec2 operator*(int lhs, IVec2 rhs) noexcept {
        return { lhs * rhs.x, lhs * rhs.y};
    }

    inline IVec2 operator/(IVec2 lhs, int rhs) noexcept {
        return { lhs.x / rhs, lhs.y / rhs };
    }

    inline IVec2 &operator/=(IVec2 &lhs, int rhs) noexcept {
        lhs.x /= rhs;
        lhs.y /= rhs;
        return lhs;
    }
}

#endif //RENDER_VEC2_HPP

