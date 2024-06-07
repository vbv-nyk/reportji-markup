#include "data.h"

char* content_between_braces(char *current, char *outer_pointer) {
  int open_braces = 1; 
  
    strcat(current, "{");
    strcat(current, "\n");

    char* return_pointer = NULL;

    char *inner_token = strtok_r(NULL, "\n", &outer_pointer);
    do{
       char *find_str = (char*)malloc(strlen(inner_token) + 1);
       strcpy(find_str, inner_token);
       strcat(current, inner_token);
       strcat(current, "\n");

      if(strstr(find_str, "{") != NULL) {
          open_braces++;
      }
      if(strstr(find_str, "}") != NULL) {
          open_braces--;
          if(open_braces == 0)
              break;
      }
       inner_token = strtok_r(NULL, "\n", &outer_pointer);
    } while(open_braces != 0);

    //printf("outer pointer is pointing to %s", inner_token);
    return outer_pointer;
}
int extract_variable_name(char* name, char* input) {
   int cur = 0;
   //printf("%s\n", input);

   int n = strlen(input);
   for(int i=0; i<n; i++) {
    if(input[i] == '=') break;
    if(input[i] == ' ') continue;
    name[cur++] = input[i];
   }
   name[cur]='\0';
}
int extract_section_name(char *name) {

}
