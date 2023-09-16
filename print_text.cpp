#include <stdio.h>
#include <stdlib.h>
#include "print_text.h"
#include "sorting.h"
#include "create_array.h"

void print_text(Onegin examination)
{
    for (int line_num = 0; line_num < examination.length; line_num++)
    {
        printf("%s\n", (examination.array_of_pointers)[line_num]);
    }
}

void print_answer_in_file(Onegin examination, const char* name_file_for_write)
{
    FILE *file;

    if ((file = fopen(name_file_for_write, "w")) == NULL)
    {
    printf("Cannot open file.\n");
    }

    print_text_in_file (examination, file);

    print_decor_division(file);

    qsort(examination.array_of_pointers, examination.length, sizeof(char*), sor_cmp);
    print_text_in_file (examination, file);

    print_decor_division(file);

    qsort(examination.array_of_pointers, examination.length, sizeof(char*), sor_cmp_rhyme);
    print_text_in_file (examination, file);

    fclose (file);
}

void print_text_in_file (Onegin examination, FILE* file)                //TODO оптимизировать вывод
{
    for (int line_num = 0; line_num < examination.length -1; line_num++)
    {

        if (!((str_len((examination.array_of_pointers)[line_num]) <= 1) && ((examination.array_of_pointers)[line_num][0] == '\0')))
        {
            fprintf(file, "%70s\n", (examination.array_of_pointers)[line_num]);
        }
    }     
}

void print_decor_division(FILE* file)
{
    "hellow "
    "world!";

    fprintf(file, "\n\n\n\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n\n\n");
}