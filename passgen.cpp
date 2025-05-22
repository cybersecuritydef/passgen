#include <iostream>
#include <fstream>
#include <set>

#include "generate.h"


bool save_to_file(const char *filename, const std::set<std::string> &words){
    std::ofstream file(filename);
    if(file.is_open()){
        for(auto it = words.begin(); it != words.end(); it++)
            file << *it << std::endl;
        file.close();
        return true;
    }
    return false;
}

char *prompt(const char *msg, char *buf, size_t len){
    std::cout << msg;
    std::cin.getline(buf, len);
    /*if(fgets(buf, len, stdin)){
        buf[strlen(buf) - 1] = '\0';
        return buf;
    }*/
    return NULL;
}


int main(int argc, char **argv){
    person p;
    GenPass genPass;
    std::set<std::string> words;

    memset(&p, '\0', sizeof(p));

    prompt("Input firstname: ", p.firstname, sizeof(p.firstname));

    prompt("Input lastname: ", p.lastname, sizeof(p.lastname));

    prompt("Input middlename: ", p.middlename, sizeof(p.middlename));

    prompt("Input nickname: ", p.nickname, sizeof(p.nickname));

    prompt("Input pet: ", p.pet, sizeof(p.pet));

    prompt("Input compnay: ", p.company, sizeof(p.company));

    prompt("Input birthday (DD.MM.YYY | DD/MM/YYYY | DD-MM-YYYY): ", p.birthday, sizeof(p.birthday));

    prompt("Input filename: ", p.filename, sizeof(p.filename));

    std::cout << "\n[!] Starting generate..." << std::endl << std::endl;
    words =  genPass.generate_passwords(&p);
    if(words.size() > 0){
        std::cout << "[!] Passwords save to file" << std::endl << std::endl;
        if(save_to_file(p.filename, words)){
            std::cout << "[+] Successful!" << std::endl << std::endl;
            std::cout << "Count passwords: " << words.size() << std::endl;
        }
        else
            die("Error save to file!");
    }
    else
        die("Empty password list!");
    return 0;
}
