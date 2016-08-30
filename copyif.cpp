#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> from_vec{10, 20, 30, 105, 209};
    std::copy(from_vec.begin(), from_vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    auto isGreaterThan100 = [](auto i){return i > 100;};

    std::vector<int> to_vec;
    std::copy_if(from_vec.begin(), from_vec.end(), std::back_inserter(to_vec), isGreaterThan100);

    std::copy(to_vec.begin(), to_vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}

//g++ -std=c++14 copyif.cpp -o copyif
