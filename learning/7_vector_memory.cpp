#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<double> numbers(0);

    int capacity = numbers.capacity();
    cout << "Capacity: " << capacity << endl;

    for (int i = 0; i < 1000; i++)
    {
        cout << numbers.capacity() << " vs " << capacity << endl;
        if (numbers.capacity() != capacity)
        {
            capacity = numbers.capacity();
            cout << "Capacity: " << capacity << endl;
        }

        numbers.push_back(i);
    }

    numbers.reserve(100000);
    // reserve affects capacity
    cout << numbers[2] << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;

    return 0;
}

/* OUTPUT */
/*
Capacity: 0
Capacity: 1
Capacity: 2
Capacity: 4
Capacity: 8
Capacity: 16
Capacity: 32
Capacity: 64
Capacity: 128

It comes down to the question of what does capacity actually measure

educative io says
capacity() function is used to get the memory space that is currently allocated for the vector.

ok confusing.

stack overflow: it is the size of the actual internal allocated size.

ok looks like there's some pattern to allocating the size but why. Maybe it's just the way it is.
 */