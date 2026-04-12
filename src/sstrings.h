#pragma once

#include <stddef.h>

#ifdef __STDC_VERSION__
  #if __STDC_VERSION__ < 202311L
    #define nullptr NULL
  #endif
#endif

#define SSTRINGS_VERSION 100
#define SSTRINGS_NULL_CHAR 0x0

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
String* string_from_size(size_t size);

/// @brief Creates a new `String` object whose data will be the contents of `content`
/// @param content string beign added as contents of the resulting `String` object
/// @return A new `String` object whose data will be the same than `content`
String* string_from_char(char const* content);

/// @brief Modifies `dest` appending the contents of `src` at the end of `dest->data`
/// @param dest `String` object where `src` will be added
/// @param src string content to be added into `dest->data`
/// @return Same pointer than `dest`
/// @note If `src` take up more memory than `dest->data`, the reallocation may reserve some extra memory avoiding make more reallocations in the future
String* string_append_char(String* const dest, char const* src);

/// @brief Modifies `dest->data` appending at the end the contents of `src->data`
/// @param dest `String` object where `src->data` will be added
/// @param src `String` object whose data field will be copied into `dest->data`
/// @return Same pointer than `dest`
/// @note If `src->data` take up more memory than `dest->data`, the reallocation may reserve some extra memory avoiding make more reallocations in the future
String* string_append_string(String* const dest, String* const src);

/// @brief Creates a new `String` object result of appends the content of `src` into `String::data`
/// @param s1 `String` object which will receive all the characters of `src`
/// @param c1 string containing the chars being concatenated into `og->data`
/// @return A new string joining the contents of `s1->data` and `c1` in one single `String` object
String* string_concat_char(String* const s1, char const* c1);

/// @brief Creates a new `String` object result of appends the content of `src->data` into `og->data`
/// @param og `String` object which will receive all the characters of `src`
/// @param src `String` object whose data will be concatenated into `og->data`
/// @return A new string joining the contents of `og->data` and `src->data` in one unique `String` object
String* string_concat_string(String* const s1, String* const s2);

/// @brief Takes a slice of the data allocated in `s1->data`
/// @param s1 `String` object where the data is allocated
/// @param from Initial position from which the slice has to began (starts counting from 0 since strings are arrays)
/// @param until How many characters the resulted slice should have from the `from` position (counting from 0 since strings are arrays)
/// @return A new `String` object whose data is a slice of `s1->data` between `from` and `until` values. `nullptr` if `from` is lowest than `0` or if `until` is greater than `s1->len`
String* string_slice(String* const s1, size_t from, size_t until);

/// @brief Makes a slice from the start of the `String` contained data (`s1->data`) until the end of the data
/// @param s1 `String` object where the data is allocated
/// @param from Initial position from which the slice has to began
/// @return A new `String` object whose data is a slice of `s1->data` between `from` and `until` values. `nullptr` if `from` is lowest than `0`
String* string_slice_from(String* const s1, size_t from);

/// @brief Makes a slice from the start of the `String` contained data (`s1->data`) until the end of the data
/// @param s1 `String` object where the data is allocated
/// @param until How many characters the resulted slice should have from the start position (not counting from 0, since bytes are counted instead of positions)
/// @return A new `String` object whose data is a slice of `s1->data` between `from` and `until` values. `nullptr` if `from` is lowest than `0`
String* string_slice_until(String* const s1, size_t until);

/// @brief Compares contents of `s1->data` with `s2->data`
/// @param s1 `String` object being compared
/// @param s2 `String` object being compared against `s1`
/// @return `false` if `s1->len` and `s2->len` are not the same or if its contents are not the same. `true` otherwise
bool string_compare(String* const s1, String* const s2);

/// @brief Makes the `String` object data be setted to 0
/// @param string `String` object containing the data which want to be putted to 0
/// @return The same `String` object pointed to by `string`
String* string_clear(String* const string);
