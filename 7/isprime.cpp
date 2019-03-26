#include <iostream>
#include <cmath>
using namespace std;

/*
    @author Wanying Cao (cwid: 10440141)
*/

bool isPrime(unsigned long long p);

int main()
{
    unsigned long long a;
    cout << "Please enter the number:" << endl;
    cin >> a;
    if (isPrime(a))
    {
        cout << "This number is prime." << endl;
    }
    else
    {
        cout << "This number is not prime." << endl;
    }

    return 0;
}

bool isPrime(unsigned long long p)
{
double k = sqrt(p);

    if (p < 2)
    {
        return false;
    }

    for (int i = 2; i < k ; i++)
    {
        if (p % i == 0)
        {
            return false;
        }
    }
    return true;
}