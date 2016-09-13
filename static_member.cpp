#include <iostream>

class Foo
{
private:
    static int m_x;

public:
    static int getX()
    {
        return m_x;
    }

    const static int m_y;
    const static int m_z = 30;
};
/*
 * ISO C++ forbids in-class initialization of non-const static member
 * Out-class initialization of const static member is allowed.
 * ‘static’ may not be used when defining (as opposed to declaring) a static data member
 */
int Foo::m_x = 10;
const int Foo::m_y = 20;

int main()
{
    std::cout << Foo::getX() << std::endl;
    std::cout << Foo::m_y << std::endl;
    std::cout << Foo::m_z << std::endl;

    return 0;
}
