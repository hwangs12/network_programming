#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);
    numbers.insert(++numbers.begin(), 100);
    numbers.erase(++numbers.begin());

    for (list<int>::iterator it = numbers.begin(); it != numbers.end();)
    {
        if (*it == 2)
        {
            numbers.insert(it, 1234);
            numbers.insert(it, 2234);
            numbers.erase(it);
            // cout << *it << endl;
        }

        if (*it == 1)
        {
            it = numbers.erase(it);
        }
        else
        {
            it++;
        }
    }

    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}