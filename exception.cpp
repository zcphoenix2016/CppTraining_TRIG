#include <iostream>

class A
{
public:
    virtual std::string what()
    {
        return "A exception";
    }
};

class B : public A
{
public:
    virtual std::string what() override
    {
        return "B exception";
    }
};

void fun(int x)
{
    if(1 == x)
    {
        throw A();
    }
    if(2 == x)
    {
        throw B();
    }
}

int main()
{
    try
    {
        fun(2);
    }
    catch(A& a)
    {
        std::cout << a.what() << std::endl;
    }
    /*
     * dead code -> move upper than base class A
    catch(B& b)
    {
        std::cout << b.what() << std::endl;
    }
    */
    catch(...)
    {
        std::cout << "Exception catched !" << std::endl;
    }

    return 0;
}
