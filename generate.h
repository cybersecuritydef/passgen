#ifndef __GENERATE_H__
#define __GENERATE_H__

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

typedef struct _list_passwords{
    char password[MAX_PASS_LEN];
    struct _list_passwords *next;
}list_passwords;

int save_to_file(list_passwords *pwd, const char *filename);

list_passwords *generate_passwords(person *p);

void list_passwords_free(list_passwords **pwd);

#endif // __GENERATE_H__
