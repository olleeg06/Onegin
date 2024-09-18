#ifndef SORT_COMPARE
#define SORT_COMPARE
#include <stdio.h> 


enum sizes {
    DIFFERENCE = 32,
    CAPITAL_1 = 65,
    CAPITAL_2 = 90
};

int sort_text (int lines, char ** symbols_in_str, int* num_symbol_line,
               int (*compare_function)(char* first, char* second, int num_first, int num_second));            
int str_compare_start (char* first, char* second, int num_first, int num_second);                 
int str_compare_end (char* first, char* second, int num_first, int num_second);

#endif