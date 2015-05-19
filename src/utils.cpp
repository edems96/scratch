#include "utils.h"

void Utils::Log(const char* str, ...) {
	std::string buffer = "Log: ";
	buffer.append(str);
	buffer.append("\n");
	
	va_list args;
	va_start(args, str);
	vprintf(buffer.c_str(), args);  
	va_end (args);
}

void Utils::Error(const char* str, ...) {
	std::string buffer = "Error: ";
	buffer.append(str);
	buffer.append("\n");
	
	va_list args;
	va_start(args, str);
	vprintf(buffer.c_str(), args);  
	va_end (args);
}

void Utils::SDLError(const char *str, ...) {
	printf("SDL Error(%d): %s\n", SDL_GetError(), str);
}