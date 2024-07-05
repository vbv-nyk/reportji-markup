#include "pages.h"

struct Page** pages;
int total_pages;

// Combines page and style and store it in the global variable
void create_pages() {
    // printf("%s", sections.pages);

    char* outer_saveptr = NULL;

    char* token = strtok_r(sections.pages, "\n", &outer_saveptr);
    int page_count = 0;
    pages = (struct Page**)malloc(sizeof(struct Page*) * (page_count + 1));

    while (token != NULL) {
        char* find_str = strdup(token);
        if (strstr(find_str, "=") != NULL) {
            char* name = (char*)malloc(100);
            char* style = (char*)malloc(100);
            char* content = (char*)malloc(30000);
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
            pages = realloc(pages, (page_count + 1) * sizeof(struct Page*));
        }
        token = strtok_r(NULL, "\n", &outer_saveptr);
        free(find_str);
        ;
    }
    total_pages = page_count;
    pages[page_count] = NULL;
}

char* load_element_content(ElementType type, char* outer_ptr, int num_elements) {
    char* element_content = (char*)malloc(1000);
    content_between_quotes(element_content, outer_ptr);
    return element_content;
}
char** inflate_element_arrays(char* outer_ptr, char** text, int* count) {
    while (*outer_ptr != ']') {
        char* output = (char*)malloc(10000);
        content_between_quotes(output, outer_ptr);
        while(*outer_ptr != '\"' && *outer_ptr != ']') {
            outer_ptr++;
        }
        if(*outer_ptr == ']') break;
        outer_ptr++;
        while(*outer_ptr != '\"' && *outer_ptr != ']') {
            outer_ptr++;
        }
        if(*outer_ptr == ']') break;
        outer_ptr++;
        text[*count] = output;
        *count = *count + 1;
        text = realloc(text, sizeof(char*) * (*count + 1));
    }
    return text;
}
FigureContent** inflate_figure_arrays(char* outer_ptr, FigureContent** figureContent, int* count) {
    while(*outer_ptr != ']') {
        char *name1 = (char*)malloc(100);
        char *content1 = (char*)malloc(100);
        char *name2 = (char*)malloc(100);
        char *content2 = (char*)malloc(100);
        if(*outer_ptr == '{') {
            outer_ptr++;
            extract_element_name(name1, outer_ptr);
            content_between_quotes(content1, outer_ptr);
            while(*outer_ptr != ',') {
                outer_ptr++;
            }
            outer_ptr++;
            extract_element_name(name2, outer_ptr);
            content_between_quotes(content2, outer_ptr);
            FigureContent* figureElement = (FigureContent*)malloc(sizeof(FigureContent));
            if(strcmp(name1,"src") == 0) {
                figureElement->src = content1;
                figureElement->caption = content2;
            } else if(strcmp(name2, "src") == 0) {
                figureElement->src = content2;
                figureElement->caption = content1;
            }
            figureContent[*count] = figureElement; 
            *count = *count + 1;
            figureContent = realloc(figureContent, sizeof(FigureContent*) * (*count+1));
        }
        //printf("%s %s", name1, name2) ;
        outer_ptr++;
    }
    return figureContent;
}

DifferenceColumns** inflate_tables_data(char* outer_ptr, DifferenceColumns** differenceColumns, int *count) {
    while(*outer_ptr != ';') {
        while(*outer_ptr != '[' && *outer_ptr != '\0') {
            outer_ptr++;
        }
        if(*outer_ptr == ';') {
            return differenceColumns;
        }
        outer_ptr--;
        int rows_count = 0;
        char** text = (char**)malloc(sizeof(char*) * 1);
        text = inflate_element_arrays(outer_ptr, text, &rows_count);
        while(*outer_ptr != ']' && *(outer_ptr + 1) != '\0') {
            outer_ptr++;
        }
        DifferenceColumns* differenceColumn = (DifferenceColumns*)malloc(sizeof(DifferenceColumns));
        differenceColumn->content = text;
        differenceColumn->rows_count = rows_count;
        differenceColumns[*count] = differenceColumn;
        *count = *count + 1;
        //printf("%d", *count);
        differenceColumns = realloc(differenceColumns, sizeof(DifferenceColumns*)* (*count + 1));
        outer_ptr++;
    }    
    return differenceColumns;
}


