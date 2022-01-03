#include <pigne/Engine.h>


Engine*getEngineInstance()
{
    static Engine*engine;
    if (engine == NULL) engine = new Engine();
    return engine;
}

Engine::Engine()
{
    this->debugger = new Debugger(this);
    this->window = new Window(this);
    this->camera = new Camera(this);
}

void Engine::initEngine(int argc, char*argv[])
{
    glutInit(&argc, argv);
}

void Engine::registerEngineExitEvent(void*exit)
{
    
}

uint64_t Engine::getEngineTime()
{
    if (this->startTimestamp == 0)
        this->startTimestamp = T_getTimestamp();
    
    return T_getTimestamp() - this->startTimestamp;
}

Debugger* Engine::getDebugger()
{
    return this->debugger;
}

Window* Engine::getWindow()
{
    return this->window;
}

Camera* Engine::getCamera()
{
    return this->camera;
}
