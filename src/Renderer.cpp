#include <pigne/Renderer.h>

Renderer::Renderer(Engine*engine)
{
    this->engine = engine;
}

void Renderer::begin(int type)
{    
    if (this->hasBegun) {
        engine->getDebugger()->printError("You must call Renderer::end before begining"); return; }
    
    glBegin(type);
    this->hasBegun = true;
}

void Renderer::end()
{
    glEnd();
    this->hasBegun = false;
}

void Renderer::drawRect(double x, double y, double w, double h, int color)
{
    if (!this->hasBegun) {
        engine->getDebugger()->printWarning("You must call Renderer::begin before any rendering"); return; }
    
	uint8_t alpha = color & 0xFF;
	uint8_t blue = (color >> 8) & 0xFF;
	uint8_t green = (color >> 16) & 0xFF;
	uint8_t red = (color >> 24) & 0xFF;

    glColor4f(red / 255.0f, green / 255.0f, blue / 255.0f, alpha / 255.0f);
    glVertex2d(x, y);
    glVertex2d(x + w, y);
    glVertex2d(x + w, y + h);
    glVertex2d(x, y + h);
}

void Renderer::drawLine(double x0, double y0, double x1, double y1, int color)
{
    if (!this->hasBegun) {
        engine->getDebugger()->printWarning("You must call Renderer::begin before any rendering"); return; }
    
	uint8_t alpha = color & 0xFF;
	uint8_t blue = (color >> 8) & 0xFF;
	uint8_t green = (color >> 16) & 0xFF;
	uint8_t red = (color >> 24) & 0xFF;

    glColor4f(red / 255.0f, green / 255.0f, blue / 255.0f, alpha / 255.0f);
    glVertex2f(x0, y0);
    glVertex2f(x1, y1);
}

void Renderer::drawImage(Image*img, double x, double y)
{
    if (!this->hasBegun) {
        engine->getDebugger()->printWarning("You must call Renderer::begin before any rendering"); return; }
    
    img->bindTexture();

    int w = img->getSize()->x;
    int h = img->getSize()->y;
    
    glTexCoord2d(0, 0);  glVertex2d(x, y);
    glTexCoord2d(1, 0);  glVertex2d(x + w, y);
    glTexCoord2d(1, 1);  glVertex2d(x + w, y + h);
    glTexCoord2d(0, 1);  glVertex2d(x, y + h);
}
