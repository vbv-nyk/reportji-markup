#ifndef SECTIONS_H
#define SECTIONS_H
#include "../libs.h"

// Data structure to hold the different sections of the markup
struct Sections {
    char* styles;
    char* pages;
    char* output;
};

extern struct Sections sections;

// Reads the input from the file descriptor and inflates the Sections
void load_sections(char *file_name); 

#endif