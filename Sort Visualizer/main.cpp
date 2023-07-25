#include "libraries.h"
#include "global_variables.h"
#include "sort_functions.h"
#include "help_functions.h"

int main(int argc, char* args[]) {
	SDL_RenderSetScale(render, 8, 9);
	SDL_SetWindowPosition(window, 60, 32);

	std::vector<int>nums(MAX_SIZE, 0);	
	fillArray(nums, MAX_SIZE);

	bool running{ true };
	while (running) {
		intro();
		char choice{ makeChoice() };

		switch (choice) {
		case '0':
			running = false;
			break;
		case '1':
			SDL_Delay(2000); /*2 seconds delay*/
			bubbleSort(nums);
			//ensureSort(nums);
			std::cout << "\nArray swaps: " << swaps << ". " <<
				"Array accesses: " << array_accesses << ".\n";
			swaps = 0; array_accesses = 0;
			printSortInfo(choice);
			checkSort(nums);
			fillArray(nums, MAX_SIZE);
			system("cls"); /*clears terminal*/
			break;
		case '2':
			SDL_Delay(2000); /*2 seconds delay*/
			quickSort(nums, 0, MAX_SIZE - 1);
			std::cout << "\nArray swaps: " << swaps << ". " <<
				"Array accesses: " << array_accesses << ".\n";
			swaps = 0; array_accesses = 0;
			printSortInfo(choice);
			checkSort(nums);
			fillArray(nums, MAX_SIZE);
			system("cls"); /*clears terminal*/
			break;
		case '3':
			SDL_Delay(2000); /*2 seconds delay*/
			selectionSort(nums);
			std::cout << "\nArray swaps: " << swaps << ". " <<
				"Array accesses: " << array_accesses << ".\n";
			swaps = 0; array_accesses = 0;
			printSortInfo(choice);
			checkSort(nums);
			fillArray(nums, MAX_SIZE);
			system("cls"); /*clears terminal*/
			break;
		case '4':
			SDL_Delay(2000); /*2 seconds delay*/
			insertionSort(nums);
			std::cout << "\nArray swaps: " << swaps << ". " <<
				"Array accesses: " << array_accesses << ".\n";
			swaps = 0; array_accesses = 0;
			printSortInfo(choice);
			checkSort(nums);
			fillArray(nums, MAX_SIZE);
			system("cls"); /*clears terminal*/
			break;
		case '5':
			SDL_Delay(2000); /*2 seconds delay*/
			mergeSort(nums, 0, nums.size() - 1);
			std::cout << "\nArray swaps: " << swaps << ". " <<
				"Array accesses: " << array_accesses << ".\n";
			swaps = 0; array_accesses = 0;
			printSortInfo(choice);
			checkSort(nums);
			fillArray(nums, MAX_SIZE);
			system("cls"); /*clears terminal*/
			break;
		}
	}
	close();
	return 0;
}