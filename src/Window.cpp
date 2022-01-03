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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(this->position->x, this->position->y);
    glutInitWindowSize(this->size->x, this->size->y);
    glutCreateWindow(this->title);

    glutDisplayFunc(&defaultWindowHanlder);
    glutIdleFunc(&defaultWindowHanlder);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

void Window::setTitle(char*fmt)
{
    //free((void*)this->title);
    this->title = fmt;
    glutSetWindowTitle(this->title);
}

void Window::setSize(Vec2*i)
{
    free((void*)this->size);
    this->size = i;
    glutReshapeWindow(this->size->x, this->size->y);
}

void Window::setPosition(Vec2*i)
{
    free((void*)this->position);
    this->position = i;
    glutPositionWindow(this->position->x, this->position->y);
}


void defaultWindowHanlder()
{
    Engine*main = getEngineInstance();
    Window*self = main->getWindow();

    glutPostRedisplay();

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    //main->getCamera()->tick();
    glTranslatef(0, 0, 0);
    self->getUpdateHandler()();
    glPopMatrix();
    glutSwapBuffers();
    
    self->tickClock();
}
