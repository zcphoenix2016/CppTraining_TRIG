#include <iostream>

class Base
{
public:
    Base()
    {
        m_pb = new int(10);
	std::cout << "Base constructor" << std::endl;
    }

    virtual ~Base()
    {
        delete m_pb;
	std::cout << "Base desctructor" << std::endl;
    }

    Base(Base&& rhs)
    {
        m_pb = rhs.m_pb;
        rhs.m_pb = nullptr;	
	std::cout << "Base move constructor" << std::endl;
    }

    void isNullPtr()
    {
        if(m_pb)
	{
            std::cout << "m_pb is not null" << std::endl;
	}
	else
	{
            std::cout << "m_pb is null" << std::endl;
	}
    }
private:
    int* m_pb = nullptr;
};

class Derived : public Base
{
public:
    Derived()
    {
        m_pd = new int(20);
	std::cout << "Derived constructor" << std::endl;
    }

    ~Derived()
    {
        delete m_pd;
	std::cout << "Derived desctructor" << std::endl;
    }

    Derived(Derived&& rhs) : Base(dynamic_cast<Base&&>(rhs))
    {
        m_pd = rhs.m_pd;
	rhs.m_pd = nullptr;
	std::cout << "Derived move constructor" << std::endl;
    }

    void isNullPtr()
    {
        Base::isNullPtr();
	if(m_pd)
	{
            std::cout << "m_pd is not null" << std::endl;
	}
	else
	{
            std::cout << "m_pd is null" << std::endl;
	}
    }
private:
    int* m_pd = nullptr;
};

int main()
{
    Base b1;
    Derived d1;

    b1.isNullPtr();
    d1.isNullPtr();

    Base b2(std::move(b1));
    Derived d2(std::move(d1));

    b1.isNullPtr();
    d1.isNullPtr();
    b2.isNullPtr();
    d2.isNullPtr();

    return 0;
}






