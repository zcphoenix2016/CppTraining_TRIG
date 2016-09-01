#include <iostream>

class Foo
{
public:
    void nonConstFunc()
    {
        std::cout << "Non-const member function."  << std::endl;
    }

    void constFunc() const
    {
        std::cout << "Const member function." << std::endl;
    }
};

int main()
{
    Foo f;
    f.nonConstFunc();
    f.constFunc();

    const Foo cf;
    cf.constFunc();
    //cf.nonConstFunc(); //const object could only invoke const member function.

    return 0;
}
