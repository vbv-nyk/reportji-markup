#include "pages.h"

struct Page** pages;
int total_pages;

// Combines page and style and store it in the global variable
void create_pages() {
    //printf("%s", sections.pages);
    //printf("%s", sections.styles);
        
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

          outer_saveptr = content_between_braces(content, outer_saveptr);
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