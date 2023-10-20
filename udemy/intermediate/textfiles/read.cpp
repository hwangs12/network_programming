#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/* when is using std:: allowed or when is it not allowed */
int main()
{
    string filename = "sample.txt";
    ifstream inFile;
    inFile.open(filename);

    string line;
    // char a;
    /* while (inFile.get(a))
    {
        cout << a;
    } */
    while (inFile) // !inFile.eof() also works
    {
        getline(inFile, line);
        cout << line << endl;
    }

    return 0;
}