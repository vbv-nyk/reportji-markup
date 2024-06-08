#ifndef DATA_H
#define DATA_H

#include "../libs.h"
/* Provides an interface for the common operations performed on the data*/

/* Store the data between the braces into the provided buffer
    Usage: use strtok() to retrieve the start of the buffer where the token is present 
    Output: Data between the braces of the token provided, appended into *current
    Note: The function assumes that there's enough space to store the content in *current
    */
char* content_between_braces(char *current, char *outer_pointer, char* open_brace, char* close_brace );


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
int extract_section_name(char *name, char *find_str);

/* 
 *  Input
    The content is of the format 
    element_name: "content"
    or
    elment_name: ["content 1", "content 2"]

 *  Output
    Element with content inflated
*/

/*
 * Input
   The input is of the form element_name: content
   The output is of the form element_name
   The output stored in the *name buffer passed to the fucntion
*/
int extract_element_name(char *name, char *content);

/* Input
    The name of the element
    Output
    The type of the element
    Note: Returns NULL if the type does not exist
        Useful for filtering invalid types
*/
ElementType get_element_type(char* element_name);


int content_between_quotes(char* output, char* input);
#endif