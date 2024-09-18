#include <stdio.h> 
#include "work_files.h"

int count_symbol (FILE* file)
{    
    fseek (file, 0, SEEK_END);
    size_t nums = ftell(file);
    fseek (file, 0, SEEK_SET);

    return nums;
}

int print_sort (char ** symbols_in_str, size_t lines, FILE *sort_file)
{    
    for (int i = 0; i < lines; i++){
        int j = 0;
        fprintf(sort_file, "%s\n", symbols_in_str[i]);
    }
    
    fprintf(sort_file,"\n\n\n");
    
    return 0;
}

int print_original (char *buffer, FILE *sort_file, size_t num_all_symbol, size_t symbol_offset)
{
    for (int i = 0; i < num_all_symbol - symbol_offset; i++){
        if (buffer[i] == NULL)
            buffer[i] = '\n';
        fprintf(sort_file,"%c", buffer[i]);
    }

    return 0;
}