#include <iostream>
using namespace std;
/*
	 Author: Wanying Cao
	 ID:10440141
*/
int main() {

    int a, b, c;
    cout << "first number:";
    cin  >> a ;
    cout << '\n';
    cout << "last number:";
    cin  >> b ;
    cout << '\n';

    int n = 1, sum1 = 0 , sum2 = 0;
    int differ;

    if (a > b)
    c=a,a=b,b=c;
    int x = a, y = b;

    while (b > a)
        {
            n++, a++;
        }

    sum1=(x+y)*n/2;

    cout << "sum1: " << sum1 << endl;



    while (y >= x)
        {
            sum2 += x, x++;
        }

    cout << "sum2: " << sum2 << endl;


    differ = sum1 - sum2 ;

    cout << "differ: " << differ << endl;

    return 0;

}