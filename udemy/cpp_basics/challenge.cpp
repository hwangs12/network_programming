/* Create a C++ program that asks the user for their favorite number b/w 1 and 100 then read this number from the console. */

/* Suppose the user enters 24. */

/* Then display the following to the console */

/* Amazing!! That's my favorite number too!
No really!!, 24 is my favorite number! */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Enter your favorite number between 1 and 100; ";
    int favoriteNumber;
    cin >> favoriteNumber;

    cout << "Amazing!! That's my favorite number too!\n"
            "No really!!, "
         << favoriteNumber << " is my favorite number!" << endl;

    return 0;
}