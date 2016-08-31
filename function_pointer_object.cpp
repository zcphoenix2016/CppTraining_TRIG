#include <functional>
#include <iostream>

bool greater(int x, int y)
{
    return x > y;
}

typedef bool(*funPtr)(int, int);
using funPtrCpp11 = bool(*)(int, int);

int main()
{
    std::cout << std::boolalpha;

    funPtr fp = greater;
    std::cout << fp(10, 20) << std::endl;

    funPtrCpp11 fpCpp11 = greater;
    std::cout << fpCpp11(20, 10) << std::endl;

    std::function<bool(int, int)> funcObj = greater;
    std::cout << funcObj(10, 20) << std::endl;

    return 0;
}

//g++ -std=c++14 function_pointer_object.cpp -o function_pointer_object

