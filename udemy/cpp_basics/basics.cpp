#include <iostream>
/* below program is not compiled with std version 11 or higher */
extern int x;
int main()
{
    std::cout << "Hello World" << std::endl;

    std::cout << x;

    return 0;
}