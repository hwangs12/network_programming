/* GAINING SOME INSIGHT INTO FILE STREAM */

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main()
{
    string filename = "population.txt";
    ifstream fileStream;
    fileStream.open(filename);
    if (!fileStream.is_open())
    {
        return 1;
    }
    string content;
    while (fileStream)
    {
        fileStream >> content;
        cout << content;
    }
    cout << endl;

    return 0;
}