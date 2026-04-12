#include <stdio.h>
#include <stdlib.h>
#include "sstrings.h"

int main() {
    String* const str = string_from_char("This is a test");

    String* const concat = string_concat_char(str, " of my String objects implementation");
    if (concat == nullptr) {
        perror("Error reallocating memory for String");
        string_free(str);
        return EXIT_FAILURE;
    }

    printf("Original: %s\n", str->data);
    printf("Concatenated: %s\n", concat->data);

    free(str);
    free(concat);

    return 0;
}
