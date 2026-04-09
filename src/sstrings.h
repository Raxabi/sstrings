#pragma once

#include <stddef.h>

#ifdef __STDC_VERSION__
  #if __STDC_VERSION__ < 202311L
    #define nullptr NULL
  #endif
#endif

#define SSTRINGS_VERSION 100

typedef struct {
    char* data; // chunk of data
    size_t len; // Size in bytes not counting the null terminator
    size_t size; // Size in bytes
} String;

/// @brief Deallocates the memory of a previously allocated `String` object
/// @param string `String` object being deallocated
void string_free(String* string);

/// @brief Creates a new `String` object with the specified `size`
/// @param size Size in bytes for holding string contents
/// @return A new empty `String` object with the specified `size`
String* const string_from_size(size_t size);

/// @brief Creates a new `String` object whose data will be the contents of `content`
/// @param content string beign added as contents of the resulting `String` object
/// @return A new `String` object whose data will be the same than `content`
String* const string_from_char(char const* content);

/// @brief Modifies `dest` appending the contents of `src` at the end of `dest->data`
/// @param dest `String` object where `src` will be added
/// @param src string content to be added into `dest->data`
/// @return Same pointer than `dest`
String* const string_append_char(String* const dest, char const* src);

/// @brief Modifies `dest->data` appending at the end the contents of `src->data`
/// @param dest `String` object where `src->data` will be added
/// @param src `String` object whose data field will be copied into `dest->data`
/// @return Same pointer than `dest`
String* const string_append_string(String* const dest, String* const src);

/// @brief Creates a new `String` object result of appends the content of `src` into `String::data`
/// @param s1 `String` object which will receive all the characters of `src`
/// @param c1 string containing the chars being concatenated into `og->data`
/// @return A new string joining the contents of `og->data` and `src` in one single `String` object
String* const string_concat_char(String* const s1, char const* c1);

/// @brief Creates a new `String` object result of appends the content of `src->data` into `og->data`
/// @param og `String` object which will receive all the characters of `src`
/// @param src `String` object whose data will be concatenated into `og->data`
/// @return A new string joining the contents of `og->data` and `src->data` in one unique `String` object
String* const string_concat_string(String* const og, String* const src);
