#ifndef DYNAMICINTARRAYLIB_H_INCLUDED
#define DYNAMICINTARRAYLIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


struct dynamic_int_array{
    int arr_length;
    int* contents;
    int next_available_index;
};

struct dynamic_int_array init_dynamic_int_arr(int*, int);
void insert_int_to_arr(struct dynamic_int_array*, int);
void print_int_arr(struct dynamic_int_array*);
void print_int_arr_len(struct dynamic_int_array*);
int sum_of_int_elements(struct dynamic_int_array*);
int int_index(struct dynamic_int_array*, int);

#endif // DYNAMICINTARRAYLIB_H_INCLUDED
