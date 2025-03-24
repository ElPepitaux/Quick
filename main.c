#include "quick.h"
#include <stdio.h>

void display(data_t *data, int res)
{
    move_cursor_backwards(strlen(data->to_write));
    for (int i = 0; i < data->index; i++) {
        printf(GREEN);
        printf("%c", data->to_write[i]);
        printf(RESET);
    }
    if (res == 0) {
        printf(GREEN);
        printf("%c", data->to_write[data->index]);
        printf(RESET);
    } else if (res == 1) {
        printf(RED);
        printf("%c", data->to_write[data->index]);
        printf(RESET);
    }
    for (int i = data->index + 1; data->to_write[i]; i++) {
        printf("%c", data->to_write[i]);
    }
    if (res == 0)
        data->index++;
    fflush(stdout);
}

int win(data_t *data)
{
    double time = 0;
    int c = 0;

    printf("\n");
    time = get_time();
    printf("You typed %d words per minute\n", (int)(data->nbr_word * 60 / time));
    printf("You made %d errors\n", data->error);
    printf("You want to play again? (y/n)\n");
    fflush(stdout);
    c = get_input();
    if (c == 'y') {
        start_clock();
        data->index = 0;
        data->error = 0;
        init_word(data);
        printf("\n%s", data->to_write);
        return 0;
    }
    return 1;
}

int loop(data_t *data, arg_info_t *info)
{
    int res = 0;
    int c = 0;

    while (c != 27) {
        c = get_input();
        if (c == -1) {
            perror("scanf");
            destroy_data(&data, info);
            return 1;
        }
        res = check_input(data, c);
        if (res == 2) {
            if (win(data))
                break;
            else
                continue;
        }
        display(data, res);
    }
    return 0;
}

int main(int ac, char **av)
{
    srand(time(NULL));
    arg_info_t arg_info = {0};
    data_t *data = NULL;

    parse_arg(ac, av, &arg_info);
    if (arg_info.error || arg_info.help) {
        display_help();
        return arg_info.error ? 84 : 0;
    }
    data = init_data(&arg_info);
    if (!data)
        return 84;
    printf("%s", data->to_write);
    start_clock();
    if (loop(data, &arg_info))
        return 84;
    destroy_data(&data, &arg_info);
    return 0;
}
