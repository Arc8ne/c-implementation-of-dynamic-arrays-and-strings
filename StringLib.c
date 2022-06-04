struct String{
    char* text;
    int length;
    int length_with_null;
};

void get_str_length(struct String* current_str_ptr){
    current_str_ptr->length = 0;
    int index = 0;

    while (*(current_str_ptr->text + index) != '\0'){
        current_str_ptr->length++;
        index++;
    }

    current_str_ptr->length_with_null = current_str_ptr->length + 1;
}

struct String init_String(char* content){
    struct String new_string;
    new_string.text = content;
    get_str_length(&new_string);

    return new_string;
}
