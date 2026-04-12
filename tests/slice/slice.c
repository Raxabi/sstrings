#include <stdio.h>
#include <stdlib.h>
#include "sstrings.h"

int main() {
    String* const s1 = string_from_char("Hello_World!");
    if (!s1) {
        perror("Failed allocating memory when creating String object");
        return EXIT_FAILURE;
    }

    // We want to slice the string (`s1->data`) from the start until the first 'o' letter
    // Remember that the values when slicing a string are index based
    String* const slice = string_slice_until(s1, 4);
    if (!slice) {
        perror("Bad ranges or memory allocation failed when creating String object");
        string_free(s1);
        return EXIT_FAILURE;
    }

    String* const slice2 = string_slice_from(s1, 6);
    if (!slice2) {
        perror("Bad ranges or memory allocation failed when creating String object");
        string_free(s1);
        string_free(slice);
        return EXIT_FAILURE;
    }

    // The output should be 'Hello'
    printf("%s\n", slice->data);
    // the output should be 'World'
    printf("%s\n\n", slice2->data);

    if (!string_append_char(slice, ", ")) {
        perror("Memory reallocation failed when trying to grow the string");
        string_free(s1);
        string_free(slice);
        string_free(slice2);
        return EXIT_FAILURE;
    }

    String* const helloWorld = string_concat_string(slice, slice2);
    if (!helloWorld) {
        perror("Bad ranges or memory allocation failed when creating String object");
        string_free(s1);
        string_free(slice);
        string_free(slice2);
        return EXIT_FAILURE;
    }

    string_free(s1);
    string_free(slice);
    string_free(slice2);

    // `s1` and `slice` are not needed anymore since `string_concat_...` creates a new string
    // joining both objects received as parameters
    printf("Concatenation: %s\n", helloWorld->data);
    string_free(helloWorld);

    return 0;
}
