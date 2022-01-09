//
// Created by foobles on 1/8/2022.
//

#include "engine/3d/camera.hpp"

#include <cmath>

using namespace engine;

Camera::Camera(engine::FVec3 pos, engine::FVec3 rot, float fov) noexcept :
        pos(pos),
        rot(rot),
        fov(fov),
        matrix{}
{
    recompute_matrix();
}


void Camera::recompute_matrix() noexcept {
    using std::sin;
    using std::cos;
    using std::tan;

    float inverse_tan_half_fov = 1.0f / tanf(fov * 0.5f);
    FMat4 translation = {{
        {1,      0,      0,      0},
        {0,      1,      0,      0},
        {0,      0,      1,      0},
        {-pos.x, -pos.y, -pos.z, 1}
    }};
    FMat4 rot_x_axis = {{
        {1, 0,          0,           0},
        {0, cos(rot.x), -sin(rot.x), 0},
        {0, sin(rot.x), cos(rot.x),  0},
        {0, 0,          0,           1}
    }};
    FMat4 rot_y_axis = {{
        {cos(rot.y), 0, -sin(rot.y), 0},
        {0,          1, 0,           0},
        {sin(rot.y), 0, cos(rot.y),  0},
        {0,          0, 0,           1}
    }};
    FMat4 rot_z_axis = {{
        {cos(rot.z), -sin(rot.z), 0, 0},
        {sin(rot.z), cos(rot.z),  0, 0},
        {0,          0,           1, 0},
        {0,          0,           0, 1}
    }};
    FMat4 fov_transform = {{
        {inverse_tan_half_fov, 0,                    0, 0},
        {0,                    inverse_tan_half_fov, 0, 0},
        {0,                    0,                    1, 0},
        {0,                    0,                    0, 1}
    }};

    matrix = translation * rot_x_axis * rot_y_axis * rot_z_axis * fov_transform;
}

FMat4 Camera::get_matrix() const noexcept {
    return matrix;
}

FVec3 Camera::get_pos() const noexcept {
    return pos;
}

void Camera::set_pos(FVec3 new_pos) noexcept {
    pos = new_pos;
    needs_recompute = true;
}

void Camera::modify_pos(FVec3 delta) noexcept {
    pos += delta;
    needs_recompute = true;
}

FVec3 Camera::get_rot() const noexcept {
    return rot;
}

void Camera::set_rot(FVec3 new_rot) noexcept {
    rot = new_rot;
    needs_recompute = true;
}

void Camera::modify_rot(FVec3 delta) noexcept {
    rot += delta;
    needs_recompute = true;
}

void Camera::update_matrix() noexcept {
    if (needs_recompute) {
        recompute_matrix();
        needs_recompute = false;
    }
}
