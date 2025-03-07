#include "quick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_word(data_t *data, char *file)
{
    if (!data->to_write)
        free(data->to_write);
    data->to_write = chose_word(file);
    if (!data->to_write)
        return 1;
    data->nbr_word = count_word(data->to_write, " \t");
    if (data->nbr_word == -1)
        return 1;
    return 0;
}

data_t *init_data(void)
{
    data_t *new = malloc(sizeof(data_t));

    if (!new)
        return NULL;
    if (init_word(new, "file.txt")) {
        free(new);
        return NULL;
    }
    new->index = 0;
    new->error = 0;
    new->shell = (struct termios){0};
    tcgetattr(0, &new->shell);
    new->shell.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new->shell);
    chose_word("file.txt");
    return new;
}

void dump_data(data_t *data)
{
    if (!data)
        return;
    printf("DATA {to_write = %s, index = %d}\n", data->to_write, data->index);
    return;
}

void destroy_data(data_t **data)
{
    if (!(*data))
        return;
    (*data)->shell.c_lflag |= (ICANON | ECHO);
    tcsetattr(0, TCSANOW, &(*data)->shell);
    free((*data)->to_write);
    free((*data));
    *data = NULL;
}
