#ifndef FILES_H
#define FILES_H
#include "libs.h"

// Loads a file given the pathname
int load_file(char *file_name) {
    int flags = O_RDWR;
    
    int fd =  open(file_name, flags);
    
    if(fd == -1) {
        fatal_error("The provided file does not exist\n");
    }
    
    return fd;
}

// Retrieves the file size provided the file descriptor
int get_file_size(int fd) {
    off_t file_size = lseek(fd, 0, SEEK_END);
    if(file_size == -1) {
        fatal_error("File doesn't have seek permissions\n");
    }
    int regain_offset = lseek(fd, 0, SEEK_SET);
    if(regain_offset == -1) {
        fatal_error("Error setting offset to beginning\n");
    }
    return file_size;
}

// Loads the data into the provided buffer provided the file descriptor and size
int load_data(int fd, char *buffer, int file_size) {
    int bytes_read;
    if((bytes_read = read(fd, buffer, file_size))) {
        if(bytes_read == -1) {
            fatal_error("Error reading from the file\n");
        }
    }

}
#endif