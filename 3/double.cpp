#include <iostream>
using namespace std;
/*
	 Author: Wanying Cao
	 ID:10440141
*/

int main() {

    int b = 1, d = 100;
    double u = 1.000000;
    double sum1 = 0.0;
    double sum2 = 0.0;
    double differ;

    while (b <= 100)
    {
        sum1 += u / b;
        b++;
    }

    cout << sum1 << endl;

    while ( d >= 1)
    {
        sum2 += u / d;
        d--;
    }
    cout << sum2 << endl;

    differ = sum1 - sum2 ;

    cout << differ << endl;

    return 0;
}
