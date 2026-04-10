// Unemployed final boss proyect, create my own string object implementation

#include <string.h>
#include <stdlib.h>

#include "sstrings.h"

inline void string_free(String* string) {
    free(string->data);
    free(string);
}

String* const string_from_size(size_t size) {
    String* const string = malloc(sizeof(String));
    if (string == nullptr)
        return nullptr;
    
    char* data = malloc(size);
    if (data == nullptr) {
        string_free(string);
        return nullptr;
    }

    string->data = data;
    string->len  = 0;
    string->size = size;
    // `string->len` is 0 because it represents the length in bytes until the null terminator
    // then, in absence of any char in our initialized memory, we left it to 0
    return string;
}

String* const string_from_char(char const* content) {
    size_t len  = strlen(content);
    size_t size = len + 1;
    String* const string = string_from_size(size);
    if (string == nullptr)
        return nullptr;

    memcpy(string->data, content, size);
    string->len = len;
    return string;
}

/// @brief This function acts as a helper because calling it require to pass the `src` length (without null terminator)
/// @brief In this way, there are fewer calls to `strlen` which is a O(N) complexity function
/// @param dest `String` object where `src` will be added
/// @param src string content to be added into `dest->data`
/// @param src_len pre-computed size (in bytes) of `src` without counting the null terminator
/// @return Same pointer than `dest`
static String* const string_append_helper(String* const dest, char const* src, size_t src_len) {
    size_t src_size = src_len + 1; // This value holds the byte for the null terminator

    char* tmp = realloc(dest->data, dest->size + src_len);
    if (tmp == nullptr)
        return nullptr;

    // In case where previously allocated memory can not grow anymore in its assigned region
    dest->data = tmp;

    // Gets the position of the null character of `dest` String, then `memcpy` will overlap it by the first character of `src`
    char* dest_ends = dest->data + dest->len;

    // Updates the values in `dest`
    memcpy(dest_ends, src, src_size);
    dest->size += src_len;
    dest->len  += src_len;
    return dest;
}

inline String* const string_append_char(String* const dest, char const* src) {
    size_t src_len = strlen(src);
    return string_append_helper(dest, src, src_len);
}

inline String* const string_append_string(String* const dest, String* const src) {
    return string_append_helper(dest, src->data, src->len);
}

/// @brief This function acts as a helper because calling it require to pass the `src` length (without null terminator)
/// @brief In this way, there are fewer calls to `strlen` which is a O(N) complexity function
/// @param s1 `String` object where `src` will be added
/// @param c1 string content to be added into `s1->data`
/// @param c1_len pre-computed size (in bytes) of `c1` without counting the null terminator
/// @return A new string joining the contents of `s1->data` and `c1` in one single `String` object
static String* const string_concat_helper(String* const s1, char const* c1, size_t c1_len) {
    size_t c1_size = c1_len + 1;

    size_t size = s1->size + c1_len; // adding 1 is not needed since `s1->size` already holds the extra byte for the null terminator
    String* const string = string_from_size(size);
    if (string == nullptr)
        return nullptr;

    // Resolves the position where `c1` should be concatenated
    char* string_ends = string->data + s1->len;
    memcpy(string->data, s1->data, s1->size);
    memcpy(string_ends, c1, c1_size);

    return string;
}

inline String* const string_concat_char(String* const s1, char const* c1) {
    size_t c1_len = strlen(c1);
    return string_concat_helper(s1, c1, c1_len);
}

inline String* const string_concat_string(String* const s1, String* const s2) {
    return string_concat_helper(s1, s2->data, s2->len);
}
