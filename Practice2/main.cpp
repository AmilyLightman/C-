/*#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a = "abc";
    cout << a << '\n';
    cout << a[0] << '\n';
    cout << a[a.size()-1] << '\n';

    a += "Sherlock Holmes";
    a += a[3];
    cout << a <<'\n';

    return 0;
}
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//1. LAWAYS USE DOUBLE!!!!! (NEVER FLOAT)
int main()
{
#if 0
    double x = 6.023e+22;
    double y = 1.23456789012345e-300;
    double z =1.23456789012345e+308;
# endif

    double b = 0.000;
    for (int i = 0; i < 100; i++, b += 0.1)
        cout << i * 0.1 << ' ',
        cout << b << ' ' << '\n',
        cout << setprecision(15);

    int a = 5;
    string s = "abc";

    int x[5];//x[0]...x[4]

}
// int i;
// double(i)     make i to double
// 2^16 = 65536 uint16_t > 0 ~ 65535
// int a = round(b*3)


uint8_t a = 0; //0...225
         uint16_t b = 0; // 0...65535
                 uint32_t  c = 1241241;

                 // sizeof()

/*
bool b
if (b)
{
cout << "true";
}
else
{
cout << "false";
}


Class A
private:
int x     > 32
bool y    > 1
int x:1    >bitfields
        inty:2
*/

//  atan2(y,x); robot   angel
        int main()
{
    a &b// both 1 = 1
    a | b  // have 1 = 1
    a^b  //differ = 1
    ~a // opposite , 1 = 0, 0 = 1

    int a = 1 << 5;//0000000001000000 multiply by 2**5 = 32
    // 123 "shift left" in decimal 1230
            int b = 1024 >> 3;//000000100000  1024/ 2**3 = 1024/8 =128
            int c = 55 >> 3; // 55/8 = 0000110001 = 0110 =6

}
using namespace std;
int main()
ifstream f(" ");




#include <iostream>
#include <random>
{
const int SIZE = 10;
int x[SIZE];
fillRandom(x, SIZE); //fill array x with SIZE random number
print(x, SIZE);
cout <<mean(x, SIZE) <<'\n';
}
fillRandom()
{
    for ()
        a[i] =
 x = rand(), y = rand();   // never use it
         default_random_engine gen;
         uniform_int_distribution<int> distribution(1,n);
    for (int i = 0; i < ; ++i) {
        a[i] = distribution(gen);




        default_random_engine gen(0); remove seed once you are done testing...

    }
}
mean()
{
 for auto
}

/*Four :
 class = a specification of an object;
 object = an instance;
 message ;
 method = member functions;
 */
class Fraction //no return type in Fraction
        {
            private:
            int numerator, denminator;
            public:
            Fraction(int i, int j)// constructor
            {
                numerator = i;
                denminator = j;
            }
            void print()
            {
                cout << numerator << '/' << denminator ;
            }

        };

int main()
{
    Fraction f1(1,2);//1/2
    Fraction f2(1,3);//1/3
    Fraction f3 = f1 + f2;//1/2 + 1/3
}





#include <iostream>
#include <random>
using namespace std;
/*
	 Author: Wanying Cao
	 ID:10440141
*/

void fillRandom(int x[], int n);
void mean(int x[],int n);

default_random_engine gen(7); //remove seed once you are done testing...

void fillRandom(int x[], int n)
{
    uniform_int_distribution<int> distribution(1,n);
    for (int i = 0; i < n; i++)
    {
        x[i] = distribution(gen);
        cout << x[i] <<' ';
    }
    cout <<'\n';
}

void mean(int x[], int n)
{
    double sum = 0, mean;
    for (int j = 0; j < n; j++)
    {
        sum += x[j];
    }
    cout << sum <<'\n';
    mean = sum/n;
    cout << mean <<'\n';
}

int main()
{
    const int n = 10;
    int x[n];
    fillRandom(x, n); //fill array x with SIZE random number
    //print(x, SIZE);//print out the array
    mean(x, n);
}











