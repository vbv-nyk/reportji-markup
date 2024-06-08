#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "../libs.h"

typedef enum {
    TITLE,
    SUBTITLE,
    HEADING,
    AUTHOR,
    DATE,
    PARAGRAPHS,
    ITEMS,
    FIGURES,
    CITATIONS
} ElementType;

typedef union {
    Title title;    
    Subtitle subtitle;
    Heading heading;
    Author author;
    Date date;
    Paragraphs paragraphs;
    Items items;
    Figures figures;
    Citations citations;
} ElementDefinition;

typedef struct {
    ElementType type;
    ElementDefinition content;
} Element;

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
} Paragraphs;

typedef struct {
    char **text;
} Items;

typedef struct {
    char **text;
} Figures;

typedef struct {
    char **text;
} Citations;


#endif