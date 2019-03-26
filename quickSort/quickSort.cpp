#include <iostream>
#include<fstream>
#include <random>
using namespace std;
/*
  Author: Wanying Cao
*/

void swap(int& a, int& b){
    a=a+b;
    b=a-b;
    a=a-b;
}
bool test(int x[],int L,int R){
    for (int i = L; i < R; i++) {
        if(x[i]>x[i+1]){
            return true;
        }
    }
    return false;
}
void quickSort(int x[],int L,int R){    // O(n log n)
    long ran=random();
    int pivot = x[ran%(R-L)+L];
    //cout<<pivot;
    int i=L, j=R;
    while(i<j){
        while(x[i]<= pivot && i<R){
            i++;
        }
        //cout<<i;
        while(x[j]> pivot && i<=j){
            j--;
        }
        if(i<j){
            swap(x[i],x[j]);
        }
    }
    if (i - L > 1) {
        if(test(x,L,i))
            quickSort(x, L, i);
    }if (R - j > 1) {
        if(test(x,j,R))
            quickSort(x, j, R);
    }
}

int main() {
    int n;
    ifstream in("/Users/caowanying/CLionProjects/quickSort/hw3.dat");
    //ifstream in("hw3.dat");
    if (!in)
    {
        cout << "file open error" << endl;
        return 1;
    }
    in >> n;
    cout<< "n = " << n<<"\n";
    int array[n];
    cout<< "the original array: ";
    for (int k = 0; k < n; k++) {
        in >> array[k];
        cout<< array[k]<<" ";
    }
    cout<< "\n";
    quickSort(array, 0, n-1);
    cout<< "After QuickSort array: ";
    for (int i = 0; i < n; ++i) {
        cout<< array[i]<<" ";
    }
    return 0;
}