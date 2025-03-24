#include "quick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_word(data_t *data)
{
    if (!data->to_write)
        free(data->to_write);
    data->to_write = chose_word(data->tab);
    if (!data->to_write)
        return 1;
    data->nbr_word = count_word(data->to_write, SKIP_CHAR);
    return 0;
}

data_t *init_data(arg_info_t *info)
{
    data_t *new = malloc(sizeof(data_t));

    if (!new)
        return NULL;
    new->tab = get_content_split(info->file, "\n");
    if (init_word(new)) {
        free(new);
        return NULL;
    }
    new->index = 0;
    new->error = 0;
    new->shell = (struct termios){0};
    tcgetattr(0, &new->shell);
    new->shell.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &new->shell);
    return new;
}

void dump_data(data_t *data)
{
    if (!data)
        return;
    printf("DATA {to_write = %s, index = %d}\n", data->to_write, data->index);
    return;
}

void destroy_data(data_t **data, arg_info_t *info)
{
    if (!(*data))
        return;
    (*data)->shell.c_lflag |= (ICANON | ECHO);
    tcsetattr(0, TCSANOW, &(*data)->shell);
    if (info->file)
        free((*data)->to_write);
    free((*data));
    *data = NULL;
}
