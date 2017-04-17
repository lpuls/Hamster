#ifndef __TOOL__
#define __TOOL__

#include <string>
#include <sstream>
#include <iostream>
#include <functional>
using namespace std;

namespace MC
{
#define GET(type, var, fun) public: type get##fun() { return var; }
#define SET(type, var, fun) public: void set##fun(type value) { var = value; }

// 平台
#define WINDOWS

// Debug log 输出等级
#define DEBUG_LEVEL 3
#define NONE_DEBUG 0
#define INFO_LEVEL 1
#define WARNING_LEVEL 2
#define ERROR_LEVEL 3

#if DEBUG_LEVEL >= ERROR_LEVEL
#define LOG_INFO(var) MC::info(var)
#define LOG_WARNING(var) MC::warning(var)
#define LOG_ERROR(var) MC::error(var)
#elif DEBUG_LEVEL >= WARNING_LEVEL
#define LOG_INFO(var) MC::info(var)
#define LOG_WARNING(var) MC::warning(var)
#define LOG_ERROR(var)
#elif DEBUG_LEVEL >= INFO_LEVEL
#define LOG_INFO(var) MC::info(var)
#define LOG_WARNING(var)
#define LOG_ERROR(var)
#elif DEBUG_LEVEL >= NONE_DEBUG
#define LOG_INFO(var)
#define LOG_WARNING(var)
#define LOG_ERROR(var)
#endif

#define DARK_BLUE 1
#define DARK_GREEN 2
#define DARK_RED 4
#define DARK_WHITE 7
#define GARY 8
#define BLUE 9
#define GREEN 10
#define RED 12
#define WHITE 15
#define YELLOW 14

    void log(string log, int color);
	void info(string log);
	void warning(string log);
	void error(string log);
	void command(string log);

	// 时间为毫称
	void sleep(unsigned int time);

    template<class T>
    string toStr(T value)
    {
        ostringstream stream;
        stream << value;  //n为int类型
        return stream.str();
    }

    template<class T>
    string toStr(string str, T value)
    {
        ostringstream stream;
        stream << str;
        stream << value;  //n为int类型
        return stream.str();
    }

	int toInt(string str);

    char* toChar(const char* str);
}

#endif