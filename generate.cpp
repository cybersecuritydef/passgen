#include "tools.h"
#include "generate.h"



void GenPass::add_password_digit(std::set<std::string> &words){
    char word[MAX_PASS_LEN] = {'\0'};
    char ww[MAX_PASS_LEN] = {'\0'};
    char t[MAX_PASS_LEN] = {'\0'};
    int index = 0;
    int jj = 0;
    Tools tools;
    std::set<std::string> w;
    std::set<std::string>::iterator it = words.begin();
    if(words.size() > 0){
        while(it != words.end()){
                std::string tmp = *it;
            if(tools.is_string(tmp.c_str())){
                /* add digits to right */
                for(jj = 0; jj < 10; jj++){
                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    for(index = jj; index < 10; index++){
                        snprintf(word, MAX_PASS_LEN - 1, "%s%d", word, index);
                        w.insert(word);
                    }
                }

                for(jj = 0; jj < 10; jj++){
                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    snprintf(word, MAX_PASS_LEN - 1, "%s%d%d", word, jj, jj);
                    w.insert(word);

                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    snprintf(word, MAX_PASS_LEN - 1, "%s_%d%d", word, jj, jj);
                    w.insert(word);

                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    snprintf(word, MAX_PASS_LEN - 1, "%s-%d%d", word, jj, jj);
                    w.insert(word);

                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    snprintf(word, MAX_PASS_LEN - 1, "%s%d%d%d", word, jj, jj, jj);
                    w.insert(word);

                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    snprintf(word, MAX_PASS_LEN - 1, "%s_%d%d%d", word, jj, jj, jj);
                    w.insert(word);

                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    snprintf(word, MAX_PASS_LEN - 1, "%s-%d%d%d", word, jj, jj, jj);
                    w.insert(word);

                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    snprintf(word, MAX_PASS_LEN - 1, "%s%d%d%d%d", word, jj, jj, jj, jj);
                    w.insert(word);

                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    snprintf(word, MAX_PASS_LEN - 1, "%s_%d%d%d%d", word, jj, jj, jj, jj);
                    w.insert(word);

                    memset(word, '\0', sizeof(word));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    snprintf(word, MAX_PASS_LEN - 1, "%s-%d%d%d%d", word, jj, jj, jj, jj);
                    w.insert(word);
                }

                /* add digits to left */
                for(jj = 0; jj < 10; jj++){
                    memset(word, '\0', sizeof(word));
                    memset(t, '\0', sizeof(t));
                    memset(ww, '\0', sizeof(w));
                    snprintf(word, MAX_PASS_LEN - 1, "%s", tmp.c_str());
                    for(index = jj; index < 10; index++){
                        snprintf(ww, MAX_PASS_LEN - 1, "%s%d", ww, index);
                        snprintf(t, MAX_PASS_LEN - 1, "%s%s", ww, word);
                        w.insert(t);
                    }
                }
            }
            ++it;
        }
        words.insert(w.begin(), w.end());
    }
}

void GenPass::password_upper(std::set<std::string> &words){
    char word[MAX_PASS_LEN] = {'\0'};
    int index = 0;
    Tools tools;
    std::set<std::string> w;
    std::set<std::string>::iterator it = words.begin();
    if(words.size() > 0){
        while(it != words.end()){
            memset(word, '\0', sizeof(word));
            std::string tmp = *it;
            for(index = 0; index < tmp.size(); index++){
                if(tools.str_upper_chr(tmp.c_str(), index, word) == 0)
                    w.insert(word);
            }
            if(tools.str_upper_title_chr(tmp.c_str(), word) == 0)
                w.insert(word);
            if(tools.str_upper_string(tmp.c_str(), word) == 0)
                w.insert(word);
            ++it;
        }
        words.insert(w.begin(), w.end());
    }
}

