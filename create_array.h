#ifndef CREATE_ARRAY
#define CREATE_ARRAY

#define INVALID_LENGTH -1

typedef struct 
{
    char** array_of_pointers;
    int length;

    char* buffer;
    size_t size;
} Onegin;

void create_array_of_pointers (Onegin* examination, const char* name_file_for_read);

void write_in_buffer (Onegin* examination, FILE* file);
void count_lines_and_change_newline_to_zero (Onegin* examination);

void allocate_mem_for_array (Onegin* examination);
void write_in_array (Onegin* examination);


#define MAX(a,b) a > b ? a : b;
// MAX(3,4);


#endif