#include "api/libs.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        usage_error("Please provide the filename");
    }
    
    load_sections(argv[1]);

    create_pages();
    get_elements();

    for(int i=0; i<total_pages;i++) {
            printf("%d\n", pages[i]->num_elements);
    }
    
    return EXIT_SUCCESS;
}