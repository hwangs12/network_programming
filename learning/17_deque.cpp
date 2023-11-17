/* deque is an acronym of double-ended queue. */

/* deques are sequence containers with dynamic sizes that can be expanded or contracted on both ends */

/* Specific libraries may implement deques in different ways, generally as some form of dynamic array. */
#include <iostream>
#include <deque>

using std::cout;
using std::deque;
using std::endl;

int main()
{
    deque<int> mapleSyrup;

    mapleSyrup.push_back(5);
    mapleSyrup.push_front(1);

    for (int i : mapleSyrup)
    {
        cout << i << endl;
    }
}