#include "quick.h"

int count_word(const char *str, const char *skip)
{
    char *dup = strdup(str);
    if (!dup)
        return -1;
    char *tmp = strtok(dup, skip);
    int ret = 0;

    while (tmp != NULL) {
        ret++;
        tmp = strtok(NULL, skip);
    }
    free(dup);
    return ret;
}

static char **split_word(char *str, char *skip)
{
    int i = 0;
    char **tab = NULL;
    char *tmp = NULL;
    int nbr_word = count_word(str, skip);

    tab = calloc((nbr_word + 1), sizeof(char *));
    if (!tab)
        return NULL;
    tmp = strtok(str, skip);
    do {
        tab[i] = strdup(tmp);
        if (!tab[i])
            return NULL;
        tmp = strtok(NULL, skip);
        i++;
    } while (tmp);
    return tab;
}

char *get_content(char *file)
{
    FILE *fd = fopen(file, "r");
    char *content = NULL;
    size_t size = 0;

    if (!fd)
        return NULL;
    fseek(fd, 0, SEEK_END);
    size = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    content = malloc(size + 1);
    if (!content) {
        fclose(fd);
        return NULL;
    }
    fread(content, 1, size, fd);
    content[size] = 0;
    fclose(fd);
    return content;
}

int tab_len(char **tab)
{
    int i = 0;

    while(tab[i])
        i++;
    return i;
}

char *chose_word(char *file)
{
    char *content = get_content(file);
    char **tab = NULL;
    char *word = NULL;

    if (!content)
        return NULL;
    tab = split_word(content, "\n");
    if (!tab)
        return NULL;
    word = strdup(tab[rand() % tab_len(tab)]);
    if (!word)
        return NULL;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    return word;
}