void GenPass::password_mutation(std::set<std::string> &words){
    char word[MAX_PASS_LEN] = {'\0'};
    Tools tools;
    std::set<std::string> w;
    std::set<std::string>::iterator it = words.begin();
    if(words.size() > 0){
        while(it != words.end()){
            memset(word, '\0', sizeof(word));
            std::string tmp = *it;
            if(tools.str_count_chr(tmp.c_str(), 'a') > 1){
                tools.str_replace_chr(tmp.c_str(), 'a', '@', word);
                w.insert(word);
                tools.str_replace_chr_end(tmp.c_str(), 'a', '@', word);
                w.insert(word);
                tools.str_replace_chr_all(tmp.c_str(), 'a', '@', word);
                w.insert(word);
            }

            if(tools.str_count_chr(tmp.c_str(), 's') > 1){
                tools.str_replace_chr(tmp.c_str(), 's', '$', word);
                w.insert(word);
                tools.str_replace_chr_end(tmp.c_str(), 's', '$', word);
                w.insert(word);
                tools.str_replace_chr_all(tmp.c_str(), 's', '$', word);
                w.insert(word);
            }

            if(tools.str_count_chr(tmp.c_str(), 's') > 1){
                tools.str_replace_chr(tmp.c_str(), 's', '5', word);
                w.insert(word);
                tools.str_replace_chr_end(tmp.c_str(), 's', '5', word);
                w.insert(word);
                tools.str_replace_chr_all(tmp.c_str(), 's', '5', word);
                w.insert(word);
            }

            if(tools.str_count_chr(tmp.c_str(), 'o') > 1){
                tools.str_replace_chr(tmp.c_str(), 'o', '0', word);
                w.insert(word);
                tools.str_replace_chr_end(tmp.c_str(), 'o', '0', word);
                w.insert(word);
                tools.str_replace_chr_all(tmp.c_str(), 'o', '0', word);
                w.insert(word);
            }

            if(tools.str_count_chr(tmp.c_str(), 'i') > 1){
                tools.str_replace_chr(tmp.c_str(), 'i', '!', word);
                w.insert(word);
                tools.str_replace_chr_end(tmp.c_str(), 'i', '!', word);
                w.insert(word);
                tools.str_replace_chr_all(tmp.c_str(), 'i', '!', word);
                w.insert(word);
            }

            if(tools.str_count_chr(tmp.c_str(), 'z') > 1){
                tools.str_replace_chr(tmp.c_str(), 'z', '2', word);
                w.insert(word);
                tools.str_replace_chr_end(tmp.c_str(), 'z', '2', word);
                w.insert(word);
                tools.str_replace_chr_all(tmp.c_str(), 'z', '2', word);
                w.insert(word);
            }

            if(tools.str_count_chr(tmp.c_str(), 'g') > 1){
                tools.str_replace_chr(tmp.c_str(), 'g', '9', word);
                w.insert(word);
                tools.str_replace_chr_end(tmp.c_str(), 'g', '9', word);
                w.insert(word);
                tools.str_replace_chr_all(tmp.c_str(), 'g', '9', word);
                w.insert(word);
            }
            ++it;
        }
        words.insert(w.begin(), w.end());
    }
}

void GenPass::join_names(std::set<std::string> &words, const char *firstname, const char *lastname){
    char word[MAX_PASS_LEN] = {'\0'};
    if(firstname != nullptr && lastname != nullptr){
        snprintf(word, MAX_NAME_LEN - 1, "%s_%s", firstname, lastname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s-%s", firstname, lastname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s%s", firstname, lastname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s.%s", firstname, lastname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s_%s", lastname, firstname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s-%s", lastname, firstname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s%s", lastname, firstname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s.%s", lastname, firstname);
        words.insert(word);

        snprintf(word, MAX_NAME_LEN - 1, "%s_%c", firstname, lastname[0]);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s-%c", firstname, lastname[0]);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s%c", firstname, lastname[0]);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s.%c", firstname, lastname[0]);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%c_%s", lastname[0], firstname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%c-%s", lastname[0], firstname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%c%s", lastname[0], firstname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%c.%s", lastname[0], firstname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s_%c", lastname, firstname[0]);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s-%c", lastname, firstname[0]);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s%c", lastname, firstname[0]);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%s.%c", lastname, firstname[0]);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%c_%s", firstname[0], lastname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%c-%s", firstname[0], lastname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%c%s", firstname[0], lastname);
        words.insert(word);
        snprintf(word, MAX_NAME_LEN - 1, "%c.%s", firstname[0], lastname);
    }
}

