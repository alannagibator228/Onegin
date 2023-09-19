#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include "create_array.h"
#include "print_text.h"
//-lasan -fsanitize=address -ggdb3

void create_array_of_pointers(ParsedText *Text)
{
    assert(Text != NULL);

    count_lines_and_change_newline_to_zero(Text);

    allocate_mem_for_array(Text);
    write_pointers_and_len_str(Text);
}

void write_in_buffer(ParsedText *Text, const char *name_file_for_read)
{
    assert(Text != NULL);
    FILE *file = NULL;

    if ((file = fopen(name_file_for_read, "r")) == NULL)
    {
        perror("Cannot open file for read.\n");
    }

    struct stat file_inf;
    fstat(fileno(file), &file_inf);
    Text->size = file_inf.st_size;
    size_t size_plus_byte = Text->size + 1;

    Text->buffer = (char *)calloc(size_plus_byte, sizeof(char));

    assert(Text->buffer != NULL);

    fread(Text->buffer, sizeof(char), Text->size, file);
    (Text->buffer)[Text->size] = '\n';

    fclose(file);
}

void count_lines_and_change_newline_to_zero(ParsedText *Text)
{
    assert(Text != NULL);
    assert(Text->buffer != NULL);

    Text->length = 0;
    for (size_t index = 0; index < Text->size + 1; index++)
    {
        if ((Text->buffer)[index] == '\n')
        {
            (Text->buffer)[index] = '\0';
            Text->length++;
        }
    }
}

void allocate_mem_for_array(ParsedText *Text)
{
    assert(Text != NULL);

    (Text->array_of_pointers) = (char **)calloc(Text->length, sizeof(char *));
    (Text->len_str) = (int *)calloc(Text->length, sizeof(int));

    assert(Text->array_of_pointers != NULL);
    assert(Text->len_str != NULL);
}

void write_pointers_and_len_str(ParsedText *Text)
{
    assert(Text != NULL);
    assert(Text->array_of_pointers != NULL);
    assert(Text->buffer != NULL);

    (Text->array_of_pointers)[0] = (Text->buffer);
    int index_for_array = 1;
    int len_str = 1;
    (Text->len_str)[index_for_array - 1] = len_str - 1;
    for (size_t index = 1; index < Text->size; index++)
    {
        if ((Text->buffer)[index] == '\0')
        {
            (Text->array_of_pointers)[index_for_array] = (Text->buffer) + index + 1;
            len_str = 0;
            index_for_array++;
        }
        else
        {
            len_str++;
            (Text->len_str)[index_for_array - 1] = len_str - 1;
        }
    }
    (Text->len_str)[index_for_array - 1] = len_str;
}