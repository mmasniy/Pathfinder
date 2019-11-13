#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>

#define USAGE "usage: ./pathfinder [filename]"
#define LINE_1 "error: line 1 isn't valid"
#define INVALID_NUMBER "error: invalid number of islands"

//Errors
void mx_printerr(const char *s);
bool mx_check_number_args(int argc);


#endif
