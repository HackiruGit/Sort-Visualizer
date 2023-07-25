#include "libraries.h"
#include "global_variables.h"

void intro() {
	std::cout << "===========SORTING VISUALIZER===========\n"
		<< "This app was created to represent visualization of\n"
		<< "different sorting algorithms in C++ using SDL2 library.\n"
		<< "Sorting algorithms represented here are Bubble,\n"
		<< "Quick, Selection, Insertion, Merge sorts.\n"
		<< "The storage values are in range [1,99] and their order\n"
		<< "is randomly generated. You have an option to choose\n"
		<< "one of the algorithms by using corresponding\n"
		<< "buttons (1-5).\n"
		<< ".....................................\n"
		<< "LIST OF SORTING ALGORITHMS:\n\n"
		<< "Press '0' to exit the program.\n"
		<< "Press '1' to choose 'Bubble Sort'.\n"
		<< "Press '2' to choose 'Quick Sort'.\n"
		<< "Press '3' to choose 'Selection Sort'.\n"
		<< "Press '4' to choose 'Insertion Sort'.\n"
		<< "Press '5' to choose 'Merge Sort'.\n"
		<< ".....................................\n"
		<< "Your choice: ";
	return;
}

char makeChoice() {
	char choice{};
	std::cin >> choice;

	std::set<char>acceptables{ '0','1','2','3','4','5' };
	if (acceptables.find(choice) == acceptables.end()) {
		choice = '1';
	}
	return choice;
}

void fillArray(std::vector<int>& nums, std::size_t size) {

	/*Marsenne's Twister algorithm for generating random numbers*/
	std::mt19937 random_generator;
	std::uniform_int_distribution random_range(1, 100);

	for (int i = 0; i < size; ++i) {
		nums[i] = random_range(random_generator);
	}
	return;
}

void close() {
	SDL_DestroyRenderer(render);
	render = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();

	return;
}

void show_state(std::vector<int>& nums, std::size_t red, std::size_t blue) {

	/*Choose black as a brush color*/
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);

	/*Clear render with brush color*/
	SDL_RenderClear(render);

	std::size_t index{ 0 };
	for (int i : nums) {
		if (index == red)
			SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		else if (index == blue)
			SDL_SetRenderDrawColor(render, 0, 0, 255, 255);
		else
			SDL_SetRenderDrawColor(render, 255, 255, 255, 255);

		SDL_RenderDrawLine(render, index, 100, index, i);
		++index;
	}
	SDL_RenderPresent(render);

	return;
}

void show_state(std::vector<int>& nums) {
	/*yellow*/
	SDL_SetRenderDrawColor(render, 255, 255, 0, 255);

	std::size_t index{ 0 };
	for (int i : nums) {

		SDL_RenderDrawLine(render, index, 100, index, i);
		SDL_RenderPresent(render);
		SDL_Delay(10);
		++index;
	}
	return;
}

void checkSort(std::vector<int>& nums) {
	bool isSorted{ std::is_sorted(nums.begin(), nums.end()) };
	SDL_SetRenderDrawColor(render, 255, 255, 0, 255);

	std::size_t index{ 0 };
	for (int i : nums) {
		/*i shows which part of the array is currently being sorted*/
		SDL_RenderDrawLine(render, index, 100, index, i);
		SDL_RenderPresent(render);
		SDL_Delay(10);
		++index;
	}
	std::cout << "Array is sorted: " << std::boolalpha << isSorted << '\n';
	system("pause");
	return;
}

void printSortInfo(char choice) {
	switch (choice) {
	//BUBBLE-SORT
	case '1':
		std::cout << "\nTime Complexity: O(n^2) " << "\nAuxiliary Space: O(1)\n\n";
		break;
	//QUICK-SORT
	case '2':
		std::cout << "\nTime Complexity: O(n*log(n)) " << "\nAuxiliary Space: O(log(n))\n\n";
		break;
	//SELECTION-SORT
	case '3':
		std::cout << "\nTime Complexity: O(n^2) " << "\nAuxiliary Space: O(1)\n\n";
		break;
	//INSERION-SORT
	case '4':
		std::cout << "\nTime Complexity: O(n^2) " << "\nAuxiliary Space: O(1)\n\n";
		break;
	//MERGE-SORT
	case '5':
		std::cout << "\nTime Complexity: O(n*log(n)) " << "\nAuxiliary Space: O(n)\n\n";
		break;
	}
}
