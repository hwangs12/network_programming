#include <iostream>
#include <string>
#include <map>

class Person
{
private:
    std::string name;
    int age;

public:
    Person() : name(""), age(0) {}

    Person(const Person &other)
    {
        std::cout << "Copy constructor running" << std::endl;
        name = other.name;
        age = other.age;
    }

    Person(std::string name, int age) : name(name), age(age) {}

    void print() const
    {
        std::cout << name << ": " << age << std::flush;
    }

    bool operator<(const Person &other) const
    {
        if (name == other.name)
        {
            return age < other.age;
        }
        else
        {
            return name < other.name;
        }
    }
};

int main()
{
    std::map<Person, int> people;

    people[Person("Mike", 40)] = 40;
    people[Person("Mike", 444)] = 123;
    people[Person("Sue", 30)] = 30;
    people[Person("Raj", 20)] = 20;

    for (std::map<Person, int>::iterator it = people.begin(); it != people.end(); it++)
    {
        std::cout << it->second << ": " << std::flush;
        it->first.print();
        std::cout << std::endl;
    }
}
