#include <pigne/Renderer.h>

Renderer::Renderer(Engine*engine)
{
    this->engine = engine;
}

void Renderer::begin()
{
    glBegin(GL_QUADS);
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
        engine->getDebugger()->printError("You must call Renderer::begin before any rendering"); return; }
    
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
