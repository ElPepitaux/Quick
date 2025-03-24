#include "quick.h"

void display_help(void)
{
    printf("USAGE\n\t./quick_fisher [file]\n\nDESCRIPTION\n\tfile\tfile to read\n");
}

void parse_arg(int ac, char **av, arg_info_t *arg_info)
{
    arg_info->file = NULL;
    arg_info->error = 0;
    arg_info->help = 0;
    if (ac > 2) {
        arg_info->error = 1;
        return;
    }
    if (ac == 1)
        return;
    if (strcmp(av[1], "-h") == 0) {
        arg_info->help = 1;
        return;
    }
    arg_info->file = av[1];
}
