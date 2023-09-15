#include <stdio.h>
#include <stdlib.h>
#include "print_text.h"
#include "sorting.h"

void print_text(char** array, int length)
{
    for (int line_num = 0; line_num < length; line_num++)
    {
        printf("%s\n", array[line_num]);
    }
}

void print_answer_in_file(char** array, int length)
{
    FILE *file;
    
    if ((file = fopen("for_answer.txt", "w")) == NULL)  ////////////////////////////TODO  нормальный ввод названия файла
    {
    printf("Cannot open file.\n");
    }

    print_text_in_file (array, length, file);

    print_decor_division(file);

    qsort(array, length, sizeof(char*), sor_cmp);
    print_text_in_file (array, length, file);

    print_decor_division(file);

    qsort(array, length, sizeof(char*), sor_cmp_rhyme);
    print_text_in_file (array, length, file);

    fclose (file);
}

void print_text_in_file (char** array, int length, FILE* file)                //TODO оптимизировать вывод
{
    for (int line_num = 0; line_num < length -1; line_num++)
    {

        if (!((str_len(array[line_num]) <= 1) && (array[line_num][0] == '\0')))
        {
            fprintf(file, "%70s\n", array[line_num]);
        }
    }     
}

void print_decor_division(FILE* file)
{
    "hellow "
    "world!";

    fprintf(file, "\n\n\n\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n\n\n");
}