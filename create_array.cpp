#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "create_array.h"
//-lasan -fsanitize=address -ggdb3

void create_array_of_pointers(Onegin* examination, const char* name_file_for_read)
{
    FILE *file = NULL;

    if ((file=fopen(name_file_for_read, "r")) == NULL)
    {
        perror("Cannot open file for read.\n");
    }
    
    
    write_in_buffer(examination, file);

    count_lines_and_change_newline_to_zero(examination);

    allocate_mem_for_array (examination);
    write_pointers_and_len_str (examination);

    fclose (file);
}

void write_in_buffer(Onegin* examination, FILE* file)            //TODO везде проверять входные аргументы
{
    struct stat file_inf;
    fstat (fileno (file), &file_inf); 
    examination->size = file_inf.st_size; 
    size_t size_plus_byte = examination->size + 1;
    
    examination->buffer = (char*) calloc(size_plus_byte, sizeof(char)); 
    
    fread(examination->buffer, sizeof(char), examination->size, file);
    (examination->buffer)[examination->size] = '\n';
}

void count_lines_and_change_newline_to_zero (Onegin* examination)
{
    examination->length = 0;
    for (size_t index = 0; index < examination->size + 1; index++)  
    {
        if((examination->buffer)[index] == '\n')
        {
            (examination->buffer)[index] = '\0';
            examination->length++;
        }
    }
}

void allocate_mem_for_array (Onegin* examination)
{
    (examination->array_of_pointers) = (char**) calloc(examination->length, sizeof(char*));    //TODO почитать как она работает 
    (examination->len_str)           = (int*)   calloc(examination->length, sizeof(int));
}

void write_pointers_and_len_str (Onegin* examination)
{
    (examination->array_of_pointers)[0] = (examination->buffer);                        
    int index_for_array = 1;
    int len_str = 0;
    for (size_t index = 0; index < examination->size; index++)  
    {
        len_str++;
        if((examination->buffer)[index] == '\0')
        {
            (examination->array_of_pointers)[index_for_array] = (examination->buffer) + index + 1;
            (examination->len_str)[index_for_array-1] = len_str;
            len_str = 0;
            index_for_array++;
        }
    }
}