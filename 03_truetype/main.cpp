#include "kato/truetype.hpp"
#include "kato/function.hpp"

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstdint>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include <algorithm>

constexpr uint32_t IMG_WIDTH = 512, IMG_HEIGHT = 512, CHANNELS = 1;
float COLOR = 100, MIN_PX = 0, MAX_PX = 255;

int main()
{
    kato::TrueTypeFont ttf("ProggyClean.ttf");

    COLOR = 64.0;
    MAX_PX = 255.0;
    std::vector<uint8_t> image_uint8_t(IMG_WIDTH * IMG_HEIGHT, 0);
    ttf.renderText(image_uint8_t, IMG_WIDTH, IMG_HEIGHT, 50, 100, "Hello Proggy", COLOR, MAX_PX, MIN_PX);
    ttf.renderText(image_uint8_t, IMG_WIDTH, IMG_HEIGHT, 50, 200, kato::function::TimeStampString(3, "%H:%M:%S").c_str(), COLOR, MAX_PX, MIN_PX);
    stbi_write_png("image_uint8_t.png", IMG_WIDTH, IMG_HEIGHT, CHANNELS, image_uint8_t.data(), IMG_WIDTH);

    COLOR = 65535.0/10.0;
    MAX_PX = 65535.0;
    std::vector<uint16_t> image_uint16_t(IMG_WIDTH * IMG_HEIGHT, 0);
    ttf.renderText(image_uint16_t, IMG_WIDTH, IMG_HEIGHT, 50, 100, "Hello Proggy", COLOR, MAX_PX, MIN_PX);
    ttf.renderText(image_uint16_t, IMG_WIDTH, IMG_HEIGHT, 50, 200, kato::function::TimeStampString(3, "%H:%M:%S").c_str(), COLOR, MAX_PX, MIN_PX);
    // since stbi_write_png works only with 8-bit images
    for (uint i = 0; i < IMG_WIDTH * IMG_HEIGHT; ++i)
        image_uint8_t[i] = static_cast<uint8_t>(255.0*image_uint16_t[i]/MAX_PX);
    stbi_write_png("image_uint16_t.png", IMG_WIDTH, IMG_HEIGHT, CHANNELS, image_uint8_t.data(), IMG_WIDTH);

    COLOR = 0.2;
    MAX_PX = 1.0;
    std::vector<float> image_float(IMG_WIDTH * IMG_HEIGHT, 0);
    ttf.renderText(image_float, IMG_WIDTH, IMG_HEIGHT, 50, 100, "Hello Proggy", COLOR, MAX_PX, MIN_PX);
    ttf.renderText(image_float, IMG_WIDTH, IMG_HEIGHT, 50, 200, kato::function::TimeStampString(3, "%H:%M:%S").c_str(), COLOR, MAX_PX, MIN_PX);
    // since stbi_write_png works only with 8-bit images
    for (uint i = 0; i < IMG_WIDTH * IMG_HEIGHT; ++i)
        image_uint8_t[i] = static_cast<uint8_t>(255.0*image_float[i]/MAX_PX);
    stbi_write_png("image_float.png", IMG_WIDTH, IMG_HEIGHT, CHANNELS, image_uint8_t.data(), IMG_WIDTH);

    return 0;
}
