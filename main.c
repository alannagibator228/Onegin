#include <stdio.h>
#include <stdlib.h>
#include "create_array.h"
#include "print_text.h"  
#include "sorting.h"

// TODO Add more types of sort.

int main()
{
    char** array = NULL;  //TODO array не понятно что это     и засунуть всё в структуру
    char* buffer = NULL;
    
    int length = create_array_of_pointers(&array, &buffer);
    print_answer_in_file(array, length);

    free(array);
    free(buffer);

    return 0;
}