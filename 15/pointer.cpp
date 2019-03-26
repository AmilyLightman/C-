#include <iostream>
using namespace std;
/*
    @author Wanying Cao (cwid: 10440141)
*/

// fill the array x with zeros (using pointer)
void fill(int x[], int size) {
    int* p = x;
    for(int i=0;i<size;i++)
    {
        *p++ = 0;
    }//x[i] = 0; // NO, use pointer!!! *p++ = 0
}

// add 1 to every element of x
void increment(int x[], int size) {
    int* p = x;
    for(int i=0;i<size;i++,p++)
    {
        *p += 1;
    }
}

// double every element of x
void doubleMe(int x[], int size) {
    int* p = x;
    for(int i=0;i<size;i++,p++)
    {
        *p *= 2;
    }
}

// print out every element of x separated by spaces  then newline
void print(int x[], int size) {
    int* p = x;
    for(int i=0;i<size;i++,p++)
    {
        cout << x[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int x[10] = {1};
    const int size = sizeof(x)/sizeof(int);
    print(x, size);
    fill(x, size);
    print(x, size);
    increment(x, size);
    print(x, size);
    doubleMe(x, size);
    print(x, size);
}

