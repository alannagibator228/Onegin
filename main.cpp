#include <stdio.h>
#include <stdlib.h>
#include "create_array.h"
#include "print_text.h"  
#include "sorting.h"

// TODO Add more types of sort.

int main()
{
    Onegin examination;

    const char* name_file_for_read = "stan.txt";
    const char* name_file_for_write = "for_answer.txt";

    create_array_of_pointers(&examination, (const char*) name_file_for_read);
    print_answer_in_file(examination, name_file_for_write);

    free(examination.array_of_pointers);
    free(examination.buffer);

    return 0;
}