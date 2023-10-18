/* TWO THINGS */
/* 1. PARENT CLASS WILL CATCH UNLESS SUBCLASS IS PUT ON THE TOP OF THE PARENT CLASS */
/* 2. NOT EVERY MEMBER OF PARENT CLASS IS A MEMBER OF ITS SUBCLASS, HENCE WILL MISS IF AN ERROR CAUGHT IS AN INSTANCE OF PARENT */

/* RECOMMENDATION: ALWAYS PUT SUBCLASS OF EXCEPTIONS FIRST */

#include <iostream>

void catch_order()
{
    bool error1 = false;
    bool error2 = true;

    if (error1)
    {
        throw(std::bad_alloc());
    }

    if (error2)
    {
        throw(std::exception());
    }
}

int main()
{
    try
    {
        catch_order();
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "catching bad_alloc: " << e.what() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "catching exception: " << e.what() << std::endl;
    }

    return 0;
}