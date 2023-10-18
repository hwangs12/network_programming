#include <iostream>

/* YOU CAN DEFINE ERROR OBJECT CATERED TO YOUR NEEDS */

class MyException : public std::exception
{
public:
    virtual const char *what() const throw()
    {
        return "Someting went wrong!";
    }
};

class Test
{
public:
    void GoesWrong()
    {
        throw MyException();
    }
};

int main()
{
    Test test;
    try
    {
        /* code */
        test.GoesWrong();
    }
    catch (MyException &e)
    {
        std::cerr << e.what() << '\n';
    }
}