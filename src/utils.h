#ifndef UTILS_H
#define UTILS_H

#include <cstdio>
#include <string>

#include <SDL2/SDL.h>

class Utils {
	
	public:
		static void Log(const char* str, ...);
		static void Error(const char* str, ...);
		static void SDLError(const char *str, ...);
};

#endif