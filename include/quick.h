#ifndef QUICK_H_
     #define QUICK_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <strings.h>
    #include <string.h>
    #include <termio.h>
    #include <time.h>

    #define RESET   "\033[0m"
    #define BLACK   "\033[30m"      /* Black */
    #define RED     "\033[31m"      /* Red */
    #define GREEN   "\033[32m"      /* Green */
    #define YELLOW  "\033[33m"      /* Yellow */
    #define BLUE    "\033[34m"      /* Blue */
    #define MAGENTA "\033[35m"      /* Magenta */
    #define CYAN    "\033[36m"      /* Cyan */
    #define WHITE   "\033[37m"      /* White */

    #define DEFAULT_TEXT "Hey, welcome to quick fisher, type the following text as fast as you can"
    #define SKIP_CHAR " \t"

typedef struct data_s {
    char *to_write;
    int index;
    struct termios shell;
    int nbr_word;
    int error;
    char **tab;
} data_t;

typedef struct arg_info_s {
    char *file;
    int error;
    int help;
} arg_info_t;

void display_help(void);
void parse_arg(int ac, char **av, arg_info_t *arg_info);

void start_clock();
void stop_clock();
double get_time();

int get_input(void);
data_t *init_data(arg_info_t *info);
void dump_data(data_t *data);
int check_input(data_t *data, int c);
void destroy_data(data_t **data, arg_info_t *info);
void move_cursor_backwards(int times);

char **get_content_split(char *file, char *skip);

char *chose_word(char **tab);
int count_word(const char *str, const char *skip);
int init_word(data_t *data);

#endif /* !QUICK_H_ */
