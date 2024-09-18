#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>  
#include "sort_compare.h"


int sort_text (int lines, char ** symbols_in_str, int* num_symbol_line,
               int (*compare_function)(const char* first, const char* second, int num_first, int num_second))
{//TODO asserts
    for (size_t i = 0; i < lines - 1; i++){
        for (int line = 0; line < lines - 1; line++){
            if (compare_function (symbols_in_str[line], symbols_in_str[line + 1], num_symbol_line[line] - 1, num_symbol_line[line + 1] - 1) > 0){

                int tmp_int = num_symbol_line[line];
                num_symbol_line[line] = num_symbol_line[line + 1];
                num_symbol_line[line + 1] = tmp_int;
                
                char* tmp = symbols_in_str[line];
                symbols_in_str[line] = symbols_in_str[line + 1];
                symbols_in_str[line + 1] = tmp;
            }
        }
    }

    return 0;
}

int str_compare_end (const char* first, const char* second, int num_first, int num_second)
{
    for (int i = num_first, j = num_second; i >= 0 && j >= 0; i--, j--){
        if (isalpha (first[i]) && isalpha (second[j])){
            if (first[i] > second[j])
                return 1;
            else if (first[i] < second[j])
                return -1;
        } else if (isalpha (first[i]) == 0)
            j++;     
         else if (isalpha (second[j]) == 0)
            i++;
    }

    return 0;
}

int str_compare_start (const char* first,const char* second, int num_first, int num_second)
{
    int first_index = 0;
    int second_index = 0;
    
    for (int i = 0; *first != '\0' && *second != '\0'; i++){
        char symbol_1 = first[i + first_index];
        char symbol_2 = second[i + second_index];
        
        if (first[i + first_index] >= CAPITAL_1 && first[i + first_index] <= CAPITAL_2){
            symbol_1 = first[i + first_index] + DIFFERENCE;
        }
        if (second[i + second_index] >= CAPITAL_1 && second[i + second_index] <= CAPITAL_2){
            symbol_2 = second[i + second_index] + DIFFERENCE;
        }
        
        if (isalpha (symbol_1) && isalpha (symbol_2)){
            if (symbol_1 > symbol_2)
                return 1;
            else if (symbol_1 < symbol_2)
                return -1;
        } else if (isalpha (symbol_1) == 0){
            first_index++;
            i--;
        } else if (isalpha (symbol_2) == 0){
            second_index++;
            i--;
        }
        
    }
    return 0;
}

