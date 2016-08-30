#include <functional>
#include <iostream>
#include <string>

std::string printBool(bool b)
{
    return b ? "true" : "false";
}


bool greater(int x, int y)
{
    return x > y;
}

typedef bool(*funPtr)(int, int);
using funPtrCpp11 = bool(*)(int, int);

int main()
{
    funPtr fp = greater;
    std::cout << printBool(fp(10, 20)) << std::endl;

    funPtrCpp11 fpCpp11 = greater;
    std::cout << printBool(fpCpp11(20, 10)) << std::endl;

    std::function<bool(int, int)> funcObj = greater;
    std::cout << printBool(funcObj(10, 20)) << std::endl;

    return 0;
}

//g++ -std=c++14 function_pointer_object.cpp -o function_pointer_object

