#include "sections.h"
#define CURRENT_FILE "sections.h"


int load_file(char *file_name) {
    int flags = O_RDWR;
    
    int fd =  open(file_name, flags);
    
    if(fd == -1) {
        fatal_error("The provided file does not exist\n");
    }
    
    return fd;
}

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

int load_data(int fd, char *buffer, int file_size) {
    int bytes_read;
    if((bytes_read = read(fd, buffer, file_size))) {
        if(bytes_read == -1) {
            fatal_error("Error reading from the file\n");
        }
    }

}

void load_styles(char *buffer) {
    printf("%s", buffer);
}
void load_pages(char *buffer) {
    printf("%s", buffer);
}
void load_output(char *buffer) {
    printf("%s", buffer);
}

void load_sections(char *file_name) {
    int fd = load_file(file_name);
    off_t file_size = get_file_size(fd);
    char *buffer = (char *)malloc(file_size);
    load_data(fd, buffer, file_size);
    //printf("%s", buffer);
    
    char *token = strtok(buffer, "\n");

    while(token != NULL) {
        char *style; 
        char *find_str = token;
        if(strstr(find_str, "style") != NULL && strstr(find_str, "=") != NULL && strstr(find_str, "{") != NULL) {
            load_styles(token);
        }

        if(strstr(find_str, "pages") != NULL && strstr(find_str, "=") != NULL && strstr(find_str, "{") != NULL) {
            load_pages(token);
        }

        if(strstr(find_str, "output") != NULL && strstr(find_str, "=") != NULL && strstr(find_str, "{") != NULL) {
            load_output(token);
        }

        token = strtok(NULL, "\n");
    }
}