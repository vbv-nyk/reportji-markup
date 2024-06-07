#include "error.h"

void fatal_error(char* message) {
    printf("%s: ", message);
    printf("%s", strerror(errno));
    exit(EXIT_FAILURE);
}

void usage_error(char* message) {
    printf("Error: %s\n", message);
    printf("Usage: rpc filename\nDescription: Parses the markup into it's relevant LateX document\n");
    exit(EXIT_FAILURE);
}
