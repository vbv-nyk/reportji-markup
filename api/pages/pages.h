#ifndef PAGES_H
#define PAGES_H
#include "../libs.h"

/* The following api follows a way to manage the pages within the document*/

struct Page {
    char *name;
    char *content;
    char *style;
    int num_elements;
    Element** elements; 
};

// Global variable that holds all pages in the document
extern struct Page** pages;
extern int total_pages;

void create_pages();

/* After the pages have been created and inflated
 * This function will ease up further parsing
 * Cleans the relevant styles and content section
*/

void get_elements();
#endif