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

typedef struct data_s {
    char *to_write;
    int index;
    struct termios shell;
    int nbr_word;
    int error;
} data_t;

void start_clock();
void stop_clock();
double get_time();

int get_input(void);
data_t *init_data(void);
void dump_data(data_t *data);
int check_input(data_t *data, int c);
void destroy_data(data_t **data);
void move_cursor_backwards(int times);

char *chose_word(char *file);
int count_word(const char *str, const char *skip);
int init_word(data_t *data, char *file);

#endif /* !QUICK_H_ */
