//
// Created by foobles on 1/3/2022.
//

#include "engine/media/texture.hpp"

#include <cstdint>
#include "SDL_surface.h"
#include "engine/assert.hpp"

using namespace engine;

Texture::Texture(char const *bmp_path) {
    SDL_Surface *loaded_surface = SDL_LoadBMP(bmp_path);
    engine_assert(loaded_surface != nullptr);

    texture = SDL_ConvertSurfaceFormat(loaded_surface, SDL_PIXELFORMAT_RGBA32, 0);
    engine_assert(texture != nullptr);

    // >:)
    int disable_rle_result = SDL_SetSurfaceRLE(texture, 0);
    engine_assert(disable_rle_result == 0);
}

Texture::~Texture() noexcept {
    if (texture != nullptr) {
        SDL_FreeSurface(texture);
    }
}

Texture::Texture(Texture &&other) noexcept :
    texture(other.texture)
{
    other.texture = nullptr;
}

Texture &Texture::operator=(Texture &&other) noexcept {
    if (texture != nullptr) {
        SDL_FreeSurface(texture);
    }

    texture = other.texture;
    other.texture = nullptr;

    return *this;
}

Rgba24Color Texture::get_color(IVec2 pos) const noexcept {
    auto pixels = reinterpret_cast<char *>(texture->pixels);
    char *row = &pixels[texture->pitch * pos.y];
    char *pixel = &row[pos.x * 4];
    return {std::uint8_t(pixel[0]), std::uint8_t(pixel[1]), std::uint8_t(pixel[2])};
}

int Texture::get_width() const noexcept {
    return texture->w;
}

int Texture::get_height() const noexcept {
    return texture->h;
}