#ifndef CREATE_ARRAY   ////TODO погуглить зачем это
#define CREATE_ARRAY

int create_array_of_pointers (char*** array, char** buffer);  //TODO убрать лишние *
size_t write_in_buffer (FILE* file, char** buffer);
int allocate_mem_for_array (char*** array, char** buffer, size_t size_without_plus_byte);
void write_in_array (char*** array, char** buffer, size_t size_without_plus_byte);

void change_newline_to_zero (char** buffer, size_t size_plus_byte);


#define MAX(a,b) a > b ? a : b;
// MAX(3,4);


#endif