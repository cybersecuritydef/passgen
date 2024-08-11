#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int str_replace_chr(const char *str, const int chr, const int rep, char *new_str){
    int pos = 0;
    int index = 0;
    if(str != NULL && new_str != NULL){
        while(str[pos] != '\0'){
            if(str[pos] == chr){
                new_str[index++] = rep;
                pos++;
            }
            else
                new_str[index++] = str[pos++];
        }
        new_str[index] = '\0';
        return 0;
    }
    return EOF;
}

int str_index_chr(const char *str, const int chr){
    const char *cur = str;
    if(cur != NULL){
        while(*cur++ && *cur != chr)
            ;
        if((cur - str) <= strlen(str))
            return cur - str;
    }
    return EOF;
}

int str_upper_chr(const char *str, const int index, char *new_str){
    int pos = 0;
    int iindex = 0;
    if(str != NULL && index >= 0 && new_str != NULL){
        while(str[pos] != '\0'){
            if(pos == index){
                if(isalpha(str[pos]))
                    new_str[iindex++] = toupper(str[pos++]);
                else
                    return EOF;
            }
            else
                new_str[iindex++] = str[pos++];
        }
        new_str[iindex] = '\0';
        return 0;
    }
    return EOF;
}

int str_upper_string(const char *str, char *new_str){
    if(str != NULL && new_str != NULL){
        while(*str){
            *new_str++ = toupper(*str++);
        }
        *new_str = '\0';
        return 0;
    }
    return EOF;
}

int str_lower_string(const char *str, char *new_str){
    if(str != NULL && new_str != NULL){
        while(*str != '\0'){
            *new_str++ = tolower(*str++);
        }
        *new_str = '\0';
        return 0;
    }
    return EOF;
}

int str_reverse_string(const char *str, char *new_str){
    int i, j;
    if(str != NULL && new_str != NULL){
        i = strlen(str) - 1;
        j = 0;
        while(i >= 0){
            new_str[j++] = str[i--];
        }
        new_str[j] = '\0';
        return 0;
    }
    return EOF;
}
