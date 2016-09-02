#include <iostream>

class SmartPtr
{
public:
    SmartPtr(int* ptr) : m_ptr(ptr)
    {
        std::cout << "Constructor invoked." << std::endl;
    }

    ~SmartPtr()
    {
        std::cout << "Desctructor invoked." << std::endl;
	delete m_ptr;
    }

private:
    int* m_ptr = nullptr;
};


void funb()
{
    throw 1;
}

void funa()
{
    SmartPtr sp = SmartPtr(new int(10));

    funb();
    
    //Never executed!
    std::cout << __FUNCTION__ << std::endl;
}

int main()
{
    try
    {
        funa();
    }
    catch(...)
    {
        std::cout << __FUNCTION__ << std::endl;
    }

    return 0;
}





