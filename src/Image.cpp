#include <pigne/Image.h>

using namespace cimg_library; 


Image::Image(char*path, bool forceLoading)
{
    this->path = path;
    this->textureId = -1;

    if (forceLoading)
        this->load();

}

void Image::load()
{
    if (this->loaded) {
        getEngineInstance()->getDebugger()->printError("Image %s has already been loaded", this->path); return; }
    this->loaded = true;

    if (access( this->path, F_OK ) != 0)
    {
        getEngineInstance()->getDebugger()->printError("Image with path %s doesn't exist!", this->path);
        delete this;
    }

    CImg<unsigned char> image(this->path);
    this->size = new Vec2(image._width, image._height);

    int s = this->size->x*this->size->y*3;
    this->buffer = new uint8_t[s];

    for (int i = 0; i < s;i+=3) {
        this->buffer[i] = 0xFF;
        this->buffer[i + 1] = 0xFF;
        this->buffer[i + 2] = 0x00;
    }
}

void Image::bindTexture()
{
    if (this->textureId == -1)
    {
        GLuint tex;
        glGenTextures(1, &tex);
        this->textureId = tex;

        glBindTexture(GL_TEXTURE_2D, this->textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->size->x, this->size->y, 0, GL_BGR, GL_UNSIGNED_BYTE, this->buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    }
    else glBindTexture(GL_TEXTURE_2D, this->textureId);
}

Vec2*Image::getSize()
{
    return this->size;
}

uint8_t*Image::getBuffer()
{
    return this->buffer;
}
