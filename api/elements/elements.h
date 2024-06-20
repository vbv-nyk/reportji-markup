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

typedef struct {
    int rows_count;
    char** content;
} DifferenceColumns;

typedef struct {
    int count;
    DifferenceColumns **differenceColumns;
} Differences;


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
    DIFFERENCES,
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
    Differences *differences;
} ElementDefinition;

typedef struct {
    ElementType *type;
    ElementDefinition *content;
} Element;


#endif