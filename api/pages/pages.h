#ifndef PAGES_H
#define PAGES_H
#include "../libs.h"

/* The following api follows a way to manage the pages within the document*/

struct Page {
    char *name;
    char *content;
    char *style;
};

// Global variable that holds all pages in the document
extern struct Page** pages;
extern int total_pages;

void create_pages();

#endif