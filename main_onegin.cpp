#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <assert.h> 
#include "work_files.h"
#include "sort_compare.h"


int create_str (FILE* file, char* buffer, size_t num_all_symbol, int* symbol_offset);
int arr_pointers (size_t num_all_symbol, int symbol_offset, int lines, char* buffer, char** arr_pointer, int* num_symbol_line); 


int main() 
{ 
    FILE *file = fopen ("onegin_test.txt", "rb");
    assert (file && "file open err");
    size_t num_all_symbol = count_symbol (file);

    char* buffer = (char*) calloc (num_all_symbol, sizeof(char));
    assert (buffer != NULL);

    int symbol_offset = 0;
    int lines = create_str (file, buffer, num_all_symbol, &symbol_offset);
    
    char** arr_pointer = (char**) calloc (lines + 1, sizeof(char*));

    int num_symbol_line[lines] = {};
    arr_pointers (num_all_symbol, symbol_offset, lines, buffer, arr_pointer, num_symbol_line);         
    
    FILE *sort_file = fopen ("sort_onegin.txt", "wb");

    sort_text (lines, arr_pointer, num_symbol_line, str_compare_start);
    print_sort (arr_pointer, lines, sort_file); 

    sort_text (lines, arr_pointer, num_symbol_line, str_compare_end);
    print_sort (arr_pointer, lines, sort_file);

    print_original (buffer, sort_file, num_all_symbol, symbol_offset);
    fclose (sort_file);
}


int create_str (FILE* file, char* buffer,size_t num_all_symbol, int* symbol_offset)
{
    size_t lines = 0;
    size_t symbol_offsett = 0;

    for (size_t i = 0; i < num_all_symbol; i++){   
        buffer[i - symbol_offsett] = fgetc (file);
        if (buffer[i - symbol_offsett] == '\r'){
            symbol_offsett++;                               
            lines++;
        } else if (buffer[i - symbol_offsett] == '\n'){
            buffer[i - symbol_offsett] = '\0'; 
        }
    }

    *symbol_offset = symbol_offsett;

    return lines;
}

int arr_pointers (size_t num_all_symbol, int symbol_offset, int lines, char* buffer, char** arr_pointer, int* num_symbol_line)
{
    int line = 1;
    arr_pointer[0] = buffer;

    for (size_t i = 0, index = 0, num = 0; i < num_all_symbol - symbol_offset; i++){
        num++;
        if (buffer[i] == '\0'){  
            arr_pointer[line] = buffer + i + 1;
            line++;
            num_symbol_line[index] = num - 1;
            index++;
            num = 0;
        }
    }

    return 0;
}

