#include <stdio.h>
#include "sstrings.h"

int main() {
    String* const s1 = string_from_char("Hello World!");
    String* const s2 = string_from_char("Hello, World!");

    // This should shows: "failed" as program output
    printf("Comparison: %s\n", string_compare(s1, s2) ? "correct" : "failed");

    return 0;
}