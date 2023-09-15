#include <stdio.h>
#include <ctype.h>   
#include <stdlib.h>
#include <math.h>   
#include "sorting.h"

int sor_cmp(const void* str1, const void* str2)
{
    char* str_1 = *(char**) str1;
    char* str_2 = *(char**) str2;

    return str_cmp(str_1, str_2);
}

int sor_cmp_rhyme(const void* str1, const void* str2)
{
    char* str_1 = *(char**) str1;
    char* str_2 = *(char**) str2;

    return str_cmp_rhyme(str_1, str_2);
}

int str_cmp(const char* str1, const char* str2)
{
    int len_str1 = str_len(str1);   //////TODO оптимизировать
    int len_str2 = str_len(str2);
    int len = fmin(len_str1, len_str2);

    int symbol_num_1 = 0;
    int symbol_num_2 = 0;

    while (symbol_num_1 < len && symbol_num_2 < len)      ///TODO почитать про указатели на функции
    {
        if(!isalpha(str1[symbol_num_1]))
        {
            symbol_num_1++;
        }
        else if(!isalpha(str2[symbol_num_2]))
        {
            symbol_num_2++;
        }
        else if(str1[symbol_num_1] != str2[symbol_num_2])
        {
            return (str1[symbol_num_1] - str2[symbol_num_2]);
        }
        else
        {
        symbol_num_1++;
        symbol_num_2++;
        }
    }
    return (len_str1 - len_str2);
}

int str_cmp_rhyme(const char* str1, const char* str2)
{
    int len_str1 = str_len(str1);                     /////TODO лучше вообще записать все длины всех строчек
    int len_str2 = str_len(str2);
    int len = fmin(len_str1, len_str2);

    int symbol_num_1 = len_str1;
    int symbol_num_2 = len_str2;

    while (symbol_num_1 > 0 && symbol_num_2 > 0)
    {
        if(!isalpha(str1[symbol_num_1]))
        {
            symbol_num_1--;
        }
        else if(!isalpha(str2[symbol_num_2]))
        {
            symbol_num_2--;
        }
        else if(str1[symbol_num_1] != str2[symbol_num_2])
        {
            return (str1[symbol_num_1] - str2[symbol_num_2]);
        }
        else
        {
        symbol_num_1--;
        symbol_num_2--;
        }
    }
    return (len_str1 - len_str2);
}

int str_len (const char* string)
{
    if (string == NULL)
    {
        printf ("Alan dolboeb\n");
        // exit (0);
    }

    int symbol_num = 0;
    while (string[symbol_num] != '\0')
    {
        symbol_num++;
    }
    return symbol_num;
}