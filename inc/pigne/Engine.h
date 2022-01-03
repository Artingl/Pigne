#ifndef ENGINE_H
#define ENGINE_H

class Debugger;
class Window;

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#include <GL/glut.h>
#include <pigne/Vec2.h>
#include <pigne/Vec3.h>

#include <pigne/Timer.h>
#include <pigne/Window.h>
#include <pigne/Camera.h>
#include <pigne/Renderer.h>
#include <pigne/Debugger.h>
#include <pigne/Colors.h>

class Engine {
private:
    Debugger*debugger;
    Window*window;
    Camera*camera;
    Renderer*renderer;

    bool hasBeenInitialized;

    uint64_t startTimestamp;

public:

    /*
     * Class constructor
     * */
    Engine();

    /*
     * Glut initialization
     * */
    void initEngine(int argc, char*argv[]);

    /*
     * Will register an handler, that's going to be executed when Engine closes.
     * */
    void registerEngineExitEvent(void*exit);

    /*
     * Will return current time from the launch moment in milliseconds.
     * */
    uint64_t getEngineTime();

    /*
     * Returns engine debuger class
     * */
    Debugger*getDebugger();

    /*
     * Returns engine window class
     * */
    Window*getWindow();

    /*
     * Returns engine camera class
     * */
    Camera*getCamera();

    /*
     * Returns engine renderer class
     * */
    Renderer* getRenderer();

};

/*
 * Returns global engine instance
 * */
Engine*getEngineInstance();

#endif
