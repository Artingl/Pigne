#ifndef CAMERA_H
#define CAMERA_H

class Engine;
class Camera;

#include <pigne/Camera.h>
#include <GL/glut.h>

class Camera {
private:
    Engine*engine;

public:

    /*
     * Class constructor
     * */
    Camera(Engine*engine);

};

#endif
