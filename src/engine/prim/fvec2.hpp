//
// Created by foobles on 1/3/2022.
//

#ifndef RENDERENGINE3D_FVEC2_HPP
#define RENDERENGINE3D_FVEC2_HPP

namespace engine {
    struct FVec2 {
        float x;
        float y;
    };

    inline FVec2 operator+(FVec2 lhs, FVec2 rhs) noexcept {
        return {lhs.x + rhs.x, lhs.y + rhs.y};
    }

    inline FVec2 operator-(FVec2 lhs, FVec2 rhs) noexcept {
        return {lhs.x - rhs.x, lhs.y - rhs.y};
    }

    inline FVec2 operator-(FVec2 vec) noexcept {
        return {-vec.x, -vec.y};
    }

    inline FVec2 operator*(float lhs, FVec2 rhs) noexcept {
        return {lhs * rhs.x, lhs * rhs.y};
    }

    inline FVec2 operator*(FVec2 lhs, float rhs) noexcept {
        return {lhs.x * rhs, lhs.y * rhs};
    }

    inline FVec2 operator/(FVec2 lhs, float rhs) noexcept {
        return {lhs.x / rhs, lhs.y / rhs};
    }
}

#endif //RENDERENGINE3D_FVEC2_HPP
