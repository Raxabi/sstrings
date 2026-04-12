#include <stdio.h>
#include <stdlib.h>
#include "sstrings.h"

int main() {
    String* const str = string_from_char("Hello_World!");
    if (!str) {
        perror("Error allocating string");
        return EXIT_FAILURE;
    }

    if (!string_replace(str, 5, ' ')) {
        perror("Index exceeds the string length");
        return EXIT_FAILURE;
    }

    printf("%s\n", str->data);
    string_free(str);
    
    return 0;
}