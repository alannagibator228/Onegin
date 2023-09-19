#ifndef SORTING
#define SORTING

int str_cmp(ParsedText *Text, const int num_str1, const int num_str2);
int str_cmp_rhyme(ParsedText *Text, const int num_str1, const int num_str2);

int str_len(const char *string);

void swap(ParsedText *Text, int element_1, int element_2);
void selection_sort(ParsedText *Text, int (*cmp)(ParsedText *Text, const int num_str1, const int num_str2));

#endif