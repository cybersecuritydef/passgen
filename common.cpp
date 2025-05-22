#include <iostream>

#include "common.h"

void die(const char *msg){
    std::cerr << "[-] " << msg << std::endl;
    exit(EOF);
}
