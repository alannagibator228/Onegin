#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    char** array = NULL;
    char* buffer = NULL;
    
    int length = create_array_of_pointers(&array, &buffer);

    qsort(array, length, sizeof(char*), sor_cmp); 
    print_text(array, length);
    print_in_file(array, length);

    free(array);
    free(buffer);

    return 0;
}