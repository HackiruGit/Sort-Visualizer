#include "libraries.h"
#include "global_variables.h"
#include "sort_functions.h"
#include "help_functions.h"

int main(int argc, char* args[]) {
	SDL_RenderSetScale(render, 8, 9);
	SDL_SetWindowPosition(window, 60, 32);

	std::vector<int>nums(MAX_SIZE, 0);	
	int cnt;
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
			cnt = 0;
			while (++cnt < 1000)
			{
				SDL_Event event;
				SDL_PollEvent(&event);
				SDL_Delay(1);
			}
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
			cnt = 0;
			while (++cnt < 1000)
			{
				SDL_Event event;
				SDL_PollEvent(&event);
				SDL_Delay(1);
			}
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
			cnt = 0;
			while (++cnt < 1000)
			{
				SDL_Event event;
				SDL_PollEvent(&event);
				SDL_Delay(1);
			}
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
			cnt = 0;
			while (++cnt < 1000)
			{
				SDL_Event event;
				SDL_PollEvent(&event);
				SDL_Delay(1);
			}
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
			cnt = 0;
			while (++cnt < 1000)
			{
				SDL_Event event;
				SDL_PollEvent(&event);
				SDL_Delay(1);
			}
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