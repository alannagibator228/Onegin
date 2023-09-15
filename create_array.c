#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "create_array.h"
//-lasan -fsanitize=address -ggdb3

int create_array_of_pointers(char*** array, char ** buffer)
{
    FILE *file;
    
    if ((file=fopen("stan.txt", "rb")) == NULL)
    {
    printf("Cannot open file.\n");
    }
    
    
    size_t size_without_plus_byte = write_in_buffer(file, buffer);
    size_t size_plus_byte = size_without_plus_byte + 1;

    change_newline_to_zero(buffer, size_plus_byte);

    int length = allocate_mem_for_array (array, buffer, size_without_plus_byte);
    write_in_array (array, buffer, size_without_plus_byte);

    fclose (file);
    return length;
}

size_t write_in_buffer(FILE* file, char** buffer)
{
    struct stat file_inf;
    fstat (fileno (file), &file_inf); 
    size_t size_without_plus_byte = file_inf.st_size; 
    size_t size_plus_byte = size_without_plus_byte + 1;
    
    *buffer = (char*) calloc(size_plus_byte, sizeof(char)); 
    
    fread(*buffer, sizeof(char), size_without_plus_byte, file);
    (*buffer)[size_plus_byte - 1] = '\n';

    return size_without_plus_byte;
}

int allocate_mem_for_array (char*** array, char** buffer, size_t size_without_plus_byte)
{
    int length = 1;
    for (size_t index = 1; index < size_without_plus_byte; index++)  
    {
        if((*buffer)[index] == '\0')                
        {
            length++;
        }
    }
    *array = (char**) calloc(length, sizeof(char*));
    return length;
}

void write_in_array (char*** array, char** buffer, size_t size_without_plus_byte)
{
    (*array)[0] = *buffer;                        
    int index_for_array = 1;
    for (size_t index = 0; index < size_without_plus_byte; index++)  
    {
        if((*buffer)[index] == '\0')
        {
            (*array)[index_for_array] = *buffer + index + 1;
            index_for_array++;
        }
    }
}

void change_newline_to_zero (char** buffer, size_t size_plus_byte)
{
    for (size_t index = 0; index < size_plus_byte; index++)  
    {
        if((*buffer)[index] == '\n')
        {
            (*buffer)[index] = '\0';
        }
    }
}

