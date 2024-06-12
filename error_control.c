// error_control.c
#include "bsq.h"

void print_error(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

void error_control(char *str, char *buffer, int fd)
{
    print_error(str);
    if (buffer)
    {
        free(buffer);
    }
    if (fd != -1)
    {
        close(fd);
    }
}
