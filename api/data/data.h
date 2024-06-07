#ifndef DATA_H
#define DATA_H

#include "../libs.h"
/* Provides an interface for the common operations performed on the data*/

/* Store the data between the braces into the provided buffer
    Usage: use strtok() to retrieve the start of the buffer where the token is present 
    Output: Data between the braces of the token provided, appended into *current
    Note: The function assumes that there's enough space to store the content in *current
    */
char* content_between_braces(char *current, char* outer_pointer);

/*
    Retrieves the name of the variable of the form
    variable_name = section_name { 
    stores variable_name inside the buffer *name
    Usage: use strtok() to retrieve the start of the buffer where the token is present 
    Returns the length of thte name
*/
int extract_variable_name(char* naae, char* input);

/*
    Retrieves the name of the section of the form
    variable_name = section_name {
    stores section_name inside the buffer *name
    Usage: use strtok() to retrieve the start of the buffer where the token is present 
    Returns the length of the name
*/
int extract_section_name(char *name);
#endif