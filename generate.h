#ifndef __GENERATE_H__
#define __GENERATE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>

#include "common.h"

typedef struct _person{
    char firstname[MAX_NAME_LEN];
    char lastname[MAX_NAME_LEN];
    char middlename[MAX_NAME_LEN];
    char nickname[MAX_NAME_LEN];
    char pet[MAX_NAME_LEN];
    char company[MAX_NAME_LEN];
    char birthday[BIRTHDAY_LEN];
    char filename[MAX_NAME_LEN];
}person;

class GenPass{

public:
    GenPass(){}
    ~GenPass(){}
    std::set<std::string> generate_passwords(person *p);

private:
    void names_join_birthday(std::set<std::string> &words, const char *firstname, const char *lastname, const char *birthday);
    void join_birthday(std::set<std::string> &words, const char *birthday);
    void join_names(std::set<std::string> &words, const char *firstname, const char *lastname);
    void password_mutation(std::set<std::string> &words);
    void password_upper(std::set<std::string> &words);
    void add_password_digit(std::set<std::string> &words);
};




#endif // __GENERATE_H__