void GenPass::join_birthday(std::set<std::string> &words, const char *birthday){
    char word[MAX_PASS_LEN] = {'\0'};
    int day = 0;
    int mon = 0;
    int year = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    char c[] = {'-', '_'};
    std::set<std::string> w;
    std::set<std::string>::iterator it = words.begin();
    if(birthday != nullptr && words.size() > 0){
        if(sscanf(birthday, "%d.%d.%d", &day, &mon, &year) == 3 || sscanf(birthday, "%d/%d/%d", &day, &mon, &year) == 3 || sscanf(birthday, "%d-%d-%d", &day, &mon, &year) == 3){
            while(it != words.end()){
                std::string names = *it;
                snprintf(word, MAX_NAME_LEN - 1, "%s%02d", names.c_str(), day);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%s%02d", names.c_str(), mon);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%s%d", names.c_str(), year);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%s%d", names.c_str(), year / 100);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%s%d", names.c_str(), year % 100);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%02d%s", day, names.c_str());
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%02d%s", mon, names.c_str());
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%d%s", year, names.c_str());
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%d%s", year / 100, names.c_str());
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%d%s", year % 100, names.c_str());
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%s%02d%02d", names.c_str(), day, mon);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%s%02d%02d", names.c_str(), mon, day);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%s", day, mon, names.c_str());
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%s", mon, day, names.c_str());
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%s%02d%02d%d", names.c_str(), day, mon, year);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%s%02d%02d%d", names.c_str(), day, mon, year / 100);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%s%02d%02d%d", names.c_str(), day, mon, year % 100);
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%d%s", day, mon, year, names.c_str());
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%d%s", day, mon, year / 100, names.c_str());
                w.insert(word);
                snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%d%s", day, mon, year % 100, names.c_str());
                w.insert(word);
                for(i = 0; i < 2; i++){
                    snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d", names.c_str(), c[i], day);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d", names.c_str(),  c[i], mon);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d", names.c_str(),  c[i], year);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%c%d", names.c_str(),  c[i], year / 100);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%c%d", names.c_str(),  c[i], year % 100);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%02d%c%s", day, c[i], names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%02d%c%s", mon, c[i], names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%d%c%s", year, c[i], names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%d%c%s", year / 100, c[i], names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%d%c%s", year % 100, c[i], names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%02d", names.c_str(), c[i], day, mon);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%02d", names.c_str(), c[i], mon, day);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%02d%c%02d", names.c_str(), day, c[i], mon);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%02d%c%02d", names.c_str(), mon, c[i], day);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%c%s", day, mon, c[i], names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%c%s", mon, day, c[i], names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%02d%c%02d%s", day, c[i], mon, names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%02d%c%02d%s", mon, c[i], day, names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%02d%d", names.c_str(), c[i], day, mon, year / 100);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%02d%d", names.c_str(), c[i], day, mon, year % 100);
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%d%c%s", day, mon, year, c[i], names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%d%c%s", day, mon, year / 100, c[i], names.c_str());
                    w.insert(word);
                    snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%d%c%s", day, mon, year % 100, c[i], names.c_str());
                    w.insert(word);
                    for(j = 0; j < 2; j++){
                        snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%c%02d", names.c_str(), c[i], day, c[j], mon);
                        w.insert(word);
                        snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%c%02d", names.c_str(), c[i], mon, c[j], day);
                        w.insert(word);
                        snprintf(word, MAX_NAME_LEN - 1, "%02d%c%02d%c%s", day, c[i], mon, c[j], names.c_str());
                        w.insert(word);
                        snprintf(word, MAX_NAME_LEN - 1, "%02d%c%02d%c%s", mon, c[i], day, c[j], names.c_str());
                        w.insert(word);
                        snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%c%02d%d", names.c_str(), c[i], day, c[j], mon, year / 100);
                        w.insert(word);
                        snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%c%02d%d", names.c_str(), c[i], day, c[j], mon, year % 100);
                        w.insert(word);
                        snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%c%02d%d", names.c_str(), c[i], day, c[j], mon, year);
                        w.insert(word);
                        snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%c%d%c%s", day, mon, c[i], year, c[j], names.c_str());
                        w.insert(word);
                        snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%c%d%c%s", day, mon, c[i], year / 100, c[j], names.c_str());
                        w.insert(word);
                        snprintf(word, MAX_NAME_LEN - 1, "%02d%02d%c%d%c%s", day, mon, c[i], year % 100, c[j], names.c_str());
                        w.insert(word);
                        for(k = 0; k < 2; k++){
                            snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%c%02d%c%d", names.c_str(), c[i], day, c[k], mon, c[j], year / 100);
                            w.insert(word);
                            snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%c%02d%c%d", names.c_str(), c[i], day, c[k], mon, c[j], year % 100);
                            w.insert(word);
                            snprintf(word, MAX_NAME_LEN - 1, "%s%c%02d%c%02d%c%d", names.c_str(), c[i], day, c[k], mon, c[j], year);
                            w.insert(word);
                            snprintf(word, MAX_NAME_LEN - 1, "%02d%c%02d%c%d%c%s", day, c[i], mon, c[i], year, c[j], names.c_str());
                            w.insert(word);
                            snprintf(word, MAX_NAME_LEN - 1, "%02d%c%02d%c%d%c%s", day, c[i], mon, c[k], year / 100, c[j], names.c_str());
                            w.insert(word);
                            snprintf(word, MAX_NAME_LEN - 1, "%02d%c%02d%c%d%c%s", day, c[i], mon, c[k], year % 100, c[j], names.c_str());
                            w.insert(word);
                        }
                    }
                }
                ++it;
            }
            words.insert(w.begin(), w.end());
        }
    }
}

