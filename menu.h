#include "abonent.h"
#include <vector>
#include <iostream>
int menu();
int show_all(std::vector<abonent> &all);
int add_abonent(std::vector<abonent> &all);
int find(std::vector<abonent> &all);
int start_call(std::vector<abonent> &all);
int end_call(std::vector<abonent> &all);
int popolnit_balans(std::vector<abonent> &all);
int sort(std::vector<abonent> &all);
int frost_abonent(std::vector<abonent> &all);
int hot_abonent(std::vector<abonent> &all);
int file_start(const char name[],std::vector<abonent> &all);
int file_end(const char name[],std::vector<abonent> &all);