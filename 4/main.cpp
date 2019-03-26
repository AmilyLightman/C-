#include <iostream>
#include <cmath>
/*
	 Author: Wanying Cao
	 ID:10440141
	 cite: Kai Zhang, Yan Zhang; (r_n+1 = r_n / sin(( n - 2) * 180/2n )
 */
using namespace std;
int main()
{
int n;
double r = 1.00;
const double P = 3.14159265358;
for( n = 3; n <= 1000000; n++ )
{
    r /= sin((( n - 2) * P)/ (2 * n));

    if ( n == 10)
        cout << "radius" << n << ':' << r <<endl;
    if ( n == 100)
        cout << "radius" << n << ':' << r <<endl;
    if ( n == 1000)
        cout << "radius" << n << ':' << r <<endl;
    if ( n == 10000)
        cout << "radius" << n << ':' << r <<endl;
    if ( n == 100000)
        cout << "radius" << n << ':' << r <<endl;
    if ( n == 1000000)
        cout << "radius" << n << ':' << r <<endl;
};

    return 0;
}

