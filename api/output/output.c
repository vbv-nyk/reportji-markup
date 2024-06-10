#include "output.h"

Output* output;

char* parse_title(ElementDefinition title) {
    
}
char* parse_subtitle(ElementDefinition subtitle) {

}
char* parse_heading(ElementDefinition heading) {
        
}
char* parse_author(ElementDefinition author) {
        
}
char* parse_date(ElementDefinition date) {
        
}
char* parse_paragraphs(ElementDefinition paragraphs) {
        
}
char* parse_items(ElementDefinition items) {
        
}
char* parse_figures(ElementDefinition figures) {
        
}
char* parse_citations(ElementDefinition citations) {
        
}


char* element_to_latex(Element* element) {
    switch(*element->type) {
        case TITLE:
            parse_title(*element->content);
            break;
        case SUBTITLE:
            parse_subtitle(*element->content);
            break;
        case HEADING:
            parse_heading(*element->content);
            break;
        case AUTHOR:
            parse_author(*element->content);
            break;
        case DATE:
            parse_date(*element->content);
            break;
        case PARAGRAPHS:
            parse_paragraphs(*element->content);
            break;
        case ITEMS:
            parse_items(*element->content);
            break;
        case FIGURES:
            parse_figures(*element->content);
            break;
        case CITATIONS:
            parse_citations(*element->content);
            break;
    }
}


void init_output() {
    output = (Output*)malloc(sizeof(Output) * total_pages);
    for(int i=0; i < total_pages; i++) {
        OutputPage* outputPages = (OutputPage*)malloc(sizeof(OutputPage));
        char** markup = (char**)malloc(pages[i]->num_elements*(sizeof(char*)));
        for(int j=0; j < pages[i]->num_elements; j++) {
            char* output_markup = element_to_latex(pages[i]->elements[j]);
            markup[j] = output_markup;
        }
        outputPages->markup = markup;
        output[i].outputPages =  outputPages;
    }
}