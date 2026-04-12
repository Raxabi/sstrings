#include <stdio.h>
#include <stdlib.h>
#include "sstrings.h"

int main() {
    String* const str = string_from_char("Unemployed final boss");
    if (str == nullptr) {
        perror("Error allocating memory for String");
        return EXIT_FAILURE;
    }

    printf("Before appending: %s\n", str->data);

    if (!string_append_char(str, " is enjoying very much doing a String object implementation in pure C language")) {
        perror("Error reallocating memory for String");
        string_free(str);
        return EXIT_FAILURE;
    }

    printf("After appending: %s\n", str->data);
    string_free(str);

    return 0;
}
