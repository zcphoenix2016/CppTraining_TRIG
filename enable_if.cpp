#include <iostream>
#include <type_traits>
#include <string>

template<typename T, typename Enable = void>
class A
{
public:
    A()
    {
        std::cout << "Primary template class." << std::endl;
    }
};

template<typename T>
class A<T, typename std::enable_if<std::is_integral<T>::value>::type>
{
public:
    A()
    {
        std::cout << "Integral specialization template class." << std::endl;
    }
};

template<typename T>
class A<T, typename std::enable_if<std::is_floating_point<T>::value>::type>
{
public:
    A()
    {
        std::cout << "Floating point specialization template class." << std::endl;
    }
};

template<typename T>
typename std::enable_if<std::is_pointer<T>::value>::type
foo(T t)
{
    std::cout << "Pointer template function overload resolution." << std::endl;
}

template<typename T>
typename std::enable_if<std::is_integral<T>::value>::type
foo(T t)
{
    std::cout << "Integral template function overload resolution." << std::endl;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value>::type
foo(T t)
{
    std::cout << "Floating point template function overload resolution." << std::endl;
}

int main()
{
    A<std::string> a0;
    A<int> a1;
    A<float> a2;
    std::cout << "----------------------------------------------" << std::endl;

    foo<int>(10);
    foo<float>(10.0);
    foo<const char *>("FOO");

    return 0;
}
