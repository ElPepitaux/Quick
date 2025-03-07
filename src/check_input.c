#include "quick.h"

int check_input(data_t *data, int c)
{
    int i = data->index;
    int ret = 1;

    if (c == data->to_write[i]) {
        ret = 0;
    } else {
        data->error++;
    }
    if ((int)strlen(data->to_write) == i + 1) {
        stop_clock();
        ret = 2;
    }
    return ret;
}
