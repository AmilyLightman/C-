#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
/*
	 @Author: Wanying Cao ID:10440141
	 @cite: Google()
*/
void polar2Rect(double r,double q,double &x,double &y) //& reference

{
    if (r!=-1 && q!=-1)
    {
        const double pi = 3.141592654;
        x = r * sin(q * (pi / 180));
        y = r * cos(q * (pi / 180));
    }
}

int main()
{
    ifstream f("/Users/caowanying/CLionProjects/5/robotpath.dat");
    double r, q, x = 0, y = 0, a=0, b=0;
    string c,d;
    f >> c >> d;
    while (!f.eof())
    {
        //f.seekg(8,ios::cur);
        while (f >> r >> q)
        {
            cout << r << ' ' << q << '\n';
            {
                polar2Rect(r, q, x, y);
                a+=x;
                b+=y;
                cout << "dx = " << a << "  dy = " << b << endl;
            }
        }
        f.close();
    }
    return 0;
}
