#include <Engine.h>

int main()
{
    Engine*engine = new Engine();
    
    engine->getDebugger()->printInfo("Hello, World!");

    return 0;
}
