#include "api/libs.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        usage_error("Please provide the filename");
    }
    
    load_sections(argv[1]);

    time_t ts_epoch;
    //printf("%ld", (long)ts_epoch);
    struct tm *broken_time = (struct tm*)malloc(sizeof(struct tm)); 
    broken_time = localtime(&ts_epoch);

    create_pages();
    // get_elements();
    // init_output();
    // write_markup_to_file(broken_time);

    return EXIT_SUCCESS;
}