char* load_element_definition(Element* element, ElementType* type, char* outer_ptr, int num_elements, ElementDefinition* element_definition) {
    if (*type == TITLE) {
        Title* title = (Title*)malloc(sizeof(Title));
        char* content = (char*)malloc(1000);
        element->type = type;
        content = load_element_content(*type, outer_ptr, num_elements);
        title->text = content;
        element_definition->title = title;
    } else if (*type == SUBTITLE) {
        Subtitle* subtitle = (Subtitle*)malloc(sizeof(Subtitle));
        char* content = (char*)malloc(1000);
        element->type = type;
        content = load_element_content(*type, outer_ptr, num_elements);
        subtitle->text = content;
        element_definition->subtitle = subtitle;
    } else if (*type == HEADING) {
        Heading* heading = (Heading*)malloc(sizeof(Heading));
        char* content = (char*)malloc(1000);
        element->type = type;
        content = load_element_content(*type, outer_ptr, num_elements);
        heading->text = content;
        element_definition->heading = heading;
    } else if (*type == AUTHOR) {
        Author* author = (Author*)malloc(sizeof(Author));
        char* content = (char*)malloc(1000);
        element->type = type;
        content = load_element_content(*type, outer_ptr, num_elements);
        author->text = content;
        element_definition->author = author;
    } else if (*type == DATE) {
        Date* date = (Date*)malloc(sizeof(Date));
        char* content = (char*)malloc(1000);
        element->type = type;
        content = load_element_content(*type, outer_ptr, num_elements);
        date->text = content;
        element_definition->date = date;
    } else if (*type == PARAGRAPHS) {
        element->type = type;
        Paragraphs* paragraphs = (Paragraphs*)malloc(sizeof(Paragraphs));
        int count = 0;
        char** text = (char**)malloc(sizeof(char*) * 1);
        text = inflate_element_arrays(outer_ptr, text, &count);
        paragraphs->count = count;
        paragraphs->text = text;
        element_definition->paragraphs = paragraphs;
    } else if (*type == ITEMS) {
        element->type = type;
        Items* items = (Items*)malloc(sizeof(Items));
        int count = 0;
        char** text = (char**)malloc(sizeof(char*) * 1);
        text = inflate_element_arrays(outer_ptr, text, &count);
        items->count = count;
        items->text = text;
        // printf("%s", items->text[0]);
        element_definition->items = items;
    } else if (*type == FIGURES) {
        element->type = type;
        Figures* figures = (Figures*)malloc(sizeof(Figures));
        int count = 0;
        FigureContent** figureContent = (FigureContent**)malloc(sizeof(FigureContent*) * 1);
        figureContent = inflate_figure_arrays(outer_ptr, figureContent, &count);
        figures->count = count;
        figures->figureContent = figureContent;
        element_definition->figures = figures;
    } else if (*type == CITATIONS) {
        element->type = type;
        Citations* citations = (Citations*)malloc(sizeof(Citations));
        int count = 0;
        char** text = (char**)malloc(sizeof(char*) * 1);
        text = inflate_element_arrays(outer_ptr, text, &count);
        citations->count = count;
        citations->text = text;
        element_definition->citations = citations;
    } else if(*type == DIFFERENCES) {
        element->type = type;
        DifferenceColumns** differenceColumns = (DifferenceColumns**)malloc(sizeof(DifferenceColumns*) * 1);
        Differences *differences = (Differences*)malloc(sizeof(Differences));
        int count = 0;
        differenceColumns = inflate_tables_data(outer_ptr, differenceColumns, &count);
        differences->count = count - 1;
        differences->differenceColumns = differenceColumns;
        element_definition->differences = differences;
    }
}
int create_elements(char* content, ElementType* elementTypes, Element** elements) {
    int num_elements = 0;
    char* outer_ptr = content;
    char* inner_ptr = content;

    while (*outer_ptr != '\0') {
        Element* element = (Element*)malloc(sizeof(Element));
        int length = 0;
        while (*inner_ptr != '\n' && *inner_ptr != '\0') {
            length++;
            inner_ptr++;
        }

        char* current_line = strndup(outer_ptr, length);
        char* element_name = (char*)malloc(strlen(current_line));
        extract_element_name(element_name, current_line);
        ElementType* type = (ElementType*)malloc(sizeof(ElementType));
        *type = get_element_type(element_name);

        if (*type != INVALID) {
            ElementDefinition* element_definition = (ElementDefinition*)malloc(sizeof(ElementDefinition));
            load_element_definition(element, type, outer_ptr, num_elements, element_definition);
            element->content = element_definition;
            elements[num_elements] = element;
            num_elements++;
        }

        if (*inner_ptr != '\0') inner_ptr++;
        outer_ptr = inner_ptr;
    }
    return num_elements;
}

void get_elements() {
    for (int i = 0; i < total_pages; i++) {
        char* content_copy = strdup(pages[i]->content);
        ElementType* elementTypes = (ElementType*)malloc(sizeof(ElementType) * (1));
        Element** elements = (Element**)malloc(1 * sizeof(Element*));
        int num_elements = create_elements(content_copy, elementTypes, elements);
        pages[i]->elements = elements;
        pages[i]->num_elements = num_elements;
        free(content_copy);
        free(pages[i]->content);
    }
}