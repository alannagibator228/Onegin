#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    char** array = NULL;
    char* buffer = NULL;
    
    int length = create_array_of_pointers(&array, &buffer);

    print_text(array, length);
    
    free(array);
    free(buffer);

    return 0;
}