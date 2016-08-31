#include <iostream>

class Foo
{
public:
    Foo() = default;

    Foo(int val) : m_val(val)
    {
        std::cout << "Foo constructor." << std::endl;
    }

    ~Foo()
    {
        std::cout << "Foo destructor." << std::endl;
    }

    int getVal()
    {
        return m_val;
    }

private:
    int m_val = 0;
};

int main()
{
    const unsigned int COUNT = 10;
    char* buffer = new char[sizeof(Foo) * COUNT];

    Foo* pf = new (buffer) Foo(100);

    if(pf)
    {
        std::cout << pf->getVal() << std::endl;
    }
    pf->~Foo();

    delete [] buffer;

    return 0;
}

//g++ -std=c++14 placement_new.cpp -o placement_new

