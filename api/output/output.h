#ifndef OUTPUT_H
#define OUTPUT_H
#include "../libs.h"

typedef struct {
    char** markup;
} OutputPage;

typedef struct {
    OutputPage** outputPages;
} Output;

extern Output* output;

void parse_title();
void parse_subtitle();
void parse_heading();
void parse_author();
void parse_date();
void parse_paragraphs();
void parse_items();
void parse_figures();
void parse_citations();

char* element_to_latex(Element* element);

void init_output();

#endif