#include "sections.h"
// Definition of the variable
struct Sections sections = {
    .styles = "\0",
    .pages = "\0",
    .output = "\0"
}; 


// Buffer holds the entry point to either styles, pages or output
// Continues to store text into the relevant section until it finds
// the matching delimiter
void find_and_segregate(char *buffer, char *key) {
    char *buffer_cp = (char *)malloc(strlen(buffer) + 1);
    strcpy(buffer_cp, buffer);
    
    char *outer_saveptr = NULL;
    char *token = strtok_r(buffer_cp, "\n", &outer_saveptr);
    while(token != NULL) {
        char *find_str = (char*)malloc(strlen(token) + 1);
        strcpy(find_str, token);
        if(strstr(find_str, key) != NULL && strstr(find_str, "=") != NULL && strstr(find_str, "{") != NULL) {
            if(strcmp(key, "styles") == 0) {
                //printf("Found match for styles\n");
                sections.styles = (char*)malloc(strlen(buffer));
                content_between_braces(sections.styles,outer_saveptr, "{", "}");
                //printf("%s", sections.styles);
                break;
            } else if(strcmp(key, "pages") == 0) {
                //printf("Found match for pages\n");
                sections.pages = (char*)malloc(strlen(buffer));
                content_between_braces(sections.pages, outer_saveptr, "{", "}");
                //printf("%s", sections.pages);
                break;
            } else if(strcmp(key, "output") == 0) {
                //printf("Found match for output\n");
                sections.output = (char*)malloc(strlen(buffer));
                content_between_braces(sections.output, outer_saveptr, "{", "}");
                //printf("%s", sections.output);
                break;
            }
        }
        token = strtok_r(NULL, "\n", &outer_saveptr);
        free(find_str);
    }
    free(buffer_cp);
}

void load_sections(char *file_name) {
    int fd = load_file(file_name);
    off_t file_size = get_file_size(fd);
    char *buffer = (char *)malloc(file_size);
    load_data(fd, buffer, file_size);
    find_and_segregate(buffer, "styles");
    find_and_segregate(buffer, "pages");
    find_and_segregate(buffer, "output");
}