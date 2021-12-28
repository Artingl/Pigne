#include <Engine.h>

Engine::Engine()
{
    this->debugger = new Debugger(this);
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
