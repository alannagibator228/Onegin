#include <stdio.h>
#include <ctype.h>   
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "create_array.h"
#include "sorting.h"

// int sor_cmp(const void* str1, const void* str2)
// {
//     char* str_1 = *(char**) str1;
//     char* str_2 = *(char**) str2;

//     return str_cmp(str_1, str_2);
// }

// int sor_cmp_rhyme(const void* str1, const void* str2)
// {
//     char* str_1 = *(char**) str1;
//     char* str_2 = *(char**) str2;

//     return str_cmp_rhyme(str_1, str_2);
// }

int str_cmp(ParsedText* Text, const int num_str1, const int num_str2)
{
    assert(Text != NULL);     //TODO assert
    assert(num_str1 >= 0);
    assert(num_str2 >= 0);

    int len = fmin(Text->len_str[num_str1], Text->len_str[num_str2]);

    int symbol_num_1 = 0;
    int symbol_num_2 = 0;

    while (symbol_num_1 < len && symbol_num_2 < len) 
    {
        if(!isalpha(Text->array_of_pointers[num_str1][symbol_num_1]))
        {
            symbol_num_1++;
        }
        else if(!isalpha(Text->array_of_pointers[num_str2][symbol_num_2]))
        {
            symbol_num_2++;
        }
        else if(Text->array_of_pointers[num_str1][symbol_num_1] != Text->array_of_pointers[num_str2][symbol_num_2])
        {
            return (Text->array_of_pointers[num_str1][symbol_num_1] - Text->array_of_pointers[num_str2][symbol_num_2]);
        }
        else
        {
        symbol_num_1++;
        symbol_num_2++;
        }
    }
    return (Text->len_str[num_str1] - Text->len_str[num_str2]);
}

int str_cmp_rhyme(ParsedText* Text, const int num_str1, const int num_str2)
{
    assert(Text != NULL);     //TODO assert
    assert(num_str1 >= 0);
    assert(num_str2 >= 0);

    int len = fmin(Text->len_str[num_str1], Text->len_str[num_str2]);

    int symbol_num_1 = Text->len_str[num_str1];
    int symbol_num_2 = Text->len_str[num_str2];

    while (symbol_num_1 > 0 && symbol_num_2 > 0)
    {
        if(!isalpha(Text->array_of_pointers[num_str1][symbol_num_1]))
        {
            symbol_num_1--;
        }
        else if(!isalpha(Text->array_of_pointers[num_str2][symbol_num_2]))
        {
            symbol_num_2--;
        }
        else if(Text->array_of_pointers[num_str1][symbol_num_1] != Text->array_of_pointers[num_str2][symbol_num_2])
        {
            return (Text->array_of_pointers[num_str1][symbol_num_1] - Text->array_of_pointers[num_str2][symbol_num_2]);
        }
        else
        {
        symbol_num_1--;
        symbol_num_2--;
        }
    }
    return (Text->len_str[num_str1] - Text->len_str[num_str2]);
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

void swap (ParsedText* Text, int element_1, int element_2)
{
    char* point = Text->array_of_pointers[element_1];
    Text->array_of_pointers[element_1] = Text->array_of_pointers[element_2];
    Text->array_of_pointers[element_2] = point;

    int num = Text->len_str[element_1];
    Text->len_str[element_1] = Text->len_str[element_2];
    Text->len_str[element_2] = num;
}

void selection_sort (ParsedText* Text, int (*comp) (ParsedText* Text, const int num_str1, const int num_str2))
{
    assert(Text != NULL);     //TODO assert
    assert(comp != NULL);

    int index_min;
    for (int index = 0; index < Text->length; index++)
    {
        index_min = index;
        for (int num = index; num < Text->length; num ++)
        {
            if (comp(Text, index_min, num) > 0)
            {
                index_min = num;
            }
        }
        swap(Text, index_min, index);
    }
}