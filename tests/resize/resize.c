#include <stdio.h>
#include <stdlib.h>
#include "sstrings.h"

int main() {
    String* const sized = string_from_size(50);
    if (!sized) {
        perror("Error creating the String");
        return EXIT_FAILURE;
    }

    // because of the new appended content, the size of `sized` should has been increased
    //
    // Note: the new size may not match with the sum of `sized->size` + [size of the appended string]
    // because dependending on the appended content, the allocated size may be higher than the expect
    // in favour to avoid some extra reallocations
    if (!string_append_char(sized, "Counter Strike 2, its a videogame developed by Valve")) {
        perror("Error reallocating memory for String");
        string_free(sized);
        return EXIT_FAILURE;
    }

    printf("String: %s\nLength: %lld, Size: %lld, Left size: %lld\n\n", sized->data, sized->len, sized->size, sized->size - sized->len);
    string_free(sized);

    return 0;
}