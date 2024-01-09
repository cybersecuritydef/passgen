#ifndef __COMMON_H__
#define __COMMON_H__

#define DEBUG(msg) printf("[!] Debug line [%d]: %s\n", __LINE__, msg)
#define INFORMATION(msg) printf("[+] %s\n", msg)
#define DIE(msg) fprintf(stderr, "[-] %s\n", msg);\
                 exit(EOF);

#define MAX_NAME_LEN 256
#define MAX_PASS_LEN 512
#define BIRTHDAY_LEN 15

#endif // __COMMON_H__
