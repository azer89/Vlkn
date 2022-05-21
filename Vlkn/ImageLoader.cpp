#include "ImageLoader.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif 
#include "stb_image.h"

bool ImageLoader::GetPixels(const char* filename, int& texWidth, int& texHeight, int& texChannels, unsigned char*& out_pixels)
{
    pixels = stbi_load(filename, &texWidth, &texHeight, &texChannels, STBI_rgb_alpha);

    if (!pixels)
    {
        return false;
    }

    out_pixels = pixels;
    return true;
}

void ImageLoader::DestroyPixels()
{
    stbi_image_free(pixels);
}
