#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<string, int> lookup;

    // multimap doesn't have subscript but has to use insert
    lookup.insert(make_pair("Mike", 30));
    lookup.insert(make_pair("Teth", 20));
    lookup.insert(make_pair("Coach", 10));
    lookup.insert(make_pair("Pipe", 30));
    lookup.insert(make_pair("Maddoff", 30));

    for (multimap<string, int>::iterator it = lookup.begin(); it != lookup.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    for (multimap<string, int>::iterator it = lookup.find("Mike"); it != lookup.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}