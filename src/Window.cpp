#include <pigne/Window.h>

Window::Window(Engine*engine)
{
    this->engine = engine;

    this->title = "Pigne";
    this->size = new Vec2(640, 480);
    this->position = new Vec2(100, 100);

    this->fps = 0;
    this->fps_counter = 0;
}

void Window::createWindow()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(this->position->x, this->position->y);
    glutInitWindowSize(this->size->x, this->size->y);

    glutCreateWindow(this->title);

    glutDisplayFunc(&defaultWindowHanlder);
    glutIdleFunc(&defaultWindowHanlder);
    glutMainLoop();
}

void Window::setUpdateHandler(windowUpdateHandler handler)
{
    this->updateHandler = handler;
}

windowUpdateHandler Window::getUpdateHandler()
{
    return this->updateHandler;
}

void Window::tickClock()
{
    this->fps_counter++;
    if (this->last_fps_timer == 0) 
        this->last_fps_timer = T_getTimestamp();
    
    if (this->last_fps_timer + 1000 < T_getTimestamp())
    {
        this->fps = this->fps_counter;
        this->fps_counter = 0;
        this->last_fps_timer = T_getTimestamp();
    }
}

Vec2*Window::getPosition()
{
    return this->position;
}

Vec2*Window::getSize()
{
    return this->size;
}

uint32_t Window::getFPS()
{
    return this->fps;
}


void defaultWindowHanlder()
{
    Engine*main = getEngineInstance();
    Window*self = main->getWindow();

    self->getUpdateHandler()();
    self->tickClock();
}
