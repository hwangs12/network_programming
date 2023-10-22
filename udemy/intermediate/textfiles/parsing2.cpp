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
    int intContent;
    while (fileStream)
    {
        // file stream will read through strings up to the first whitespace it finds and exit
        fileStream >> content;
        // file stream will continue to read through the numbers all the way through the first whitespace it finds
        fileStream >> intContent;
        cout << content;
        cout << intContent;
    }
    cout << endl;

    return 0;
}