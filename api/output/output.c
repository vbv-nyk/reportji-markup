#include "output.h"

Output* output;


void init_output() {
    output = (Output*)malloc(sizeof(Output) * total_pages);
    
    for(int i=0; i < total_pages; i++) {
        OutputPage** outputPages = (OutputPage**)malloc(sizeof(OutputPage*));
        for(int j=0; j < pages[i]->num_elements; j++) {
            //element_to_latex(pages[i]->elements[j]);
        }
        output[i].outputPages =  outputPages;
    }
}