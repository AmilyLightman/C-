#include <iostream>
#include<fstream>
#include <random>
#include <cmath>
using namespace std;
/*
   Author: Wanying Cao
*/
const double PHI = (1+sqrt(5))/2;

void generateQuadratic(int a[], int n) {
    const int c = 100, c2 = 2;
    for (int i = 0, x = -n/2; i < n; i++, x++) {
        a[i] = c - c2*x*x;
    }
}

int goldenMean(const int array[], int n){
    int L=0, R=n-1;
    double S= (R - L) / PHI ;
    int x1 = (int)(R - S), x2 =(int)(L + S);
    while(R-L>1) {
        if (array[x1] > array[x2]) {
            R = x2;
            x2 = x1;
            S = (R - L) / PHI;
            x1 = (int)(R - S);
        }
        else
        {
            L = x1;
            x1 = x2;
            S = (R - L) / PHI;
            x2 =(int)( L + S);
        }
    }
    if(array[L]<array[R])
    {
        return R;
    }
    return L;
}

int main(){
    int n=5;
    cout<< "Please choose the number of array: ";
    cin>> n;
    int array[n];

    generateQuadratic(array,n);

    cout<< "the original array: ";
    for (int k = 0; k < n; k++) {
        cout<< array[k]<<" ";
    }
    cout<< "\n";

    int pos = goldenMean(array, n);
    cout<< "pos = " << pos << "\nthe lagest number is " << array[pos]<< '\n';

/*
    int data[] = {1, 5, 16, 17, 18, 92, 15, 15, 12, 3, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0};
    int pos2 = goldenMean(data,sizeof(data)/ sizeof(int)-1);
    cout<< "pos = " << pos2 << "\nthe lagest number is " << data[pos2]<< '\n';
    */
}