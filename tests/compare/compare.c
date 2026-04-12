#include <stdio.h>
#include <stdlib.h>
#include "sstrings.h"

int main() {
    String* const s1 = string_from_char("Hello, World!");
    if (!s1) {
        perror("Memory allocation failed when creating String object");
        return EXIT_FAILURE;
    }

    String* const s2 = string_from_char("Hello, World!");
    if (!s2) {
        perror("Memory allocation failed when creating String object");
        string_free(s1);
        return EXIT_FAILURE;
    }

    // This should shows: "failed" as program output
    printf("Comparison: %s\n", string_compare(s1, s2) ? "sucessfully" : "failed");
    string_free(s1);
    string_free(s2);

    return 0;
}
