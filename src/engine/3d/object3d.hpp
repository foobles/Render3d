//
// Created by foobles on 1/9/2022.
//

#ifndef RENDERENGINE3D_OBJECT3D_HPP
#define RENDERENGINE3D_OBJECT3D_HPP

#include "engine/3d/model.hpp"
#include "engine/3d/transform.hpp"
#include "engine/media/texture.hpp"
#include "engine/prim/fmat.hpp"

namespace engine {
    struct Object3d {
        Transform trans;
        Model model;
        Texture tex;
    };
}

#endif //RENDERENGINE3D_OBJECT3D_HPP
