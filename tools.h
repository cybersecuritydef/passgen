#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

class Tools{

public:
    Tools(){}
    ~Tools(){}

    int str_replace_chr_all(const char *str, int chr, int rep, char *new_str);

    int str_replace_chr(const char *str, int chr, int rep, char *new_str);

    int str_replace_chr_end(const char *str, int chr, int rep, char *new_str);

    int str_count_chr(const char *str, const int chr);

    int str_upper_chr(const char *str, int index, char *new_str);

    int str_upper_title_chr(const char *str, char *new_str);

    int str_upper_string(const char *str, char *new_str);

    int str_lower_string(const char *str, char *new_str);

    bool is_string(const char *str);
};



#endif // __TOOLS_H__
