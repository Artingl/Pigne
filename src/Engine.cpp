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
    this->renderer = new Renderer(this);

    this->hasBeenInitialized = false;
}

void Engine::initEngine(int argc, char*argv[])
{
    glutInit(&argc, argv);
    this->hasBeenInitialized = true;
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
    if (!this->hasBeenInitialized)
        this->getDebugger()->printError("Before doing any rendering stuff you must initialize the engine by calling Engine::initEngine method!"), 
        exit(0);

    return this->window;
}

Camera* Engine::getCamera()
{
    if (!this->hasBeenInitialized)
        this->getDebugger()->printError("Before doing any rendering stuff you must initialize the engine by calling Engine::initEngine method!"), 
        exit(0);

    return this->camera;
}

Renderer* Engine::getRenderer()
{
    if (!this->hasBeenInitialized)
        this->getDebugger()->printError("Before doing any rendering stuff you must initialize the engine by calling Engine::initEngine method!"), 
        exit(0);

    return this->renderer;
}
