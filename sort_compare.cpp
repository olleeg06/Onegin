#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>  
#include <assert.h> 
#include "sort_compare.h"


int sort_text (int lines, strocs *keys, size_t num_no_alpha_line,
               int (*compare_function)(char* first, char* second, int num_first, int num_second))
{   
    assert (keys != NULL);
    assert (lines != NULL);
    
    for (size_t i = 0; i < lines - num_no_alpha_line; i++){
        for (int line = 0; line < lines; line++){
            if (compare_function (keys[line].arr_pointer, keys[line + 1].arr_pointer, keys[line].num_symbol_line - 1, keys[line + 1].num_symbol_line - 1) > 0){

                int tmp_int = keys[line].num_symbol_line;
                keys[line].num_symbol_line = keys[line + 1].num_symbol_line;
                keys[line + 1].num_symbol_line = tmp_int;
                
                char* tmp = keys[line].arr_pointer;
                keys[line].arr_pointer = keys[line + 1].arr_pointer;
                keys[line + 1].arr_pointer = tmp;
            }
        }
    }

    return 0;
}

int str_compare_end (char* first, char* second, int num_first, int num_second)
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

int str_compare_start (char* first, char* second, int num_first, int num_second)
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

