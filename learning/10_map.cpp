#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> ages;

    ages["Mike"] = 40;
    ages["Rajesh"] = 20;
    ages["Vicky"] = 30;

    /* you can override these values */
    ages["Mike"] = 70;

    cout << ages["Rajesh"] << endl;

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}