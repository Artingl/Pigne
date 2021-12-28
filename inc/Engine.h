#ifndef ENGINE_H
#define ENGINE_H

class Debugger;

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <Timer.h>
#include <Debugger.h>
#include <Colors.h>

class Engine {
private:
    Debugger*debugger;
    uint64_t startTimestamp;

public:

    /*
     * Class constructor
     * */
    Engine();

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

};

#endif
