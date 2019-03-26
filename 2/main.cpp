#include <iostream>
/*
	 Author: Wanying Cao
	 ID:10440141
*/

using namespace std;

int main()
{
    int a;
    cout << "number:";
    cin  >> a ;
    while( a != 1 )
    {
        if (a % 2 == 1)
            a = a * 3 + 1;

        else

            a /= 2;

        cout << a <<'\n' ;
    }

    return 0;
}
