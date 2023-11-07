#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test
{
private:
    string name;

public:
    Test(string name) : name(name) {}

    ~Test()
    {
        cout << "Test destroyed" << endl;
    }

    void print()
    {
        cout << name << endl;
    }
};

/* STACK IS LIFO QUEUE IS FIFO */

int main()
{
    stack<Test> testStack;

    testStack.push(Test("Mike"));
    testStack.push(Test("Kasey"));
    testStack.push(Test("Turek"));

    cout << endl;

    /*
    This is invalid code. Object is destroyed.

    Test &test1 = testStack.top();
    testStack.pop();
    test1.print(); // Reference refers to destroyed objects
     */

    while (testStack.size() > 0)
    {
        Test &test = testStack.top();
        test.print();
        testStack.pop();
    }
    queue<Test> testQueue;

    testQueue.push(Test("Mike"));
    testQueue.push(Test("Kasey"));
    testQueue.push(Test("Turek"));

    cout << endl;

    /*
    This is invalid code. Object is destroyed.

    Test &test1 = testQueue.top();
    testQueue.pop();
    test1.print(); // Reference refers to destroyed objects
     */

    while (testQueue.size() > 0)
    {
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }

    return 0;
}