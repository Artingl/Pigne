#include <Debugger.h>


Debugger::Debugger(Engine*engine)
{
    this->engine = engine;
}

void Debugger::printError(char*fmt, ...)
{
	va_list args;
	va_start(args, fmt);
    printf("%s[%f] [  ERROR  ]: ", COLOR_RED, ((double)(this->engine->getEngineTime() / 1000)));
	vprintf(fmt, args);
    printf("%s\n", COLOR_DEFAULT);
	va_end(args);
}

void Debugger::printInfo(char*fmt, ...)
{
	va_list args;
	va_start(args, fmt);
    printf("%s[%f] [  INFO  ]: ", COLOR_CYAN, ((double)(this->engine->getEngineTime() / 1000)));
	vprintf(fmt, args);
    printf("%s\n", COLOR_DEFAULT);
	va_end(args);
}

void Debugger::printWarning(char*fmt, ...)
{
	va_list args;
	va_start(args, fmt);
    printf("%s[%f] [  WARNING  ]: ", COLOR_YELLOW, ((double)(this->engine->getEngineTime() / 1000)));
	vprintf(fmt, args);
    printf("%s\n", COLOR_DEFAULT);
	va_end(args);
}

void Debugger::printDebug(char*fmt, ...)
{
	va_list args;
	va_start(args, fmt);
    printf("%s[%f] [  Debug  ]: ", COLOR_WHITE, ((double)(this->engine->getEngineTime() / 1000)));
	vprintf(fmt, args);
    printf("%s\n", COLOR_DEFAULT);
	va_end(args);
}
