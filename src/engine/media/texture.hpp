//
// Created by foobles on 1/3/2022.
//

#ifndef RENDERENGINE3D_TEXTURE_HPP
#define RENDERENGINE3D_TEXTURE_HPP

#include <string_view>
#include "engine/prim/color.hpp"
#include "engine/prim/ivec2.hpp"

struct SDL_Surface;

namespace engine {

    class Texture {
    public:
        explicit Texture(char const *bmp_path);
        ~Texture() noexcept;

        Texture(Texture const &other) = delete;
        Texture &operator=(Texture const &other) = delete;
        Texture(Texture &&other) noexcept;
        Texture &operator=(Texture &&other) noexcept;

        [[nodiscard]] Rgba24Color get_color(IVec2 pos) const noexcept;

        [[nodiscard]] int get_width() const noexcept;
        [[nodiscard]] int get_height() const noexcept;
    private:
        SDL_Surface *texture;
    };
}



#endif //RENDERENGINE3D_TEXTURE_HPP
