#include <iostream>

using u8 = unsigned char;
using u64 = unsigned long long;

template<u8 f>
class Factorial
{
public:
    static const u64 value = (f * Factorial<f - 1>::value);
};

template<>
class Factorial<0>
{
public:
    static const u64 value = 1;
};

//Similar constexpr function
constexpr u64 factorial(const u8 f)
{
    return (f == 0 ? 1 : f * factorial(f - 1));
}

int main()
{
    std::cout << Factorial<7>::value << std::endl;
    std::cout << factorial(7) << std::endl;
    int arr[factorial(7)];

    return 0;
}
