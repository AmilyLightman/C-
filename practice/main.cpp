#include <iostream>
#include <string>
using namespace std;

int main()
{

// print out the string n times  cout << msg will print
void print(string msg, int n)
{
for (int i =0; i < n; i++ )
    cout << msg;
}
// return a string repeating msg n times,example "hello",3 > "hellohellohello"
string repeat(string msg, int n)
{
    string big = msg;
    big += msg;          //msg twice
}
// return a string that is the opposite order, example hello > olleh
string reverse(string msg)
{
return "your answer goes here!";
}
//return the next character in ASCII, for example 'a' + 1 > 'b'
char nextChar(char c)
{

}
int factorial(int n)
    {

    }
int main()
{
    print("hello", 3);
    string big =repeat("yo",9);
    cout << big << '\n';
    cout << nextChar('a') << '\n';
    cout << factorial(5) << '\n'; //5*4*3*2*1=120
    //cout << factorial2(21) << '\n'; //5*4*3*2*1=120
    //cout << factorial2(51) << '\n'; //5*4*3*2*1=120
    //cout << choose(52 ,6) << '\n';  //52!/(6!(52-6)!) 52C0=1 52C1=52
}

    return 0;
}



// inline   not called but compare?   just have to understand

// () call function










/*
 theta = atan2(y,x); ??
read in robotpath.bat
each line contains distance(in meters) and angle (in degrees)
convert angle to radians
 good design



 void f(x, y, r, q)
 double& r,      & reference ????

 theta = atan2(y,x); ??

 */







