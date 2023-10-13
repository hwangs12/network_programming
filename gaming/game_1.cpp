/* Write a program that takes a string S and for each character prints the following response:
if the char is a upper case letter then first print out all the uppercase letters before it.

if the character is a lowercase letter then first print out all the lower-case letters before it.

if the character is a digit then first print out all the digits before it, starting from 0 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    cout << "enter a string" << endl;
    string s;
    getline(cin, s);
    string answer = "";
    for (char c : s)
    {
        if (isupper(c))
        {
            for (int i = 65; i <= c; i++)
            {
                answer += i;
            }
        }
        if (islower(c))
        {
            for (int i = 97; i != c; i++)
            {
                answer += i;
            }
        }
        if (isdigit(c))
        {
            for (int i = 48; i != c; i++)
            {
                answer += i;
            }
        }
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << answer << endl;
}