#include "sections.h"

void get_content() {
   int open_braces = 1; 
   
    char *token = strtok(NULL, "\n");
   while(open_braces != 0) {
        char *style; 
        char *find_str = token;
        printf("%s\n", token);
        if(strstr(find_str, "{") != NULL) {
            open_braces++;
        }
        if(strstr(find_str, "}") != NULL) {
            open_braces--;
        }
        token = strtok(NULL, "\n");
   }
}

// Buffer holds the entry point to either styles, pages or output
// Continues to store text into the relevant section until it finds
// the matching delimiter
void load_styles(char *buffer) {
    char *buffer_cp = (char *)malloc(strlen(buffer));
    strcpy(buffer_cp, buffer);

    //printf("%s", buffer);
    char *token = strtok(buffer, "\n");
    while(token != NULL) {
        char *style; 
        char *find_str = token;
        if(strstr(find_str, "style") != NULL && strstr(find_str, "=") != NULL && strstr(find_str, "{") != NULL) {
            printf("{\n");
            get_content();
        }
        token = strtok(NULL, "\n");
    }
}
void load_pages(char *buffer) {
}
void load_output(char *buffer) {
}

void load_sections(char *file_name) {
    int fd = load_file(file_name);
    off_t file_size = get_file_size(fd);
    char *buffer = (char *)malloc(file_size);
    load_data(fd, buffer, file_size);
    //printf("%s", buffer);
    
    load_styles(buffer);
    load_pages(buffer);
    load_output(buffer);
}