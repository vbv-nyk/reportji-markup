#include "api/libs.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        usage_error("Please provide the filename");
    }
    
    load_sections(argv[1]);

    create_pages();
    get_elements();
    init_output();
    write_markup_to_file();

    return EXIT_SUCCESS;
}