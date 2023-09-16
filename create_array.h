#ifndef CREATE_ARRAY
#define CREATE_ARRAY

#define INVALID_LENGTH -1

typedef struct 
{
    char** array_of_pointers;
    int length;

    char* buffer;
    size_t size;
    int* len_str;
} ParsedText;

void create_array_of_pointers (ParsedText* Text, const char* name_file_for_read);

void write_in_buffer (ParsedText* Text, FILE* file);
void count_lines_and_change_newline_to_zero (ParsedText* Text); 

void allocate_mem_for_array (ParsedText* Text);
void write_pointers_and_len_str (ParsedText* Text);


#define MAX(a,b) a > b ? a : b;
// MAX(3,4);


#endif