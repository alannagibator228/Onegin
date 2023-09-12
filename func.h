#ifndef FUNC_H
#define FUNC_H

int create_array_of_pointers (char*** array, char** buffer);
int write_in_buffer (FILE* file, char** buffer);
int memory_for_array (char*** array, char** buffer, int size_without_plus_byte);
void write_in_array (char*** array, char** buffer, int size_without_plus_byte);

void change_newline_to_zero (char** buffer, int size_plus_byte);

void print_text (char** array, int length);

int sor_cmp(const void* str1, const void* str2);
int str_cmp(const char* str1, const char* str2);

#endif