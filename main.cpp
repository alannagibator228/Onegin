#include <stdio.h>
#include <stdlib.h>
#include "create_array.h"
#include "print_text.h"  
#include "sorting.h"

int main()
{
    ParsedText Text;

    const char* name_file_for_read = "stan.txt";
    const char* name_file_for_write = "for_answer.txt";

    create_array_of_pointers(&Text, (const char*) name_file_for_read);
    print_answer_in_file(&Text, name_file_for_write);

    free(Text.array_of_pointers);
    free(Text.buffer);

    return 0;
}