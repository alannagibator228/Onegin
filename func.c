#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <math.h>
#include <ctype.h>      
#include "func.h"
//-lasan -fsanitize=address -ggdb3

int create_array_of_pointers(char*** array, char ** buffer)
{
    FILE *file;
    
    if ((file=fopen("Slim.txt", "rb")) == NULL)
    {
    printf("Cannot open file.\n");
    }
    
    
    size_t size_without_plus_byte = write_in_buffer(file, buffer);
    size_t size_plus_byte = size_without_plus_byte + 1;

    change_newline_to_zero(buffer, size_plus_byte);

    int length = memory_for_array (array, buffer, size_without_plus_byte);
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

int memory_for_array (char*** array, char** buffer, size_t size_without_plus_byte)
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

void print_text(char** array, int length)
{
    for (int line_num = 0; line_num < length; line_num++)
    {
        printf("%s\n", array[line_num]);
    }
}

void print_in_file(char** array, int length)
{
    FILE *file;
    
    if ((file=fopen("slimwrite.txt", "w")) == NULL)
    {
    printf("Cannot open file.\n");
    }

    for (int line_num = 0; line_num < length; line_num++)
    {
        fprintf(file, "%s\n", array[line_num]);
    }
    fclose (file);
}

int sor_cmp(const void* str1, const void* str2)
{
    char* str_1 = *(char**) str1;
    char* str_2 = *(char**) str2;

    return str_cmp(str_1, str_2);
}

int str_cmp(const char* str1, const char* str2)
{
    int len_str1 = str_len(str1);
    int len_str2 = str_len(str2);
    int len = fmin(len_str1, len_str2);

    int symbol_num_1 = 0;
    int symbol_num_2 = 0;

    while (symbol_num_1 < len && symbol_num_2 < len)
    {
        if(!isalpha(str1[symbol_num_1]))
        {
            symbol_num_1++;
        }
        else if(!isalpha(str2[symbol_num_2]))
        {
            symbol_num_2++;
        }
        else if(str1[symbol_num_1] != str2[symbol_num_2])
        {
            return (str1[symbol_num_1] - str2[symbol_num_2]);
        }
        else
        {
        symbol_num_1++;
        symbol_num_2++;
        }
    }
    return (len_str1 - len_str2);
}

int str_len (const char* string)
{
    int symbol_num = 0;
    while (string[symbol_num] != '\0')
    {
        symbol_num++;
    }
    return symbol_num;
}