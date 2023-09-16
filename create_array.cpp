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
        printf("Cannot open file.\n");   //TODO perror
    }
    
    
    write_in_buffer(examination, file);

    change_newline_to_zero(examination);

    allocate_mem_for_array (examination);
    write_in_array (examination);

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

void change_newline_to_zero (Onegin* examination)
{
    for (size_t index = 0; index < examination->size + 1; index++)  
    {
        if((examination->buffer)[index] == '\n')
        {
            (examination->buffer)[index] = '\0';
        }
    }
}

void allocate_mem_for_array (Onegin* examination)
{
    examination->length = 1;
    for (size_t index = 1; index < examination->size; index++)  
    {
        if((examination->buffer)[index] == '\0')                //TODO зарание записать их количество
        {
            examination->length++;
        }
    }
    (examination->array_of_pointers) = (char**) calloc(examination->length, sizeof(char*));    //TODO почитать как она работает 
}

void write_in_array (Onegin* examination)
{
    (examination->array_of_pointers)[0] = (examination->buffer);                        
    int index_for_array = 1;
    for (size_t index = 0; index < examination->size; index++)  
    {
        if((examination->buffer)[index] == '\0')
        {
            (examination->array_of_pointers)[index_for_array] = (examination->buffer) + index + 1;
            index_for_array++;
        }
    }
}