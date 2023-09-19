#ifndef PRINT_TEXT
#define PRINT_TEXT
#include "create_array.h"

void print_text(ParsedText *Text);
void print_unsorted_text_in_file(ParsedText *Text, const char *name_file_for_write);
void print_answer_in_file(ParsedText *Text, const char *name_file_for_write);
void print_text_in_file(ParsedText *Text, FILE *file);
void print_decor_division(FILE *file);

#endif