#include <iostream>
using namespace std;

void mightGoWrong()
{
    bool error1 = false;
    bool error2 = true;

    if (error1)
    {
        // throw 8;
        throw "Something went wrong.";
    }
    if (error2)
    {
        throw string("Something else went wrong"); // cpp compiler will instantiate and clean up as well.
    }
}

void useMightGoWrong()
{
    mightGoWrong();
}

int main()
{
    try
    {
        /* code */
        useMightGoWrong(); // nested function will not lose catch capacity
    }
    catch (int e)
    {
        std::cerr << "Error code: " << e << '\n';
    }
    catch (char const *e) // catch char object in throw
    {
        cout << "Error message: " << e << endl;
    }
    catch (string &e)
    {
        cout << "String error message: " << e << endl;
    }

    cout << "Still running" << endl;

    return 0;
}