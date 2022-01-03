#ifndef WINDOW_H
#define WINDOW_H

class Engine;
class Window;

typedef void (*windowUpdateHandler)();

#include <stdarg.h>
#include <stdlib.h>

#include <pigne/Engine.h>
#include <GL/glut.h>

class Window {
private:
    Engine*engine;

    uint64_t last_fps_timer;
    uint32_t fps_counter;
    uint32_t fps;

    const char* title;
    Vec2*size;
    Vec2*position;
    windowUpdateHandler updateHandler;

public:

    /*
     * Class constructor
     * */
    Window(Engine*engine);
    
    /*
     * Sets new window update handler
     * */
    void setUpdateHandler(windowUpdateHandler handler);

    /*
     * Shows window
     * */
    void createWindow();

    /*
     * Updates current fps count
     * */
    void tickClock();

    /*
     * Draws framebuffer onto screen
     * */
    void drawFramebuffer();

    /*
     * Changes current window title
     * */
    void setTitle(char*fmt);
    
    /*
     * Changes current window size
     * */
    void setSize(Vec2*i);

    /*
     * Changes current window position
     * */
    void setPosition(Vec2*i);

    /*
     * Returns current window update handler
     * */
    windowUpdateHandler getUpdateHandler();

    /*
     * Returns current window position
     * */
    Vec2*getPosition();

    /*
     * Returns current window size
     * */
    Vec2*getSize();

    /*
     * Returns current fps value
     * */
    uint32_t getFPS();

};

void defaultWindowHanlder();

#endif
