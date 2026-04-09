#include <stdio.h>
#include <stdlib.h>
#include "sstrings.h"

int main() {
    String* const str = string_from_char("El desempleado final boss");
    if (str == nullptr) {
        perror("Error allocating memory for String");
        exit(EXIT_FAILURE);
    }


    String* const append = string_append_char(str, " esta muy entretenido");
    if (append == nullptr) {
        perror("Error reallocating memory for String");
        string_free(str);
        exit(EXIT_FAILURE);
    }


    String* const concat = string_concat_char(append, " intentando recrear objetos strings");
    if (concat == nullptr) {
        perror("Error reallocating memory for String");
        string_free(append);
        exit(EXIT_FAILURE);
    }


    // `str` here is not more needed since `concat` is a new string object
    string_free(append); // `append` its the same pointer than `str`

    printf("%s\n", concat->data);
    string_free(concat);
    return 0;
}
