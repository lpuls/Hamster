#include "Flex.h"
#include "../Tool.h"

#include <iostream>
using namespace std;


char* Hamster::FLEX::remove(char* str, char target)
{
    std::string temp = str;
    int pos = temp.find(target);
    if (pos >= 0 && pos < temp.length())
    {
        temp = temp.erase(pos);
    }
    return MC::toChar(temp.c_str());
}