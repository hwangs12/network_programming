#include <iostream>

int age{13}; // Global variable

int main()
{
    /* global vars can be dangerous sometimes */
    /* age is local in main function */
    /* local vars gets precedence in the runtime. */
    int age{18};
    std::cout << age << std::endl;
    return 0;
}