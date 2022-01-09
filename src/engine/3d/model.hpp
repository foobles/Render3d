//
// Created by foobles on 1/8/2022.
//

#ifndef RENDERENGINE3D_MODEL_HPP
#define RENDERENGINE3D_MODEL_HPP

#include <vector>
#include "engine/prim/fvec.hpp"


namespace engine {
    struct Tri {
        int v0;
        int v1;
        int v2;

        int t0;
        int t1;
        int t2;
    };

    struct Model {
        std::vector<FVec3> vertices;
        std::vector<float> tex_coords;
        std::vector<Tri> tris;
    };
}


#endif //RENDERENGINE3D_MODEL_HPP
