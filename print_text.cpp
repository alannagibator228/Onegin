#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "print_text.h"
#include "sorting.h"
#include "create_array.h"

void print_text(ParsedText *Text)
{
    assert(Text->length >= 0);

    for (int line_num = 0; line_num < Text->length; line_num++)
    {
        printf("%s\n", (Text->array_of_pointers)[line_num]);
    }
}

void print_unsorted_text_in_file(ParsedText *Text, const char *name_file_for_write)
{
    assert(name_file_for_write != "");
    assert(Text->buffer != NULL);
    assert(Text->size >= 0);

    FILE *file;

    if ((file = fopen(name_file_for_write, "a")) == NULL)
    {
        perror("Cannot open file for answer.\n");
    }
    
    fwrite(Text->buffer, sizeof(char), Text->size, file);

    fclose(file);
}

void print_answer_in_file(ParsedText *Text, const char *name_file_for_write)
{
    assert(name_file_for_write != "");
    assert(Text->array_of_pointers != NULL);
    assert(Text->length >= 0);

    FILE *file;

    if ((file = fopen(name_file_for_write, "w")) == NULL)
    {
        perror("Cannot open file for answer.\n");
    }

    selection_sort(Text, str_cmp);
    print_text_in_file(Text, file);

    print_decor_division(file);

    selection_sort(Text, str_cmp_rhyme);
    print_text_in_file(Text, file);

    print_decor_division(file);

    fclose(file);
}

void print_text_in_file(ParsedText *Text, FILE *file) // TODO оптимизировать вывод
{
    assert(file != NULL);
    assert(Text->array_of_pointers != NULL);
    assert(Text->length >= 0);

    for (int line_num = 0; line_num < Text->length; line_num++)
    {

        if (!((str_len((Text->array_of_pointers)[line_num]) <= 1) && ((Text->array_of_pointers)[line_num][0] == '\0')))
        {
            fwrite(Text->array_of_pointers[line_num], sizeof(char), Text->len_str[line_num], file);
            fprintf(file, "\n");
        }
    }
}

void print_decor_division(FILE *file)
{
    "hellow "
    "world!";

    fprintf(file, "\n\n\n\n////////////////////////////////////////////////////////////////////////////////////////////////\n"
                          "////////////////////////////////////////////////////////////////////////////////////////////////\n"
                          "////////////////////////////////////////////////////////////////////////////////////////////////\n"
                          "////////////////////////////////////////////////////////////////////////////////////////////////\n"
                          "////////////////////////////////////////////////////////////////////////////////////////////////\n"
                          "////////////////////////////////////////////////////////////////////////////////////////////////\n"
                          "////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n\n\n");
}