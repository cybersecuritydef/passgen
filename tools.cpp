#include "tools.h"


bool Tools::is_string(const char *str){
    while(*str != '\0'){
        if(isdigit(*str))
            return false;
        *str++;
    }
    return true;
}

int Tools::str_replace_chr(const char *str, int chr, int rep, char *new_str){
    int pos = 0;
    int index = 0;
    bool state = false;
    if(str != nullptr && new_str != nullptr){
        while(str[pos] != '\0'){
            if(str[pos] == chr && !state){
                new_str[index++] = rep;
                pos++;
                state = true;
            }
            else
                new_str[index++] = str[pos++];
        }
        new_str[index] = '\0';
        return 0;
    }
    return EOF;
}

int Tools::str_replace_chr_end(const char *str, int chr, int rep, char *new_str){
    char *tmp = nullptr;
    int index = 0;
    int pos = 0;
    int i = 0;
    bool state = false;
    if((tmp = strrchr(str, chr)) != nullptr){
        index = tmp - str;
        while(str[pos] != '\0'){
            if(pos == index && !state){
                new_str[i++] = rep;
                pos++;
                state = true;
            }
            else
                new_str[i++] = str[pos++];
        }
        new_str[i] = '\0';
        return 0;
    }
    return EOF;
}

int Tools::str_replace_chr_all(const char *str, const int chr, const int rep, char *new_str){
    int pos = 0;
    int index = 0;
    if(str != nullptr && new_str != nullptr){
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

int Tools::str_index_chr(const char *str, const int chr){
    const char *cur = str;
    if(cur != nullptr){
        while(*cur++ && *cur != chr)
            ;
        if((cur - str) <= strlen(str))
            return cur - str;
    }
    return EOF;
}

int Tools::str_upper_title_chr(const char *str, char *new_str){
    int pos = 0;
    int iindex = 0;
    if(str != nullptr && new_str != nullptr){
        while(str[pos] != '\0'){
            if(pos == 0 || pos == strlen(str) - 1)
                new_str[iindex++] = toupper(str[pos++]);
            else
                new_str[iindex++] = str[pos++];
        }
        new_str[iindex] = '\0';
        return 0;
    }
    return EOF;
}

int Tools::str_upper_chr(const char *str, const int index, char *new_str){
    int pos = 0;
    int iindex = 0;
    if(str != nullptr && index >= 0 && new_str != nullptr){
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

int Tools::str_upper_string(const char *str, char *new_str){
    if(str != nullptr && new_str != nullptr){
        while((*new_str++ = toupper(*str++)))
            ;
        *new_str = '\0';
        return 0;
    }
    return EOF;
}

int Tools::str_lower_string(const char *str, char *new_str){
    if(str != nullptr && new_str != nullptr){
        while((*new_str++ = tolower(*str++)))
            ;
        *new_str = '\0';
        return 0;
    }
    return EOF;
}

int Tools::str_reverse_string(const char *str, char *new_str){
    int i, j;
    if(str != nullptr && new_str != nullptr){
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
