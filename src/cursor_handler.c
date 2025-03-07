#include "quick.h"

void move_cursor_backwards(int times)
{
    printf("\033[%dD", times);
}


