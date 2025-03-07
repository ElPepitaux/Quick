#include "quick.h"
#include <stdio.h>

int get_input(void)
{
    char c = 0;
    int ret = scanf("%c", &c);
    if (ret == 0)
        return -1;
    return c;
}
