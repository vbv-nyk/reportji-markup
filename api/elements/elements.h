#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "../libs.h"


typedef struct {
    char *text;
} Title;

typedef struct {
    char *text;
} Subtitle;

typedef struct {
    char *text;
} Heading;

typedef struct {
    char *text;
} Author;

typedef struct {
    char *text;
} Date;

typedef struct {
    char **text;
    int count;
} Paragraphs;

typedef struct {
    char **text;
    int count;
} Items;

typedef struct{
    char* src;
    char* caption;
} FigureContent;

typedef struct {
    FigureContent **figureContent;
    int count;
} Figures;

typedef struct {
    char **text;
    int count;
} Citations;



typedef enum {
    TITLE,
    SUBTITLE,
    HEADING,
    AUTHOR,
    DATE,
    PARAGRAPHS,
    ITEMS,
    FIGURES,
    CITATIONS,
    INVALID
} ElementType;

typedef union {
    Title *title;    
    Subtitle *subtitle;
    Heading *heading;
    Author *author;
    Date *date;
    Paragraphs *paragraphs;
    Items *items;
    Figures *figures;
    Citations *citations;
} ElementDefinition;

typedef struct {
    ElementType *type;
    ElementDefinition *content;
} Element;

#endif