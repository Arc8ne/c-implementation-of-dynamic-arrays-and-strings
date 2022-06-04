#ifndef STRINGLIB_H_INCLUDED
#define STRINGLIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct String{
    char* text;
    int length;
    int length_with_null;
};

void get_str_length(struct String*);
struct String init_String(char*);

#endif // STRINGLIB_H_INCLUDED
