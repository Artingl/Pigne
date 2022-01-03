#ifndef RENDERER_H
#define RENDERER_H

class Engine;
class Renderer;

#include <stdlib.h>

#include <pigne/Camera.h>
#include <pigne/Vec2.h>
#include <pigne/Vec3.h>

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
    void begin();

    /*
     * Read about Renderer::begin
     * */
    void end();


    /* 2d rendering */

    /*
     * Will draw a rectangle on screen
     * */
    void drawRect(double x, double y, double w, double h, int color);

};

#endif
