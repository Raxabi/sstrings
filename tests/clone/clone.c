#include <stdio.h>
#include <stdlib.h>
#include "sstrings.h"

int main() {
    String* const s1 = string_from_size(50);
    if (!s1) {
        perror("Error creating the String");
        return EXIT_FAILURE;
    }

    if (!string_append_char(s1, "Counter Strike 2, its a videogame developed by Valve")) {
        perror("Error reallocating memory for String");
        string_free(s1);
        return EXIT_FAILURE;
    }

    String* const s2 = string_clone(s1);
    if (!s2) {
        perror("String clone could not be possible");
        string_free(s1);
        return EXIT_FAILURE;
    }

    printf("Addr: %p\tdata: %s\tlen: %lld\tsize: %lld\n", s1, s1->data, s1->len, s1->size);
    printf("Addr: %p\tdata: %s\tlen: %lld\tsize: %lld\n", s2, s2->data, s2->len, s2->size);

    if (!string_append_char(s2, ". Also Half-Life, which is a FPS game")) {
        perror("Error reallocating memory for String");
        string_free(s1);
        return EXIT_FAILURE;
    }

    printf("Addr: %p\tdata: %s\tlen: %lld\tsize: %lld\n", s2, s2->data, s2->len, s2->size);

    string_free(s1);
    string_free(s2);
    return 0;
}