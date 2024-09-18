#ifndef WORK_FILE
#define WORK_FILE
#include <stdio.h> 


size_t count_symbol (FILE* file);
int print_sort (char** arr_pointer, size_t lines, FILE *sort_file);
int print_original (char *buffer, FILE *sort_file, size_t num_all_symbol);


#endif