//
// Created by foobles on 1/9/2022.
//

#include "engine/3d/transform.hpp"


#include <cmath>

using namespace engine;

Transform::Transform(engine::FVec3 pos, engine::FVec3 rot, engine::FVec3 scale) noexcept :
    pos(pos),
    rot(rot),
    scale(scale),
    needs_recompute(false),
    matrix()
{}

Transform::Transform(FVec3 pos, FVec3 rot) noexcept :
    Transform(pos, rot, {1, 1, 1})
{}


void Transform::recompute_matrix() noexcept {
    using std::sin;
    using std::cos;
    FMat4 scale_mat = {{
        {scale.x, 0,       0,       0},
        {0,       scale.y, 0,       0},
        {0,       0,       scale.z, 0},
        {0,       0,       0,       1}
    }};

    FMat4 rot_x_mat = {{
        {1, 0,           0,          0},
        {0, cos(rot.x),  sin(rot.x), 0},
        {0, -sin(rot.x), cos(rot.x), 0},
        {0, 0,           0,          1}
    }};
    FMat4 rot_y_mat = {{
        {cos(rot.y),  0, sin(rot.y), 0},
        {0,           1, 0,          0},
        {-sin(rot.y), 0, cos(rot.y), 0},
        {0,           0, 0,          1}
    }};
    FMat4 rot_z_mat = {{
        {cos(rot.z),  sin(rot.z), 0, 0},
        {-sin(rot.z), cos(rot.z), 0, 0},
        {0,           0,          1, 0},
        {0,           0,          0, 1}
    }};

    FMat4 translate_mat = {{
        {1,     0,     0,     0},
        {0,     1,     0,     0},
        {0,     0,     1,     0},
        {pos.x, pos.y, pos.z, 1}
    }};

    matrix = scale_mat * rot_x_mat * rot_y_mat * rot_z_mat * translate_mat;
}

void Transform::update_matrix() noexcept {
    if (needs_recompute) {
        recompute_matrix();
        needs_recompute = false;
    }
}

FVec3 Transform::get_pos() const noexcept {
    return pos;
}

void Transform::set_pos(FVec3 new_pos) noexcept {
    pos = new_pos;
    needs_recompute = true;
}

void Transform::modify_pos(FVec3 delta) noexcept {
    pos += delta;
    needs_recompute = true;
}

FVec3 Transform::get_rot() const noexcept {
    return rot;
}

void Transform::set_rot(FVec3 new_rot) noexcept {
    rot = new_rot;
    needs_recompute = true;
}

void Transform::modify_rot(FVec3 delta) noexcept {
    rot += delta;
    needs_recompute = true;
}

FVec3 Transform::get_scale() const noexcept {
    return scale;
}

void Transform::set_scale(FVec3 new_scale) noexcept {
    scale = new_scale;
    needs_recompute = true;
}

void Transform::modify_scale(FVec3 delta) noexcept {
    scale += delta;
    needs_recompute = true;
}

FMat4 Transform::get_matrix() const noexcept {
    return matrix;
}

