#include <functional>
#include <iostream>

std::function<int(int)> multiplyBy2Lambda()
{
    return [](int x){return 2 * x;};
}

auto multiplyBy2Lambda_new()
{
    return [](int x){return 2 * x;};
}

int main()
{
    std::function<int(int)> fn = multiplyBy2Lambda();
    std::cout << "fn(5) returns " << fn(5) << std::endl;

    auto fn_new = multiplyBy2Lambda_new();
    std::cout << "fn_new(5) returns " << fn_new(5) << std::endl;

    return 0;
}

//g++ -std=c++14 return_lambda.cpp -o return_lambda
