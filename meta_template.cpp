#include <iostream>

template<unsigned char f>
class Factorial
{
public:
    static const unsigned long long value = (f * Factorial<f - 1>::value);
};

template<>
class Factorial<0>
{
public:
    static const unsigned long long value = 1;
};

int main()
{
    std::cout << Factorial<7>::value << std::endl;

    return 0;
}
