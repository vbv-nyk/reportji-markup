#include "pages.h"

struct Page** pages;
int total_pages;

// Combines page and style and store it in the global variable
void create_pages() {
    //printf("%s", sections.pages);

        
    char *outer_saveptr = NULL;

    char *token = strtok_r(sections.pages, "\n", &outer_saveptr);
    int page_count = 0;
    pages = (struct Page**)malloc(sizeof(struct Page*) * (page_count + 1));

    while(token != NULL) {
        char *find_str = strdup(token); 
       if(strstr(find_str, "=") != NULL) {
          char *name = (char *)malloc(100);
          char *style = (char *)malloc(100);
          char *content = (char *)malloc(1000);
          name[0] = '\0';
          content[0] = '\0';

          int name_size = extract_variable_name(name, find_str);
          name = realloc(name, name_size);

          int style_size = extract_section_name(style, find_str);
          style = realloc(style, style_size);

          outer_saveptr = content_between_braces(content, outer_saveptr, "{", "}");
          struct Page* page = (struct Page*)malloc(name_size + style_size + strlen(content));

          page->name = name;
          page->content = content;
          page->style = style_from_name(style);
          free(style);

          pages[page_count] = page;
          page_count++;
        pages =  realloc(pages, (page_count + 1) * sizeof(struct Page*));
       }
        token = strtok_r(NULL, "\n", &outer_saveptr);
        free(find_str);;
    }
    total_pages = page_count;
    pages[page_count] = NULL;
}

void read_through_content(char *content) {
    char* outer_ptr;
    char* inner_ptr;
    outer_ptr = content;
    inner_ptr = content;
    while(*outer_ptr != '\0') {
        int length = 0;
       while(*inner_ptr != '\n' && *inner_ptr != '\0') {
        length++;
        inner_ptr++;
       }
       char *current_line = strndup(outer_ptr, length);
       char *element_name = (char*)malloc(strlen(current_line));
        extract_element_name(element_name, current_line);
       //printf("%s", element_name);
       ElementType type = get_element_type(element_name);
       if(type == TITLE || type == SUBTITLE || type == HEADING || type == AUTHOR || type == DATE) {
        char *element_content = (char*)malloc(1000);
        content_between_quotes(element_content, outer_ptr);
        printf("%s: %s", element_name, element_content);
        printf("\n");
        free((element_content));
       }
       if(*inner_ptr != '\0') inner_ptr++;
       outer_ptr = inner_ptr;
    }
}

void get_elements() {
    for(int i=0; i<total_pages; i++) {
        char* content_copy = strdup(pages[i]->content);
        read_through_content(content_copy);
        free(content_copy);
    }
}