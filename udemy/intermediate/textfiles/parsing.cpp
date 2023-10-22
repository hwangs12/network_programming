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

    while (input)
    {
        string line;
        /* this call will read all the data from the buffer into input  up to and including the first ':' character it encounters. The stream then moves the pointer to the first element in the buffer after that ':'. character. */
        getline(input, line, ':');
        int population;
        input >> population;

        // input.get();
        input >> ws;

        // if (!input)
        // {
        //     break;
        // }

        cout << "'" << line << "'"
             << " -- '" << population << "'" << endl;
    }

    input.close();

    return 0;
}