#include <iostream>

/* DESIGN A PROGRAM THAT CREATES MEMORY ALLOCATION ERROR AND CATCH IT */

class CanGoWrong
{
public:
    CanGoWrong()
    {
        char *large = new char[99999];
        delete[] large;
    }
};

int main()
{
    try
    {
        /* code */
        CanGoWrong wrong;
    }
    catch (std::bad_alloc &e)
    {
        std::cerr << "We got error:: " << e.what() << '\n';
    }
}
