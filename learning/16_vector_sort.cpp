#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

class Test
{
private:
    int age;
    string name;

public:
    Test(int age, string name) : age(age), name(name){};
    void print()
    {
        cout << name << ": " << age << endl;
    };
    friend bool comp(const Test &human1, const Test &human2);
};

bool comp(const Test &human1, const Test &human2)
{
    return human1.name < human2.name;
}

int main()
{
    vector<Test> tests;
    tests.push_back(Test(5, "mama"));
    tests.push_back(Test(7, "goma"));
    tests.push_back(Test(5, "tama"));
    tests.push_back(Test(5, "tima"));
    tests.push_back(Test(5, "papa"));

    sort(tests.begin(), tests.begin() + 3, comp);

    for (vector<Test>::iterator it = tests.begin(); it != tests.end(); it++)
    {
        it->print();
    }

    return 0;
}
