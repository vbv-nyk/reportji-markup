#ifndef STYLES_H
#define STLYES_H
#include "../libs.h"
/*Returns content of the styles to inflate the page data structure
    Returns NULL if the specified style does not exist*/
char* style_from_name(char* name);

/* Returns the LaTeX equivalent of the provided style
    takes input of the form-> style_name: value;
    return NULL for an invalid style*/
char* styles_to_latex(char* name);

#endif