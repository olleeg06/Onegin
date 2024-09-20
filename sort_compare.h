#ifndef SORT_COMPARE
#define SORT_COMPARE
#include <stdio.h> 


enum sizes {
    DIFFERENCE = 32,
    CAPITAL_1 = 65,
    CAPITAL_2 = 90
};

struct strocs{
    char* arr_pointer;
    int num_symbol_line; //size_line?
    };

int sort_text (int lines, struct strocs *keys, size_t num_no_alpha_line,
               int (*compare_function)(char* first, char* second, int num_first, int num_second));            
int str_compare_start (char* first, char* second, int num_first, int num_second);                 
int str_compare_end (char* first, char* second, int num_first, int num_second);

#endif