void GenPass::names_join_birthday(std::set<std::string> &words, const char *firstname, const char *lastname, const char *birthday){
    char word[MAX_PASS_LEN] = {'\0'};
    int day = 0;
    int mon = 0;
    int year = 0;
    if(birthday != nullptr && firstname != nullptr && lastname != nullptr){
        if(sscanf(birthday, "%d.%d.%d", &day, &mon, &year) == 3 || sscanf(birthday, "%d/%d/%d", &day, &mon, &year) == 3 || sscanf(birthday, "%d-%d-%d", &day, &mon, &year) == 3){

            snprintf(word, MAX_NAME_LEN - 1, "%s%02d%s", firstname, day, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%02d%s", firstname, mon, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%d%s", firstname, year, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%d%s", firstname, year % 100, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%d%s", firstname, year / 100, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%02d%s", firstname, day, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%02d%s", firstname, mon, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%d%s", firstname, year, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%d%s", firstname, year % 100, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%d%s", firstname, year / 100, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%02d%s", firstname, day, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%02d%s", firstname, mon, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%d%s", firstname, year, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%d%s", firstname, year % 100, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%d%s", firstname, year / 100, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%02d_%s", firstname, day, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%02d_%s", firstname, mon, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%d_%s", firstname, year, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%d_%s", firstname, year % 100, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%d_%s", firstname, year / 100, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%02d-%s", firstname, day, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%02d-%s", firstname, mon, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%d-%s", firstname, year, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%d-%s", firstname, year % 100, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%d-%s", firstname, year / 100, lastname);
            words.insert(word);

            snprintf(word, MAX_NAME_LEN - 1, "%02d%s%s", day, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d%s%s", mon, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d%s%s", year, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d%s%s", year % 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d%s%s", year / 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s%s", day, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s%s", mon, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s%s", year, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s%s", year % 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s%s", year / 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s%s", day, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s%s", mon, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s%s", year, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s%s", year % 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s%s", year / 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s_%s", day, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s_%s", mon, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s_%s", year, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s_%s", year % 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s_%s", year / 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s.%s", day, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d_%s.%s", mon, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s.%s", year, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s.%s", year % 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d_%s.%s", year / 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s-%s", day, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s-%s", mon, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s-%s", year, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s-%s", year % 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s-%s", year / 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s.%s", day, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d-%s.%s", mon, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s.%s", year, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s.%s", year % 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d-%s.%s", year / 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d%s.%s", day, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%02d%s.%s", mon, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d%s.%s", year, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d%s.%s", year % 100, firstname, lastname);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%d%s.%s", year / 100, firstname, lastname);
            words.insert(word);

            snprintf(word, MAX_NAME_LEN - 1, "%s%s%02d", firstname, lastname, day);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s%02d", firstname, lastname, mon);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s%d", firstname, lastname, year);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s%d", firstname, lastname, year % 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s%d", firstname, lastname, year / 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s_%02d", firstname, lastname, day);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s_%02d", firstname, lastname, mon);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s_%d", firstname, lastname, year);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s_%d", firstname, lastname, year % 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s_%d", firstname, lastname, year / 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s-%02d", firstname, lastname, day);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s-%02d", firstname, lastname, mon);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s-%d", firstname, lastname, year);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s-%d", firstname, lastname, year % 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s%s-%d", firstname, lastname, year / 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%02d", firstname, lastname, day);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%02d", firstname, lastname, mon);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%d", firstname, lastname, year);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%d", firstname, lastname, year % 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s_%s_%d", firstname, lastname, year / 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s_%02d", firstname, lastname, day);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s_%02d", firstname, lastname, mon);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s_%d", firstname, lastname, year);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s_%d", firstname, lastname, year % 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s_%d", firstname, lastname, year / 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%02d", firstname, lastname, day);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%02d", firstname, lastname, mon);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%d", firstname, lastname, year);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%d", firstname, lastname, year % 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s-%s-%d", firstname, lastname, year / 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s-%02d", firstname, lastname, day);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s-%02d", firstname, lastname, mon);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s-%d", firstname, lastname, year);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s-%d", firstname, lastname, year % 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s-%d", firstname, lastname, year / 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s%02d", firstname, lastname, day);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s%02d", firstname, lastname, mon);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s%d", firstname, lastname, year);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s%d", firstname, lastname, year % 100);
            words.insert(word);
            snprintf(word, MAX_NAME_LEN - 1, "%s.%s%d", firstname, lastname, year / 100);
            words.insert(word);
        }
    }
}

