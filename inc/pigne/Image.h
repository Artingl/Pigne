#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define cimg_display 0  // look at pigne/CImg.h, line 371

#include <pigne/CImg.h>
#include <pigne/Vec2.h>
#include <pigne/Engine.h>

class Image {
private:
    int textureId;

    bool loaded;
    char*path;

    Vec2*size;
    uint8_t*buffer;

public:

    /*
     * Class cunstructor
     * */
    Image(char*path, bool forceLoading=true);

    /*
     * Will load the image if it hasn't
     * */
    void load();

    /*
     * Will bind this image as an texture
     * */
    void bindTexture();

    /*
     * Returns image size
     * */
    Vec2*getSize();
    /*
     * Returns image buffer
     * */
    uint8_t*getBuffer();

};
