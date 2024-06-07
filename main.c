#include "api/libs.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        usage_error("Please provide the filename");
    }
    
    load_sections(argv[1]);

    printf("%s", sections.styles);
    printf("%s", sections.pages);
    printf("%s", sections.output);
    create_pages();
    return EXIT_SUCCESS;
}