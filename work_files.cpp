#include <stdio.h> 
#include "work_files.h"

size_t count_symbol (FILE* file) 
{    
    fseek (file, 0, SEEK_END);
    size_t nums = ftell(file);
    fseek (file, 0, SEEK_SET);

    return nums;
}

int print_sort (char ** symbols_in_str, size_t lines, FILE *sort_file)
{    
    for (int i = 0; i < lines; i++){
        fprintf(sort_file, "%s\n", symbols_in_str[i]);
    }
    
    fprintf(sort_file,"\n\n\n");
    
    return 0;
}

int print_original (char *buffer, FILE *sort_file, size_t num_all_symbol)
{
    for (int i = 0; i < num_all_symbol; i++){
        if (buffer[i] == NULL && buffer[i + 1] == NULL){
            buffer[i] = ' ';
            buffer[i + 1] = '\n';
            i++;
        }

        fputc (buffer[i], sort_file);
    }

    return 0;
}