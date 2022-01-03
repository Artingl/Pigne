#ifndef CAMERA_H
#define CAMERA_H

class Engine;
class Camera;

#include <stdlib.h>

#include <pigne/Engine.h>
#include <pigne/Vec2.h>
#include <pigne/Vec3.h>

//#include <GL/glu.h>
#include <GL/glut.h>

class Camera {
private:
    Engine*engine;

    Vec3*position;
    Vec3*rotation;

public:

    /*
     * Class constructor
     * */
    Camera(Engine*engine);

    /*
     * Stes camera position
     * */
    void setPosition(Vec3*i);

    /*
     * Sets camera rotation
     * */
    void setRotation(Vec3*i);

    /*
     * Sets perspective camera
     * */
    void perspective(double FOV, double aspect, double zNear, double renderDistance);

    /*
     * Sets orthographic camera
     * */
    void orthographic(double left, double right, double bottom, double top, double zNear, double zFar);

};

#endif
