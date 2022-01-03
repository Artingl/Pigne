#include <pigne/Timer.h>

uint64_t T_getTimestamp()
{
    struct timeval te; 
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

void T_sleep(uint64_t ms)
{
    uint64_t start = T_getTimestamp();
    while(start + ms > T_getTimestamp()) {}
}
