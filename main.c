#include "api/libs.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        usage_error("Please provide the filename");
    }
    
    load_sections(argv[1]);

    create_pages();
    printf("%s\n", pages[0]->name);
    printf("%s\n", pages[0]->content);
    printf("%d", total_pages);
    return EXIT_SUCCESS;
}