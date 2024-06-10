#ifndef OUTPUT_H
#define OUTPUT_H
#include "../libs.h"

typedef struct {
    char* name;
    char** markup;
} OutputPage;

typedef struct {
    OutputPage* outputPages;
} Output;

extern Output* output;

char* parse_title(ElementDefinition title);
char* parse_subtitle(ElementDefinition subtitle);
char* parse_heading(ElementDefinition heading);
char* parse_author(ElementDefinition author);
char* parse_date(ElementDefinition date);
char* parse_paragraphs(ElementDefinition paragraphs);
char* parse_items(ElementDefinition items);
char* parse_figures(ElementDefinition figures);
char* parse_citations(ElementDefinition citations);

char* element_to_latex(Element* element);

void init_output();

#endif