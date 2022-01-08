//
// Created by foobles on 1/3/2022.
//

#ifndef RENDERENGINE3D_FMAT_HPP
#define RENDERENGINE3D_FMAT_HPP

#include "engine/prim/fvec.hpp"

namespace engine {
    struct FMat4 {
        float rows[4][4];
    };

    inline FMat4 operator*(FMat4 lhs, FMat4 rhs) noexcept {
        float (*a)[4] = lhs.rows;
        float (*b)[4] = rhs.rows;
        FMat4 ret{};
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                ret.rows[i][j] =
                        (a[i][0] * b[0][j])
                        + (a[i][1] * b[1][j])
                        + (a[i][2] * b[2][j])
                        + (a[i][3] * b[3][j]);
            }
        }
        return ret;
    }

    inline FVec4 operator*(FVec4 lhs, FMat4 rhs) noexcept {
        FVec4 a = lhs;
        float (*b)[4] = rhs.rows;
        return {
            .x = (a.x * b[0][0]) + (a.y * b[1][0]) + (a.z * b[2][0]) + (a.w * b[3][0]),
            .y = (a.x * b[0][1]) + (a.y * b[1][1]) + (a.z * b[2][1]) + (a.w * b[3][1]),
            .z = (a.x * b[0][2]) + (a.y * b[1][2]) + (a.z * b[2][2]) + (a.w * b[3][2]),
            .w = (a.x * b[0][3]) + (a.y * b[1][3]) + (a.z * b[2][3]) + (a.w * b[3][3]),
        };
    }
}

#endif //RENDERENGINE3D_FMAT_HPP
