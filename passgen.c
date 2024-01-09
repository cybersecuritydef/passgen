#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "generate.h"

bool save_to_file(list_passwords *pwd, const char *filename){
    FILE *file = NULL;
    if((file = fopen(filename, "w")) != NULL){
        while(pwd != NULL){
            fprintf(file, "%s\n", pwd->password);
            pwd = pwd->next;
        }
        return true;
    }
    return false;
}

char *prompt(const char *msg, char *buf, size_t len){
    printf("%s", msg);
    if(fgets(buf, len, stdin)){
        buf[strlen(buf) - 1] = '\0';
        return buf;
    }
    return NULL;
}

void print(list_passwords *pwd){
    while(pwd != NULL){
        DEBUG(pwd->password);
        pwd = pwd->next;
    }
}

int main(int argc, char **argv){
    person p;
    list_passwords *pwd = NULL;
    memset(&p, '\0', sizeof(p));

    prompt("Input firstname: ", p.firstname, sizeof(p.firstname));

    prompt("Input lastname: ", p.lastname, sizeof(p.lastname));

    prompt("Input middlename: ", p.middlename, sizeof(p.middlename));

    prompt("Input nickname: ", p.nickname, sizeof(p.nickname));

    prompt("Input pet: ", p.pet, sizeof(p.pet));

    prompt("Input compnay: ", p.company, sizeof(p.company));

    prompt("Input birthday: ", p.birthday, sizeof(p.birthday));

    prompt("Input path file: ", p.filename, sizeof(p.filename));

    INFORMATION("Starting generate...\n");
    pwd = generate_passwords(&p);

    INFORMATION("Passwords save to file...\n");
    if(save_to_file(pwd, p.filename))
        INFORMATION("Successful!\n");
    else
        die("Error save to file!");

    list_passwords_free(&pwd);
    return 0;
}
