#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include "create_array.h"
//-lasan -fsanitize=address -ggdb3

void create_array_of_pointers(ParsedText* Text, const char* name_file_for_read)
{
    assert(Text != NULL);                 //TODO assert

    FILE *file = NULL;

    if ((file=fopen(name_file_for_read, "r")) == NULL)
    {
        perror("Cannot open file for read.\n");
    }
    
    
    write_in_buffer(Text, file);

    count_lines_and_change_newline_to_zero(Text);

    allocate_mem_for_array (Text);
    write_pointers_and_len_str (Text);

    fclose (file);
}

void write_in_buffer(ParsedText* Text, FILE* file)   
{
    assert(Text != NULL);      //TODO assert
    assert(file != NULL);

    struct stat file_inf;
    fstat (fileno (file), &file_inf); 
    Text->size = file_inf.st_size; 
    size_t size_plus_byte = Text->size + 1;
    
    Text->buffer = (char*) calloc(size_plus_byte, sizeof(char)); 

    assert(Text->buffer != NULL);   //TODO assert
    
    fread(Text->buffer, sizeof(char), Text->size, file);
    (Text->buffer)[Text->size] = '\n';
}

void count_lines_and_change_newline_to_zero (ParsedText* Text)
{
    assert(Text != NULL);                  //TODO assert
    assert(Text->buffer != NULL);

    Text->length = 0;
    for (size_t index = 0; index < Text->size + 1; index++)  
    {
        if((Text->buffer)[index] == '\n')
        {
            (Text->buffer)[index] = '\0';
            Text->length++;
        }
    }
}

void allocate_mem_for_array (ParsedText* Text)
{
    assert(Text != NULL); // TODO assert

    (Text->array_of_pointers) = (char**) calloc(Text->length, sizeof(char*));    //TODO почитать как она работает 
    (Text->len_str)           = (int*)   calloc(Text->length, sizeof(int));
}

void write_pointers_and_len_str (ParsedText* Text)
{
    assert(Text != NULL);                           //TODO assert
    assert(Text->array_of_pointers != NULL);
    assert(Text->buffer != NULL);

    (Text->array_of_pointers)[0] = (Text->buffer);                        
    int index_for_array = 1;
    int len_str = 0;
    for (size_t index = 0; index < Text->size; index++)  
    {
        len_str++;
        if((Text->buffer)[index] == '\0')
        {
            (Text->array_of_pointers)[index_for_array] = (Text->buffer) + index + 1;
            (Text->len_str)[index_for_array-1] = len_str;
            len_str = 0;
            index_for_array++;
        }
    }
}