struct dynamic_int_array{
    int arr_length;
    int* contents;
    int next_available_index;
};

//Creates and returns a dynamic_int_array struct, also initialises values to defaults and allocates memory for the dynamic_int_array.contents array
struct dynamic_int_array init_dynamic_int_arr(int* initial_vals, int arr_length){
    struct dynamic_int_array new_int_arr;
    new_int_arr.next_available_index = 0;
    new_int_arr.arr_length = arr_length;
    new_int_arr.contents = (int*)malloc(arr_length * sizeof(int));

    for (int i = 0; i < arr_length; i++){
        *(new_int_arr.contents + i) = *(initial_vals + i);
        new_int_arr.next_available_index++;
    }

    return new_int_arr;
};

/*Inserts one new integer value into the dynamic_int_array, takes pointer to dynamic_int_array struct and
new integer value to be added as arguments, if there is not enough space for the new integer value in the
dynamic_int_array, more memory is allocated and original values are copied to the new memory location and the new
value is inserted at the very end of the dynamic_int_array*/
void insert_int_to_arr(struct dynamic_int_array* int_arr_ptr, int new_int){
    int mem_increase_val = 1;

    if (int_arr_ptr->next_available_index >= int_arr_ptr->arr_length){
        int* new_int_values_ptr = (int*)malloc((int_arr_ptr->arr_length + mem_increase_val) * sizeof(int));

        for (int i = 0; i < int_arr_ptr->arr_length; i++){
            *(new_int_values_ptr + i) = *(int_arr_ptr->contents + i);
        }

        *(new_int_values_ptr + int_arr_ptr->next_available_index) = new_int;

        free(int_arr_ptr->contents);

        int_arr_ptr->contents = new_int_values_ptr;

        int_arr_ptr->arr_length += mem_increase_val;
        int_arr_ptr->next_available_index ++;
    }
}

//Prints all elements inside of dynamic_int_array.content array
void print_int_arr(struct dynamic_int_array* int_arr_ptr){
    for (int i = 0; i < int_arr_ptr->arr_length; i++){
        printf("\n%d", *(int_arr_ptr->contents + i));
    }
}

//Prints the length of dynamic_int_array (aka the value of dynamic_int_array.arr_length)
void print_int_arr_len(struct dynamic_int_array* int_arr_ptr){
    printf("Array length: %d", int_arr_ptr->arr_length);
}

int sum_of_int_elements(struct dynamic_int_array* int_arr_ptr){
    int result_sum = 0;

    for (int i = 0; i < int_arr_ptr->arr_length; i++){
        result_sum += *(int_arr_ptr->contents + i);
    }

    return result_sum;
}

int int_index(struct dynamic_int_array* int_arr_ptr, int chosen_int){
    for (int i = 0; i < int_arr_ptr->arr_length; i++){
        if (*(int_arr_ptr->contents + i) == chosen_int){
            return i;
        }
    }

    return -1;
}
