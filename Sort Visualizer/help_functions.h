#ifndef HELP_FUNCTIONS
#define HELP_FUNCTIONS

#include "libraries.h"

void intro();
char makeChoice();
void fillArray(std::vector<int>& nums, std::size_t size);
void close();
void show_state(std::vector<int>& nums, std::size_t red, std::size_t blue);
void show_state(std::vector<int>& nums);
void checkSort(std::vector<int>& nums);
void printSortInfo(char choice);

#endif
