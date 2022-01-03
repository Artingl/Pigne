#include <pigne/Engine.h>

Engine*engine;

void update();

int main(int argc, char*argv[])
{
    // Initialize the Engine, create a window and show it

    engine = getEngineInstance();
    engine->initEngine(argc, argv);

    engine->getWindow()->setUpdateHandler(&update);
    engine->getWindow()->createWindow();

    return 0;
}

void update()
{
    Window*window = engine->getWindow();
    Vec2*size = window->getSize();

    engine->getDebugger()->printDebug("FPS: %d", window->getFPS());


}
