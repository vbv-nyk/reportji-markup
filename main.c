#include "api/libs.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        usage_error("Please provide the filename");
    }
    
    load_sections(argv[1]);

    create_pages();
    clean_data();
    
    int i = 0;
    while(pages[i] != NULL) {
        printf("Name:%s\nContent:%s\nStyle:%s", pages[i]->name, pages[i]->content, pages[i]->style);
        i++;
    }
    return EXIT_SUCCESS;
}