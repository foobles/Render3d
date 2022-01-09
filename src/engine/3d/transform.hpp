//
// Created by foobles on 1/9/2022.
//

#ifndef RENDERENGINE3D_TRANSFORM_HPP
#define RENDERENGINE3D_TRANSFORM_HPP

#include "engine/prim/fmat.hpp"
#include "engine/prim/fvec.hpp"

namespace engine {
    class Transform {
    public:
        Transform(FVec3 pos, FVec3 rot, FVec3 scale) noexcept;
        Transform(FVec3 pos, FVec3 rot) noexcept;

        [[nodiscard]] FVec3 get_pos() const noexcept;
        void set_pos(FVec3 new_pos) noexcept;
        void modify_pos(FVec3 delta) noexcept;

        [[nodiscard]] FVec3 get_rot() const noexcept;
        void set_rot(FVec3 new_rot) noexcept;
        void modify_rot(FVec3 delta) noexcept;

        [[nodiscard]] FVec3 get_scale() const noexcept;
        void set_scale(FVec3 new_scale) noexcept;
        void modify_scale(FVec3 delta) noexcept;


        void update_matrix() noexcept;
        [[nodiscard]] FMat4 get_matrix() const noexcept;

    private:
        void recompute_matrix() noexcept;

        FVec3 pos;
        FVec3 rot;
        FVec3 scale;
        bool needs_recompute;
        FMat4 matrix;

    };
}


#endif //RENDERENGINE3D_TRANSFORM_HPP
