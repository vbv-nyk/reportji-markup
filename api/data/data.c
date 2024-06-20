#include "data.h"

char* content_between_braces(char *current, char *outer_pointer, char* open_brace, char* close_brace ) {
  int open_braces = 1; 
    strcat(current, open_brace);
    strcat(current, "\n");

    char* return_pointer = NULL;

    char *inner_token = strtok_r(NULL, "\n", &outer_pointer);
    do{
       char *find_str = (char*)malloc(strlen(inner_token) + 1);
       strcpy(find_str, inner_token);
       strcat(current, inner_token);
       strcat(current, "\n");

      if(strstr(find_str, open_brace) != NULL) {
          open_braces++;
      }
      if(strstr(find_str, close_brace) != NULL) {
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
   
   return cur;
}

int extract_section_name(char *name, char *input) {
    int n = strlen(input);
    
    int i=0;
    int cur = 0;
    while(input[i] != '=') {
        i++;
    }
    
    for(i; i<n; i++) {
        if(input[i] == '=' || input[i] == ' ' || input[i] == '{') {
            i++;
            continue;
        }
        name[cur++] = input[i];
    }
    
   name[cur]='\0';
    return cur;
}

int extract_element_name(char *name, char *content) {
    int i = 0;   
    int cur = 0;
    int n = strlen(content);
    while(content[i] == ' ') {
        i++;
    }
    
    for(i; i<n; i++) {
        if(content[i] == ':') {
            break;
        }
        name[cur++] = content[i];
    }
    name[cur] = '\0';
    return strlen(name);
}


ElementType get_element_type(char* element_name) {
    if(strcmp(element_name, "title") == 0) {
        return TITLE;
    }
    if(strcmp(element_name, "subtitle") == 0) {
        return SUBTITLE;
    }
    if(strcmp(element_name, "heading") == 0) {
        return HEADING;
    }
    if(strcmp(element_name, "author") == 0) {
        return AUTHOR;
    }
    if(strcmp(element_name, "date") == 0) {
        return DATE;
    }
    if(strcmp(element_name, "paragraphs") == 0) {
        return PARAGRAPHS;
    }
    if(strcmp(element_name, "items") == 0) {
        return ITEMS;
    }
    if(strcmp(element_name, "figures") == 0) {
        return FIGURES;
    }
    if(strcmp(element_name, "citations") == 0) {
        return CITATIONS;
    }
    if(strcmp(element_name, "differences") == 0) {
        return DIFFERENCES;
    }
    
    return INVALID;
}

int content_between_quotes(char* output, char* input) {
   int cur = 0;
   while(*input != '\"') {
       input++;
   }
   input++;
   while(*input != '\"') {
       output[cur++] = *input;
       input++;
   }
   output[cur] = '\0';
   return cur;
}

int parse_figure_source(char* output, char* input) {
//   char* name = (char*)malloc(strlen(input));
//   if(extract_element_name(name, input) == "src") {
//       content_between_quotes(output, input);
//   }
}

int parse_figure_caption(char* output, char* input) {
    
}