std::set<std::string> GenPass::generate_passwords(person *p){
    std::set<std::string> words;
    Tools tools;
    std::cout << "[!] Passwords names" << std::endl << std::endl;
    if(p != nullptr){
        if(strlen(p->firstname) > 0){
            tools.str_lower_string(p->firstname, p->firstname);
            words.insert(p->firstname);
        }

        if(strlen(p->lastname) > 0){
            tools.str_lower_string(p->lastname, p->lastname);
            words.insert(p->lastname);
            if(strlen(p->firstname) > 0){
                join_names(words, p->firstname, p->lastname);
                join_names(words, p->lastname, p->firstname);
            }
        }

        if(strlen(p->middlename) > 0){
            tools.str_lower_string(p->middlename, p->middlename);
            words.insert(p->middlename);
            if(strlen(p->firstname) > 0){
                join_names(words, p->firstname, p->middlename);
                join_names(words, p->middlename, p->firstname);
            }
            if(strlen(p->lastname) > 0){
                join_names(words, p->middlename, p->lastname);
                join_names(words, p->lastname, p->middlename);
            }
        }

        if(strlen(p->nickname) > 0){
            tools.str_lower_string(p->nickname, p->nickname);
            words.insert(p->nickname);
            if(strlen(p->firstname) > 0){
                join_names(words, p->firstname, p->nickname);
                join_names(words, p->nickname, p->firstname);
            }
            if(strlen(p->lastname) > 0){
                join_names(words, p->nickname, p->lastname);
                join_names(words, p->lastname, p->nickname);
            }
            if(strlen(p->middlename) > 0){
                join_names(words, p->middlename, p->nickname);
                join_names(words, p->nickname, p->middlename);
            }
        }

        if(strlen(p->pet) > 0){
            tools.str_lower_string(p->pet, p->pet);
            words.insert(p->pet);
            if(strlen(p->firstname) > 0){
                join_names(words, p->firstname, p->pet);
                join_names(words, p->pet, p->firstname);
            }
            if(strlen(p->lastname) > 0){
                join_names(words, p->pet, p->lastname);
                join_names(words, p->lastname, p->pet);
            }
            if(strlen(p->middlename) > 0){
                join_names(words, p->middlename, p->pet);
                join_names(words, p->pet, p->middlename);
            }
            if(strlen(p->nickname) > 0){
                join_names(words, p->pet, p->nickname);
                join_names(words, p->nickname, p->pet);
            }
        }

        if(strlen(p->company) > 0){
            tools.str_lower_string(p->company, p->company);
            words.insert(p->company);
            if(strlen(p->firstname) > 0){
                join_names(words, p->firstname, p->company);
                join_names(words, p->company, p->firstname);
            }
            if(strlen(p->lastname) > 0){
                join_names(words, p->company, p->lastname);
                join_names(words, p->lastname, p->company);
            }
            if(strlen(p->middlename) > 0){
                join_names(words, p->middlename, p->company);
                join_names(words, p->company, p->middlename);
            }
            if(strlen(p->nickname) > 0){
                join_names(words, p->company, p->nickname);
                join_names(words, p->nickname, p->company);
            }
            if(strlen(p->pet) > 0){
                join_names(words, p->pet, p->company);
                join_names(words, p->company, p->pet);
            }
        }
        std::cout << "[!] Passwords upper" << std::endl << std::endl;
        password_upper(words);

        if(strlen(p->birthday) > 0){
            std::cout << "[!] Passwords birthday" << std::endl << std::endl;
            join_birthday(words, p->birthday);
            if(strlen(p->lastname) > 0 && strlen(p->firstname) > 0){
                names_join_birthday(words, p->firstname, p->lastname, p->birthday);
                names_join_birthday(words, p->lastname, p->firstname, p->birthday);
            }

            if(strlen(p->middlename) > 0){
                if(strlen(p->firstname) > 0){
                    names_join_birthday(words, p->firstname, p->middlename, p->birthday);
                    names_join_birthday(words, p->middlename, p->firstname, p->birthday);
                }
                if(strlen(p->lastname) > 0){
                    names_join_birthday(words, p->lastname, p->middlename, p->birthday);
                    names_join_birthday(words, p->middlename, p->lastname, p->birthday);
                }
            }

            if(strlen(p->nickname) > 0){
                if(strlen(p->firstname) > 0){
                    names_join_birthday(words, p->firstname, p->nickname, p->birthday);
                    names_join_birthday(words, p->nickname, p->firstname, p->birthday);
                }
                if(strlen(p->lastname) > 0){
                    names_join_birthday(words, p->lastname, p->nickname, p->birthday);
                    names_join_birthday(words, p->nickname, p->lastname, p->birthday);
                }
                if(strlen(p->middlename) > 0){
                    names_join_birthday(words, p->middlename, p->nickname, p->birthday);
                    names_join_birthday(words, p->nickname, p->middlename, p->birthday);
                }
            }

            if(strlen(p->pet) > 0){
                if(strlen(p->firstname) > 0){
                    names_join_birthday(words, p->firstname, p->pet, p->birthday);
                    names_join_birthday(words, p->pet, p->firstname, p->birthday);
                }
                if(strlen(p->lastname) > 0){
                    names_join_birthday(words, p->lastname, p->pet, p->birthday);
                    names_join_birthday(words, p->pet, p->lastname, p->birthday);
                }
                if(strlen(p->middlename) > 0){
                    names_join_birthday(words, p->middlename, p->pet, p->birthday);
                    names_join_birthday(words, p->pet, p->middlename, p->birthday);
                }
                if(strlen(p->nickname) > 0){
                    names_join_birthday(words, p->nickname, p->pet, p->birthday);
                    names_join_birthday(words, p->pet, p->nickname, p->birthday);
                }
            }

            if(strlen(p->company) > 0){
                if(strlen(p->firstname) > 0){
                    names_join_birthday(words, p->firstname, p->company, p->birthday);
                    names_join_birthday(words, p->company, p->firstname, p->birthday);
                }
                if(strlen(p->lastname) > 0){
                    names_join_birthday(words, p->lastname, p->company, p->birthday);
                    names_join_birthday(words, p->company, p->lastname, p->birthday);
                }
                if(strlen(p->middlename) > 0){
                    names_join_birthday(words, p->middlename, p->company, p->birthday);
                    names_join_birthday(words, p->company, p->middlename, p->birthday);
                }
                if(strlen(p->nickname) > 0){
                    names_join_birthday(words, p->nickname, p->company, p->birthday);
                    names_join_birthday(words, p->company, p->nickname, p->birthday);
                }
                if(strlen(p->pet) > 0){
                    names_join_birthday(words, p->pet, p->company, p->birthday);
                    names_join_birthday(words, p->company, p->pet, p->birthday);
                }
            }
        }

        std::cout << "[!] Add digits passwords" << std::endl << std::endl;
        add_password_digit(words);

        std::cout << "[!] Passwords mutation" << std::endl << std::endl;
        password_mutation(words);
        password_mutation(words);
    }
    return words;
}
