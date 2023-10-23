#include <iostream>
#include <fstream>
using namespace std;

// removes padding created in struct so we can write the struct directly to a file
#pragma pack(push, 1)
struct Person
{
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

int main()
{
    Person someone = {"Frodo", 22, 150.68};
    string fileName = "test.bin";
    ofstream outputFile;
    // binary's don't have newline chars and we want to keep binary
    outputFile.open(fileName, ios::binary);

    if (outputFile.is_open())
    {
        outputFile.close();
    }
    else
    {
        cout << "Could not create file " + fileName;
    }

    return 0;
}