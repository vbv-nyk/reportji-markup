#ifndef ERROR_H
#define ERROR_H
#include "libs.h"

// Function that will exit upon fatal errors
void fatal_error(char* message);

// Prints help message and exits
void usage_error(char* message);

#endif