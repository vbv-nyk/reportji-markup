#ifndef FILES_H
#define FILES_H
#include "libs.h"

// Loads a file given the pathname
int load_file(char *file_name);

// Retrieves the file size provided the file descriptor
int get_file_size(int fd); 

// Loads the data into the provided buffer provided the file descriptor and size
int load_data(int fd, char *buffer, int file_size);

#endif