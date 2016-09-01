#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6};

    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::copy(vec.rbegin(), vec.rend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
