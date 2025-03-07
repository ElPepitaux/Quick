#include "quick.h"

time_t toto;

void start_clock()
{
    toto = time(NULL);
}

void stop_clock()
{
    toto = time(NULL) - toto;
}

double get_time()
{
    return (double)toto;
}
