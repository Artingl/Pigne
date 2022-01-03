#include <pigne/Engine.h>

void update();
void drawCubeLegacy(Vec3* position);

int main(int argc, char*argv[])
{
    // Initialize the Engine, create a window and show it

    Engine*engine = getEngineInstance();
    engine->initEngine(argc, argv);

    engine->getWindow()->setSize(new Vec2(868, 568));
    engine->getWindow()->setUpdateHandler(&update);
    engine->getWindow()->createWindow();

    return 0;
}

void update()
{
    Window*window = getEngineInstance()->getWindow();
    Camera*camera = getEngineInstance()->getCamera();
    Renderer*renderer = getEngineInstance()->getRenderer();
    Vec2*size = window->getSize();

    char*title = (char*)calloc(16, sizeof(char));
    sprintf(title, "FPS: %d", window->getFPS());
    window->setTitle(title);

    /* set camera perspective and position */
    camera->orthographic(0, size->x, size->y, 0, -1, 1);

    /* rendering */
    renderer->begin();
    renderer->drawRect(100, 10, 200, 150, 0xFF0000FF);
    renderer->drawRect(0, 0, 200, 150, 0x0000FFAA);
    renderer->end();

}
