/* WRITING A FILE USING FILE STREAM */
#include <iostream>
#include <fstream>

using std::cerr;
using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;

int main()
{
    std::string filename = "yoyoma.txt";

    ofstream filestream;
    /* 1. open it. fstream::app option allows you to write line without overriding the file */
    filestream.open(filename, fstream::app);
    /* 2. if it's open write on it */
    if (filestream.is_open())
    {
        filestream << "was it written?" << endl;
        filestream << "Yes!" << endl;
    }
    /* 3. if not, notify */
    else
    {
        cerr << "oops the file was not open" << endl;
    }
}

/* CAN I USE SOCKET TO EXCHANGE FILES? */