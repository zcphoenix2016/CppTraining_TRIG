#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> vec{10, 20, 30, 105, 209};
    auto ge100 = std::bind(std::greater_equal<int>(), std::placeholders::_1, 100);
    auto it = std::find_if(vec.begin(), vec.end(), ge100);
    std::cout << *it << std::endl;

    auto ge = std::bind(std::greater_equal<int>(), std::placeholders::_1, std::placeholders::_2);
    std::cout << ge(10, 20) << std::endl;

    return 0;
}

//g++ -std=c++14 greater_equal.cpp -o greater_equal
