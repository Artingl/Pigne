#ifndef TIMER_H
#define TIMER_H

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

uint64_t T_getTimestamp();
void T_sleep(uint64_t ms);

#endif
