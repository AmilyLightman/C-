#include <iostream>
#include <cmath>
using namespace std;

/*
    @author Wanying Cao (cwid: 10440141)
    @cite Guanchen Jiang: (bool loop)
*/

int range(int x, int y);

bool isPrime(int x)
{
    if (x < 2)
    {
        return false;
    }
    else if(x == 2)
    {
        return true;
    }
    for (int i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b, c, sum;
    cout << "please type the first number:";
    cin >> a;
    cout << '\n';
    cout << "please type the last number:";
    cin >> b;
    cout << '\n';
    if (a > b)
    {
        c = a;
        a = b;
        b = c;
    }
    sum = range(a, b);
    cout << "the number of prime is" << sum << '\n';

    return 0;
}

int range(int x, int y)
{
    int n = 0;
    for (; x <= y; x++)
    {
        n += isPrime(x) ? 1 : 0;
    }
    return n;
}



