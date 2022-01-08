//
// Created by foobles on 1/3/2022.
//

#ifndef RENDERENGINE3D_FVEC_HPP
#define RENDERENGINE3D_FVEC_HPP

namespace engine {
    struct FVec4 {
        float x;
        float y;
        float z;
        float w;
    };

    struct FVec3 {
        float x;
        float y;
        float z;
    };

    inline FVec4 cartesian_to_homogeneous(FVec3 vec) noexcept {
        return { vec.x, vec.y, vec.z, 1.0f};
    }

    inline FVec3 homogeneous_to_cartesian(FVec4 vec) noexcept {
        return {vec.x / vec.w, vec.y / vec.w, vec.z / vec.w};
    }

    inline FVec3 operator+(FVec3 lhs, FVec3 rhs) noexcept {
        return {lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
    }

    inline FVec3 operator-(FVec3 lhs, FVec3 rhs) noexcept {
        return {lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z};
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

    inline FVec3 operator/(FVec3 lhs, float rhs) noexcept {
        return {lhs.x / rhs, lhs.y / rhs, lhs.z / rhs};
    }
}

#endif //RENDERENGINE3D_FVEC_HPP
