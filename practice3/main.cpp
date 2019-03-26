#include <iostream>
#include <cmath>
using namespace std;

double hypot(double a, double b)
{
    return sqrt(a*a + b*b); //pow(a,2) >>a*a
}

int main() {
    double c = hypot(0.3, 0.4) ;
          cout << c << endl;
    return 0;
}

//auto c = hypot(3.0, 4.0);

#if 0
int n, x;
double prod = 1
double power(x, n);
{
    while (n > 0)
        if (n % 2 != 0);
    prod *= x;
    x *= x;
    n /= 2;
}
#endif



#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;
void sol(double r,double q,double &x,double &y)
{


}

int main()
{
    double x = 0, y = 0;
    double r, q;
    string c,d;
    ifstream f(" ");
    f >> c >> d;

    while(!f.eof())
    {
        while(f >> r >> q)
        {
            sol(r,q,x,y);
            cout << "" << x << ' ' << " " << y << endl;
        }
    }
return 0;
}

































