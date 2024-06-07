#include "pages.h"

struct Page** pages;

// Combines page and style and store it in the global variable
void create_pages() {
    //printf("%s", sections.pages);
    //printf("%s", sections.styles);
        
    char *outer_saveptr = NULL;

    char *token = strtok_r(sections.pages, "\n", &outer_saveptr);
    while(token != NULL) {
        char *find_str = strdup(token); 
       if(strstr(find_str, "=") != NULL) {
          char *name = (char *)malloc(20);
          char *content = (char *)malloc(1000);
          name[0] = '\0';
          content[0] = '\0';
          extract_variable_name(name, find_str);
          outer_saveptr = content_between_braces(content, outer_saveptr);
          //printf("%s\n", name);
          //printf("%s", content);
          free(name);
          free(content);
       }
           //printf("%s", outer_saveptr) ;
        token = strtok_r(NULL, "\n", &outer_saveptr);
        //printf("%s", token);
        free(find_str);;
    }
}