#include <iostream>
#include <cmath>
using namespace std;
/*
    * @author Wanying Cao (Id: 10440141)
*/

double windchill(double t, double v);

int main()

{
    double i, j;
    cout << "Calm" << '\t';
    for (i = 40; i >= -45; i-= 5)
    {
        cout << i <<'\t';
    }
    cout << '\n';

    for (j = 5; j <= 60; j+= 5)
    {
        cout << j << '\t';
        for (i = 40; i >= -45; i-= 5)
        {
            double windchill(double i, double j);
            cout << windchill(i,j) << '\t';
        }
        cout << '\n';
    }

    return 0;
}

double windchill(double t, double v)
{
    int f;
    f = 35.74 + 0.6215*t -35.75* pow(v, 0.16) + 0.4275 * t * pow(v, 0.16);
    return f;
}