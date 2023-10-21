#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::ws;

int main()
{
    string filename = "population.txt";
    ifstream input;
    input.open(filename);

    if (!input.is_open())
    {
        return 1;
    }

    string line;
    while (input)
    {
        getline(input, line, ':');
        cout << line << endl;
        int population;
        input >> population;

        // input.get();
        input >> ws;

        if (!input)
        {
            break;
        }

        cout << "'" << line << "'"
             << " -- " << population << "'" << endl;
    }

    input.close();

    return 0;
}