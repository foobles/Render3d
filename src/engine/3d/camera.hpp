//
// Created by foobles on 1/8/2022.
//

#ifndef RENDERENGINE3D_CAMERA_HPP
#define RENDERENGINE3D_CAMERA_HPP

#include "engine/prim/fvec.hpp"
#include "engine/prim/fmat.hpp"

namespace engine {
    class Camera {
    public:
    public:
        Camera(FVec3 pos, FVec3 rot, float fov) noexcept;

        [[nodiscard]] FVec3 get_pos() const noexcept;
        void set_pos(FVec3 new_pos) noexcept;
        void modify_pos(FVec3 delta) noexcept;

        [[nodiscard]] FVec3 get_rot() const noexcept;
        void set_rot(FVec3 new_rot) noexcept;
        void modify_rot(FVec3 delta) noexcept;

        [[nodiscard]] FMat4 get_matrix() const noexcept;

        void update_matrix() noexcept;

    private:
        void recompute_matrix() noexcept;

        FVec3 pos;
        FVec3 rot;
        float fov;
        bool needs_recompute;
        FMat4 matrix;
    };
}

#endif //RENDERENGINE3D_CAMERA_HPP
