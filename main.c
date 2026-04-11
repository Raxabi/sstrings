#include <stdio.h>
#include <stdlib.h>

#include "sstrings.h"

int main() {
    String* const str = string_from_char("El desempleado final boss");
    if (str == nullptr) {
        perror("Error allocating memory for String");
        exit(EXIT_FAILURE);
    }


    if (!string_append_char(str, " esta muy entretenido")) {
        perror("Error reallocating memory for String");
        string_free(str);
        exit(EXIT_FAILURE);
    }


    String* const concat = string_concat_char(str, " intentando recrear objetos strings");
    if (concat == nullptr) {
        perror("Error reallocating memory for String");
        string_free(str);
        exit(EXIT_FAILURE);
    }


    string_free(str);
    printf("%s\n\n", concat->data);
    string_free(concat);


    String* const sized = string_from_size(50);
    if (!string_append_char(sized, "Counter straik ofensiva global hecho por valve xdd")) {
        perror("Error reallocating memory for String");
        string_free(sized);
        exit(EXIT_FAILURE);
    }
    printf("String: %s\nLength: %lld, Left size: %lld\n\n", sized->data, sized->len, sized->size - sized->len);
    string_free(sized);

    String* const my_str = string_from_char("Puta#mierda_64");
    printf("%s\n", my_str->data);

    String* slice = string_slice(my_str, 2, 5);
    if (!slice) {
        perror("Bad ranges when slicing");
        string_free(sized);
        exit(EXIT_FAILURE);
    }

    printf("%s\n", slice->data);

    string_free(slice);
    string_free(my_str);
    return 0;
}
