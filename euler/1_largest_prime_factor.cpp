/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143?
 */

// C++ program to print all prime factors
#include <iostream>
using namespace std;

// A function to print all prime
// factors of a given number n
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n / 2;
        cout << "&&& " << n << " &&&" << endl;
    }
    int chi = 3 <= sqrt(n);
    cout << "??? " << chi << " ???" << endl;

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        cout << sqrt(n) << endl;
        cout << i << endl;
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}

/* Driver code */
int main()
{
    int n = 15;
    primeFactors(n);
    return 0;
}