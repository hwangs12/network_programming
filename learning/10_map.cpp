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

    ages.insert(pair<string, int>("Peter", 100));

    cout << ages["Rajesh"] << endl;

    /* simply accessing non existent property will add to the map. Check the iteration below */
    cout << ages["Sue"] << endl;

    if (ages.find("tate") != ages.end())
    {
        cout << "Found Vicky" << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        pair<string, int> age = *it;

        cout << age.first << ": " << age.second << endl;
    }

    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}