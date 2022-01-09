//
// Created by foobles on 1/3/2022.
//

#ifndef RENDERENGINE3D_FVEC_HPP
#define RENDERENGINE3D_FVEC_HPP

namespace engine {
    struct FVec2 {
        float x;
        float y;
    };

    struct FVec3 {
        float x;
        float y;
        float z;
    };

    struct FVec4 {
        float x;
        float y;
        float z;
        float w;
    };


    inline FVec2 operator+(FVec2 lhs, FVec2 rhs) noexcept {
        return {lhs.x + rhs.x, lhs.y + rhs.y};
    }

    inline FVec2 &operator+=(FVec2 &lhs, FVec2 rhs) noexcept {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        return lhs;
    }

    inline FVec2 operator-(FVec2 lhs, FVec2 rhs) noexcept {
        return {lhs.x - rhs.x, lhs.y - rhs.y};
    }

    inline FVec2 &operator-=(FVec2 &lhs, FVec2 rhs) noexcept {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        return lhs;
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

    inline FVec2 &operator*=(FVec2 &lhs, float rhs) noexcept {
        lhs.x *= rhs;
        lhs.y *= rhs;
        return lhs;
    }

    inline FVec2 operator/(FVec2 lhs, float rhs) noexcept {
        return {lhs.x / rhs, lhs.y / rhs};
    }

    inline FVec2 &operator/=(FVec2 &lhs, float rhs) noexcept {
        lhs.x /= rhs;
        lhs.y /= rhs;
        return lhs;
    }

    inline FVec4 cartesian_to_homogeneous(FVec3 vec) noexcept {
        return { vec.x, vec.y, vec.z, 1.0f};
    }

    inline FVec3 homogeneous_to_cartesian(FVec4 vec) noexcept {
        return {vec.x / vec.w, vec.y / vec.w, vec.z / vec.w};
    }

    inline FVec3 operator+(FVec3 lhs, FVec3 rhs) noexcept {
        return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
    }

    inline FVec3 &operator+=(FVec3 &lhs, FVec3 rhs) noexcept {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;
        return lhs;
    }

    inline FVec3 operator-(FVec3 lhs, FVec3 rhs) noexcept {
        return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
    }

    inline FVec3 &operator-=(FVec3 &lhs, FVec3 rhs) noexcept {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        lhs.z -= rhs.z;
        return lhs;
    }

    inline FVec3 operator-(FVec3 vec) noexcept {
        return {-vec.x, -vec.y, -vec.z};
    }

    inline FVec3 operator*(float lhs, FVec3 rhs) noexcept {
        return {lhs * rhs.x, lhs * rhs.y, lhs * rhs.z};
    }

    inline FVec3 operator*(FVec3 lhs, float rhs) noexcept {
        return {lhs.x * rhs, lhs.y * rhs, lhs.z * rhs};
    }

    inline FVec3 &operator*=(FVec3 &lhs, float rhs) noexcept {
        lhs.x *= rhs;
        lhs.y *= rhs;
        lhs.z *= rhs;
        return lhs;
    }

    inline FVec3 operator/(FVec3 lhs, float rhs) noexcept {
        return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
    }

    inline FVec3 &operator/=(FVec3 &lhs, float rhs) noexcept {
        lhs.x /= rhs;
        lhs.y /= rhs;
        lhs.z /= rhs;
        return lhs;
    }
}

#endif //RENDERENGINE3D_FVEC_HPP
