#ifndef DEBUGER_H
#define DEBUGER_H

class Engine;

#include <stdarg.h>
#include <pigne/Engine.h>

class Debugger {
private:
    Engine*engine;

public:

    /*
     * Class constructor
     * */
    Debugger(Engine*engine);

    /*
     * Prints red error message in console with current engine time.
     * */
    void printError(char*fmt, ...);

    /*
     * Prints cyan info message in console with current engine time.
     * */
    void printInfo(char*fmt, ...);
    
    /*
     * Prints white debug message in console with current engine time.
     * */
    void printDebug(char*fmt, ...);

    /*
     * Prints yellow warning message in console with current engine time.
     * */
    void printWarning(char*fmt, ...);


};

#endif
