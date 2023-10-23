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
        outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        outputFile.close();
    }
    else
    {
        cout << "Could not create file " + fileName;
    }

    /* READ BINARY FILE */
    Person someoneElse = {};
    ifstream inputFile;
    inputFile.open(fileName, ios::binary);
    if (inputFile.is_open())
    {
        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
        inputFile.close();
    }
    else
    {
        cout << "Coud not read file " + fileName;
    }

    cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.weight << endl;

    return 0;
}