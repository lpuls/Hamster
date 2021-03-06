#include "Tool.h"

#include <string>
#include <sstream>
#include <iostream>
#ifdef WINDOWS
#include "windows.h"
#endif

void MC::info(string log)
{
#ifdef WINDOWS
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << log << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
	std::cout << "\x1b[40;37m" << log << std::endl;
#endif
}

void MC::warning(string log)
{
#ifdef WINDOWS
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	std::cout << log << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
	std::cout << "\x1b[40;33m" << log << std::endl;
#endif
}

void MC::error(string log)
{
#ifdef WINDOWS
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << log << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
	std::cout << "\x1b[40;31m" << log << std::endl;
#endif
}

void MC::command(string log)
{
#ifdef WINDOWS
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << log << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
	std::cout << "\x1b[40;31m" << log << std::endl;
#endif
}

void MC::log(string log, int color)
{
#ifdef WINDOWS
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    std::cout << log << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
#else
    std::cout << "\x1b[40;31m" << log << std::endl;
#endif
}

void MC::sleep(unsigned int time)
{
#ifdef WINDOWS
	Sleep(time);
#else
	Sleep(time / 1000.0);
#endif
}

int MC::toInt(string str)
{
	std::istringstream iss;
	iss.str(str);
	int value;
	iss >> value;
	return value;
}

char * MC::toChar(const char * str)
{
    int size = strlen(str) + 1;
    char *buf = new char[size];
    strcpy_s(buf, size, str);
    return buf;
}
