#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <assert.h> 
#include "work_files.h"
#include "sort_compare.h"


size_t create_str (FILE* file, char* buffer, size_t num_all_symbol, int* symbol_offset);
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
    
    char** arr_pointer = (char**) calloc (lines, sizeof(char*));

    int num_symbol_line[lines] = {};
    //printf("moew %d, %d", lines, num_all_symbol);
    arr_pointers (num_all_symbol, symbol_offset, lines, buffer, arr_pointer, num_symbol_line);         
 
    FILE *sort_file = fopen ("sort_onegin.txt", "wb");

    sort_text (lines, arr_pointer, num_symbol_line, str_compare_start);
   
    print_sort (arr_pointer, lines, sort_file); 

    sort_text (lines, arr_pointer, num_symbol_line, str_compare_end);
    print_sort (arr_pointer, lines, sort_file);

    print_original (buffer, sort_file, num_all_symbol, symbol_offset);
    fclose (sort_file);
}


size_t create_str (FILE* file, char* buffer, size_t num_all_symbol, int* symbol_offset)
{
    fread(buffer, sizeof(char), num_all_symbol, file);

    size_t lines = 0;
    size_t symbol_offsett = 0;

    for (size_t i = 0; i < num_all_symbol; i++){   

        if (buffer[i - symbol_offsett] == '\r'){
            buffer[i - symbol_offsett] = '\0';                             

        } else if (buffer[i - symbol_offsett] == '\n'){
            buffer[i - symbol_offsett] = '\0'; 
            lines++;
        }
        
    }
  //  fprintf(stderr, "%d\n", lines);
    *symbol_offset = symbol_offsett;

    return lines;
}

int arr_pointers (size_t num_all_symbol, int symbol_offset, int lines, char* buffer, char** arr_pointer, int* num_symbol_line)
{ 
    assert (arr_pointer != NULL);
    int line = 0;
    arr_pointer[0] = buffer;

    for (size_t i = 0, index = 0, num = 0; i < num_all_symbol - symbol_offset; i++){
        num++;

        if (buffer[i] == '\0' && buffer[i + 1] == '\0'){  
            arr_pointer[line + 1] = buffer + i + 2;
            line++;
            num_symbol_line[index] = num - 1;
            index++;
            num = 0;
            i++;
        }
    }

    return 0;
}

