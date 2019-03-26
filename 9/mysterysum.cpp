#include <iostream>
#include <cmath>
using namespace std;
/*
	 Author: Wanying Cao
	 ID:10440141
*/

int main() {

    long n = 3000000L, a = 1L, c = n;
    int b = 0, d = 0;
    float i, j;
    float sum1 = 0.0f, sum2 = 0.0f;

    while (a <= n)
    {
        i =  1.0f / (a*a);
        sum1 += i;
        a++;
        if (i >= 0.00001)
        {
            b++;
        }
    }
    //cout << "The sum is " << sum1 << '\n';
    cout << "the number of 1/n^2 >= 0.00001 computed forward is " << b << '\n';


    while (c >= 1)
    {
        j =  1.0f / (c*c);
        sum2 += j;
        c--;
        if (j >= 0.00001)
        {
            d++;
        }
    }
    //cout << "The sum is " << sum2 << '\n';
    cout << "the number of 1/n^2 >= 0.00001 computed backward is " << d << '\n';

    cout << "The sqrt(6 * sum1) is "<< sqrt(6 * sum1) << '\n';
    cout << "The sqrt(6 * sum2) is "<< sqrt(6 * sum2) << '\n';

    if (sqrt(6 * sum1) > sqrt(6 * sum2))
    {
        cout << "The sqrt(6 * sum1) is more accurate" << '\n';
    }
    else
    {
        cout << "The sqrt(6 * sum2) is more accurate" << '\n';
    }

    return 0;
}
