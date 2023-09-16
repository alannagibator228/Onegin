#ifndef PRINT_TEXT
#define PRINT_TEXT
#include "create_array.h"

void print_text (Onegin examination);
void print_answer_in_file(Onegin examination, const char* name_file_for_write);
void print_text_in_file (Onegin examination, FILE* file);
void print_decor_division(FILE* file);

#endif