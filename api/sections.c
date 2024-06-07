#include "sections.h"
// Definition of the variable
struct Sections sections; 

void get_content(char *current) {
   int open_braces = 1; 
   
   strcat(current, "{");
   strcat(current, "\n");
   

   char *token = strtok(NULL, "\n");
   do{
        char *style; 
        char *find_str = token;
        strcat(current, token);
        strcat(current, "\n");
        if(strstr(find_str, "{") != NULL) {
            open_braces++;
        }
        if(strstr(find_str, "}") != NULL) {
            open_braces--;
        }
        token = strtok(NULL, "\n");
   } while(open_braces != 0);
   
}

// Buffer holds the entry point to either styles, pages or output
// Continues to store text into the relevant section until it finds
// the matching delimiter
void find_and_segregate(char *buffer, char *key) {
    char *buffer_cp = (char *)malloc(strlen(buffer) + 1);
    strcpy(buffer_cp, buffer);
    char *token = strtok(buffer_cp, "\n");
    while(token != NULL) {
        char *find_str = token;
        if(strstr(find_str, key) != NULL && strstr(find_str, "=") != NULL && strstr(find_str, "{") != NULL) {
            if(strcmp(key, "styles") == 0) {
                //printf("Found match for styles\n");
                sections.styles = (char*)malloc(strlen(buffer));
                get_content(sections.styles);
                //printf("%s", sections.styles);
                break;
            } else if(strcmp(key, "pages") == 0) {
                //printf("Found match for pages\n");
                sections.pages = (char*)malloc(strlen(buffer));
                get_content(sections.pages);
                //printf("%s", sections.pages);
                break;
            } else if(strcmp(key, "output") == 0) {
                //printf("Found match for output\n");
                sections.output = (char*)malloc(strlen(buffer));
                get_content(sections.output);
                //printf("%s", sections.output);
                break;
            }
        }
        token = strtok(NULL, "\n");
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