#include <stdio.h>
#include <stdlib.h>
#include "StringLib.h"
#include "DynamicIntArrayLib.h"

/*
This program allows the user to enter in any amount of numbers and then see the sum of all these numbers as well as get the
index of any one of the numbers that they have entered. It was designed as a test program to ensure that all features from
the StringLib.c and DynamicIntArrayLib.c libraries were working as intended.
*/

typedef enum {false, true} bool;

const int CHAR_SIZE = 1;

int main(){
    struct String text_1 = init_String("Welcome to the program.");

    int num_input = 0;
    int num_list[] = {};
    struct dynamic_int_array numbers_array = init_dynamic_int_arr(num_list, sizeof(num_list)/sizeof(int));

    printf(text_1.text);

    while (num_input != -1){
        printf("\nEnter a new number (Enter -1 to stop): ");
        scanf("%d", &num_input);

        if (num_input != -1){
            insert_int_to_arr(&numbers_array, num_input);
        }
    }

    printf("\nHere are all of the numbers that you have entered: ");
    print_int_arr(&numbers_array);

    printf("\nHere is the sum of all the numbers that you have entered: %d", sum_of_int_elements(&numbers_array));

    printf("\nChoose a number to find which you have just entered: ");
    scanf("%d", &num_input);

    int result_index = int_index(&numbers_array, num_input);

    if (result_index != -1){
        printf("The index of %d is %d.", num_input, result_index);
    }else{
        printf("Error: No such number was entered. Unable to find the index of such a number.");
    }

    return 0;
}
