#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "tools.h"
#include "generate.h"



static void add_password_list(list_passwords **pwd, const char *value){
    list_passwords *tmp = NULL;
    if(pwd != NULL){
        if((tmp = (list_passwords*)malloc(sizeof(list_passwords))) != NULL){
            snprintf(tmp->password, MAX_PASS_LEN - 1, "%s", value);
            tmp->next = (*pwd);
            (*pwd) = tmp;
        }
        else
            die("Error allocation memory");
    }
}

static void add_password_digit(list_passwords **pwd){
    char word[MAX_PASS_LEN] = {'\0'};
    char w[MAX_PASS_LEN] = {'\0'};
    char t[MAX_PASS_LEN] = {'\0'};
    int index = 0;
    int jj = 0;
    int i = 0;
    list_passwords *new_pwd = NULL;
    list_passwords *cur = NULL;
    if(pwd != NULL && (*pwd) != NULL){
        cur = (*pwd);
        while(cur != NULL){
            /* add digits to right */
            for(jj = 0; jj <= 9; jj++){
                memset(word, '\0', sizeof(word));
                snprintf(word, MAX_PASS_LEN - 1, "%s", cur->password);
                for(index = jj; index <= 9; index++){
                    snprintf(word, MAX_PASS_LEN - 1, "%s%d", word, index);
                    add_password_list(&new_pwd, word);
                }
            }

            for(i = 9; i >= 2; i--){
                for(jj = 0; jj <= 9; jj++){
                    memset(w, '\0', sizeof(w));
                    memset(word, '\0', sizeof(word));
                    for(index = 0; index < i; index++)
                        snprintf(w, MAX_PASS_LEN - 1, "%s%d", w, jj);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%s", cur->password, w);
                    add_password_list(&new_pwd, word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s_%s", cur->password, w);
                    add_password_list(&new_pwd, word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s-%s", cur->password, w);
                    add_password_list(&new_pwd, word);
                }
            }

            /* add digits to left */
            for(jj = 0; jj <= 9; jj++){
                memset(word, '\0', sizeof(word));
                memset(t, '\0', sizeof(t));
                memset(w, '\0', sizeof(w));
                snprintf(word, MAX_PASS_LEN - 1, "%s", cur->password);
                for(index = jj; index <= 9; index++){
                    snprintf(w, MAX_PASS_LEN - 1, "%s%d", w, index);
                    snprintf(t, MAX_PASS_LEN - 1, "%s%s", w, word);
                    add_password_list(&new_pwd, t);
                }
            }

            for(i = 9; i >= 2; i--){
                for(jj = 0; jj <= 9; jj++){
                    memset(w, '\0', sizeof(w));
                    memset(word, '\0', sizeof(word));
                    for(index = 0; index < i; index++)
                        snprintf(w, MAX_PASS_LEN - 1, "%s%d", w, jj);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%s", w, cur->password);
                    add_password_list(&new_pwd, word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s_%s", w, cur->password);
                    add_password_list(&new_pwd, word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s-%s", w, cur->password);
                    add_password_list(&new_pwd, word);
                }
            }

            add_password_list(&new_pwd, cur->password);
            cur = cur->next;
        }
        (*pwd) = new_pwd;
    }
}

static void password_upper(list_passwords **pwd){
    char word[MAX_PASS_LEN] = {'\0'};
    int index = 0;
    list_passwords *new_pwd = NULL;
    list_passwords *cur = NULL;
    if(pwd != NULL && (*pwd) != NULL){
        cur = (*pwd);
        while(cur != NULL){
            memset(word, '\0', sizeof(word));
            for(index = 0; cur->password[index] != '\0'; index++){
                if(str_upper_chr(cur->password, index, word) == 0)
                    add_password_list(&new_pwd, word);
            }
            if(str_upper_string(cur->password, word) == 0)
                add_password_list(&new_pwd, word);
            add_password_list(&new_pwd, cur->password);
            cur = cur->next;
        }
        (*pwd) = new_pwd;
    }
}

static void password_mutation(list_passwords **pwd){
    char word[MAX_PASS_LEN] = {'\0'};
    list_passwords *new_pwd = NULL;
    list_passwords *cur = NULL;
    if(pwd != NULL && (*pwd) != NULL){
        cur = (*pwd);
        while(cur != NULL){
            memset(word, '\0', sizeof(word));
            if(str_index_chr(cur->password, 'a') != EOF){
                str_replace_chr(cur->password, 'a', '@', word);
                add_password_list(&new_pwd, word);
            }

            if(str_index_chr(cur->password, 's') != EOF){
                str_replace_chr(cur->password, 's', '$', word);
                add_password_list(&new_pwd, word);
            }

            if(str_index_chr(cur->password, 's') != EOF){
                str_replace_chr(cur->password, 's', '5', word);
                add_password_list(&new_pwd, word);
            }

            if(str_index_chr(cur->password, '5') != EOF){
                str_replace_chr(cur->password, '5', '$', word);
                add_password_list(&new_pwd, word);
            }

            if(str_index_chr(cur->password, 'o') != EOF){
                str_replace_chr(cur->password, 'o', '0', word);
                add_password_list(&new_pwd, word);
            }

            if(str_index_chr(cur->password, '0') != EOF){
                str_replace_chr(cur->password, '0', 'o', word);
                add_password_list(&new_pwd, word);
            }

            if(str_index_chr(cur->password, 'i') != EOF){
                str_replace_chr(cur->password, 'i', '!', word);
                add_password_list(&new_pwd, word);
            }

            if(str_index_chr(cur->password, '1') != EOF){
                str_replace_chr(cur->password, '1', '!', word);
                add_password_list(&new_pwd, word);
            }
            add_password_list(&new_pwd, cur->password);
            cur = cur->next;
        }
        (*pwd) = new_pwd;
    }
}

static void join_names(list_passwords **pwd, const char *firstname, const char *lastname){
    char word[MAX_PASS_LEN] = {'\0'};
    if(pwd != NULL && (*pwd) != NULL && firstname != NULL && lastname != NULL){

        snprintf(word, MAX_NAME_LEN - 1, "%s_%s", firstname, lastname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s-%s", firstname, lastname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s%s", firstname, lastname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s_%s", lastname, firstname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s-%s", lastname, firstname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s%s", lastname, firstname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s%s%s", lastname, firstname, lastname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s%s%s", firstname, lastname, firstname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%s", lastname, firstname, lastname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%s", firstname, lastname, firstname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%s", lastname, firstname, lastname);
        add_password_list(pwd, word);

        snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%s", firstname, lastname, firstname);
        add_password_list(pwd, word);
    }
}

static void join_birthday(list_passwords **pwd, const char *names, const char *birthday){
    char word[MAX_PASS_LEN] = {'\0'};
    int day = 0;
    int mon = 0;
    int year = 0;
    if(pwd != NULL && (*pwd) != NULL && birthday != NULL){
        if(sscanf(birthday, "%d.%d.%d", &day, &mon, &year) == 3 || sscanf(birthday, "%d/%d/%d", &day, &mon, &year) == 3 || sscanf(birthday, "%d-%d-%d", &day, &mon, &year) == 3){
            snprintf(word, MAX_NAME_LEN - 1, "%s%02d", names, day);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d%s", day, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%02d", names, mon);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d%s", mon, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%d", names, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%d%s", year, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%d%s", day, mon, year, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%d_%s", day, mon, year, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%d-%s", day, mon, year, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d.%02d.%d%s", day, mon, year, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d-%02d-%d%s", day, mon, year, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d_%02d_%d%s", day, mon, year, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d\\%02d\\%d%s", day, mon, year, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d/%02d/%d%s", day, mon, year, names);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%02d%02d%d", names, day, mon, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s_%02d%02d%d", names, day, mon, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s-%02d%02d%d", names, day, mon, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%02d.%02d.%d", names, day, mon, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%02d-%02d-%d", names, day, mon, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%02d_%02d_%d", names, day, mon, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%02d\\%02d\\%d", names, day, mon, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%02d/%02d/%d", names, day, mon, year);
            add_password_list(pwd, word);
        }
    }
}

static void names_join_birthday(list_passwords **pwd, const char *firstname, const char *lastname, const char *birthday){
    char word[MAX_PASS_LEN] = {'\0'};
    int day = 0;
    int mon = 0;
    int year = 0;
    if(pwd != NULL && (*pwd) != NULL && birthday != NULL && firstname != NULL && lastname != NULL){
        if(sscanf(birthday, "%d.%d.%d", &day, &mon, &year) == 3 || sscanf(birthday, "%d/%d/%d", &day, &mon, &year) == 3 || sscanf(birthday, "%d-%d-%d", &day, &mon, &year) == 3){

            snprintf(word, MAX_NAME_LEN - 1, "%s%02d%s", firstname, day, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%02d%s", firstname, mon, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%d%s", firstname, year, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s_%02d%s", firstname, day, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%02d%s", firstname, mon, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%d%s", firstname, year, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s-%02d%s", firstname, day, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%02d%s", firstname, mon, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%d%s", firstname, year, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s_%02d_%s", firstname, day, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%02d_%s", firstname, mon, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%d_%s", firstname, year, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s-%02d-%s", firstname, day, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%02d-%s", firstname, mon, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%d-%s", firstname, year, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d%s%s", day, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d%s%s", mon, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%d%s%s", year, firstname, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s%s", day, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s%s", mon, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s%s", year, firstname, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s%s", day, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s%s", mon, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s%s", year, firstname, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s_%s", day, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s_%s", mon, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s_%s", year, firstname, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s-%s", day, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s-%s", mon, firstname, lastname);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s-%s", year, firstname, lastname);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%s%02d", firstname, lastname, day);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s%02d", firstname, lastname, mon);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s%d", firstname, lastname, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%s_%02d", firstname, lastname, day);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s_%02d", firstname, lastname, mon);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s_%d", firstname, lastname, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%s-%02d", firstname, lastname, day);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s-%02d", firstname, lastname, mon);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s-%d", firstname, lastname, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%02d", firstname, lastname, day);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%02d", firstname, lastname, mon);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%d", firstname, lastname, year);
            add_password_list(pwd, word);

            snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%02d", firstname, lastname, day);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%02d", firstname, lastname, mon);
            add_password_list(pwd, word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%d", firstname, lastname, year);
            add_password_list(pwd, word);
        }
    }
}

