#include <ctype.h>
#include <string.h>
#include <math.h>
#include <cstdio>
#include <string.h>

enum sizes{
    LINES = 30,
    LENGTH = 70,
    DIFFERENCE = 32,
    CAPITAL_1 = 65,
    CAPITAL_2 = 90
};

void swap_str (char* first, char* second);
void print_text (char text[][LENGTH]);
int str_compare (char* first, char* second);
int reading_file ();
int record_file (char text[][LENGTH]);

char text[LINES][LENGTH] = {};

int main(){

    reading_file();

    for (int i = 0; i < LINES - 1; i++){
        for (int j = 0; j < LINES - 1; j++){
            if (str_compare (text[j], text[j + 1]) == 1){
                swap_str (text[j], text[j + 1]);
            }
        }
    }

    record_file(text);
    return 0;
}

void swap_str (char* first, char* second){
    for (int i = 0; i < LENGTH - 1; i++){
        char temp = first[i];
        first[i] = second[i];
        second[i] = temp;
    }
}


int str_compare(char* first, char* second){
    int first_index = 0;
    int second_index = 0;
    
    for (int i = 0; i < LENGTH; i++){
        char symbol_1 = first[i + first_index];
        char symbol_2 = second[i + second_index];
        
        if (first[i + first_index] >= CAPITAL_1 && first[i + first_index] <= CAPITAL_2){
            symbol_1 = first[i + first_index] + DIFFERENCE;
        }
        if (second[i + second_index] >= CAPITAL_1 && second[i + second_index] <= CAPITAL_2){
            symbol_2 = second[i + second_index] + DIFFERENCE;
        }
        
        if (isalpha(symbol_1) && isalpha(symbol_2) && i + first_index < LENGTH && i + second_index < LENGTH){
            if (symbol_1 > symbol_2)
                return 1;
            else if (symbol_1 < symbol_2)
                return -1;
        } else if (isalpha(symbol_1) == 0 && i + first_index < LENGTH && i + second_index < LENGTH){
            first_index++;
            i--;
        } else if (isalpha(symbol_2) == 0 && i + first_index < LENGTH && i + second_index < LENGTH){
            second_index++;
            i--;
        }
        
    }
    return 0;
}

void print_text (char text[][LENGTH]){
    for (int i = 0; i < LINES; i++){
        printf ("%s", text[i]);
    }
}

int record_file (char text[][LENGTH]){
    FILE *sort_file = fopen("SortOnegin.txt", "w");
    
    for (int i = 0; i < LINES; i++){
        fprintf(sort_file, "%s", text[i]);
    }
    
    fclose(sort_file);
    
    return 0;
}

int reading_file() {
    FILE *file = fopen ("onegin.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file");
    } else {
        for (int i = 0; i < LINES; i++) {
            int j = 0;
           
            while ((text[i][j] = fgetc(file)) != EOF && text[i][j] != '\n') {
                j++;   
            }

            if (text[i][0] == '\n'){
                text[i][j] = '\0';
                i--;
            } else          
                text[i][j + 1] = '\0';
        }
    }
    return 0;
}