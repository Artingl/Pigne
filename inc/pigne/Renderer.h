#ifndef RENDERER_H
#define RENDERER_H

#define LineRender GL_LINES
#define RectRender GL_QUADS
#define PointRender GL_POINTS

class Engine;
class Renderer;
class Image;

#include <stdlib.h>

#include <pigne/Camera.h>
#include <pigne/Vec2.h>
#include <pigne/Vec3.h>
#include <pigne/Image.h>

#include <GL/glut.h>


/*
 * Notice: you can use this class to render small things, like GUI, etc., but it's not
 * recommended using it to draw the whole game, due to the reason of poor performance.
 * */
class Renderer {
private:
    Engine*engine;
    bool hasBegun;

public:

    /*
     * Class constructor
     * */
    Renderer(Engine*engine);

    /*
     * Should be called before any rendering. 
     * After render is completed, you must call Renderer::end method
     * */
    void begin(int type);

    /*
     * Read about Renderer::begin
     * */
    void end();

    /*
     * Will draw a rectangle on screen
     * */
    void drawRect(double x, double y, double w, double h, int color);

    /*
     * Will draw a line on screen
     * */
    void drawLine(double x0, double y0, double x1, double y1, int color);

    /*
     * Will draw an image on screen
     * */
    void drawImage(Image*img, double x, double y);

};

#endif