static void password_reverse(list_passwords **pwd){
    char word[MAX_PASS_LEN] = {'\0'};
    list_passwords *new_pwd = NULL;
    list_passwords *cur = NULL;
    if(pwd != NULL && (*pwd) != NULL){
        cur = (*pwd);
        while(cur != NULL){
            memset(word, '\0', sizeof(word));
            if(str_reverse_string(cur->password, word) == 0)
                add_password_list(&new_pwd, word);
            add_password_list(&new_pwd, cur->password);
            cur = cur->next;
        }
        (*pwd) = new_pwd;
    }
}

static void remove_duplicate(list_passwords **pwd){
    list_passwords *p = NULL;
    list_passwords *q = NULL;
    list_passwords *dup = NULL;
    if(pwd != NULL && (*pwd) != NULL){
        p = (*pwd);
        while(p != NULL){
            q = p;
            while(q->next != NULL){
                if(strcmp(p->password, q->next->password) == 0){
                    dup = q->next;
                    q->next = dup->next;
                    free(dup);
                    dup = NULL;
                }
                else
                    q = q->next;
            }
            p = p->next;
        }   
    }    
}

list_passwords *generate_passwords(person *p){
    list_passwords *pwd = NULL;

    if(p != NULL){
        if(strlen(p->firstname) > 0){
            str_lower_string(p->firstname, p->firstname);
            add_password_list(&pwd, p->firstname);
            if(strlen(p->birthday) > 0)
                join_birthday(&pwd, p->firstname, p->birthday);
        }

        if(strlen(p->lastname) > 0){
            str_lower_string(p->lastname, p->lastname);
            add_password_list(&pwd, p->lastname);
            if(strlen(p->birthday) > 0)
                join_birthday(&pwd, p->lastname, p->birthday);
        }

        if(strlen(p->middlename) > 0){
            str_lower_string(p->middlename, p->middlename);
            add_password_list(&pwd, p->middlename);
            if(strlen(p->birthday) > 0)
                join_birthday(&pwd, p->middlename, p->birthday);
        }

        if(strlen(p->nickname) > 0){
            str_lower_string(p->nickname, p->nickname);
            add_password_list(&pwd, p->nickname);
            if(strlen(p->birthday) > 0)
                join_birthday(&pwd, p->nickname, p->birthday);
        }

        if(strlen(p->pet) > 0){
            str_lower_string(p->pet, p->pet);
            add_password_list(&pwd, p->pet);
            if(strlen(p->birthday) > 0)
                join_birthday(&pwd, p->pet, p->birthday);
        }

        if(strlen(p->company) > 0){
            str_lower_string(p->company, p->company);
            add_password_list(&pwd, p->company);
            if(strlen(p->birthday) > 0)
                join_birthday(&pwd, p->company, p->birthday);
        }

        if(strlen(p->firstname) > 0 && strlen(p->lastname) > 0){
            INFORMATION("Passwords join firstname lastname...\n");
            join_names(&pwd, p->firstname, p->lastname);
            if(strlen(p->birthday) > 0){
                names_join_birthday(&pwd, p->firstname, p->lastname, p->birthday);
                names_join_birthday(&pwd, p->lastname, p->firstname, p->birthday);
            }
        }

        INFORMATION("Add digits in passwords...\n");
        add_password_digit(&pwd);

        INFORMATION("Passwords mutation...\n");
        password_mutation(&pwd);

        INFORMATION("Passwords reverse...\n");
        password_reverse(&pwd);

        INFORMATION("Passwords upper...\n");
        password_upper(&pwd);

        remove_duplicate(&pwd);
        
        return pwd;
    }
    return NULL;
}


void list_passwords_free(list_passwords **pwd){
    list_passwords *tmp = NULL;
    if(pwd != NULL && (*pwd) != NULL){
        while((*pwd)->next != NULL){
            tmp = (*pwd);
            (*pwd) = (*pwd)->next;
            free(tmp);
            tmp = NULL;
        }
        free((*pwd));
        (*pwd) = NULL;
    }
}
