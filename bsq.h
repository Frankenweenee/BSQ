#ifndef BSQ_H
#define BSQ_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void error_control(char *str, char *buffer, int fd);

#endif
