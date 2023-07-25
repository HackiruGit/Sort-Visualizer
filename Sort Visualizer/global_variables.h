#ifndef GLOBAL_VARIABLES
#define GLOBAL_VARIABLES

#include "libraries.h"

inline constexpr std::uint32_t WIDTH{ 740 };
inline constexpr std::uint32_t HEIGHT{ 832 };
inline constexpr std::size_t   MAX_SIZE{ 100 };

inline SDL_Window* window{ SDL_CreateWindow("Sort Visualizer", NULL, NULL, WIDTH, HEIGHT, 0) };
inline SDL_Renderer* render{ SDL_CreateRenderer(window, -1, 0) };

inline unsigned long long swaps{ 0 };
inline unsigned long long array_accesses{ 0 };

#endif
