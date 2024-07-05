#include "styles.h"

char* style_from_name(char* name) {
    char* inner_ptr = NULL;
    char* search_string = strdup(sections.styles);
    char* token = strtok_r(search_string, "\n", &inner_ptr);
   char* output = (char*)malloc(50000);
    
    while(token != NULL) {
       char *find_str = strdup(token);
       if(strstr(find_str, name) != NULL) {
           content_between_braces(output, inner_ptr, "{", "}");
       }
       token = strtok_r(NULL, "\n", &inner_ptr);
       free(find_str);
    }

    output = realloc(output, strlen(output));
    return output;
}
char* styles_to_latex(char* name) {}