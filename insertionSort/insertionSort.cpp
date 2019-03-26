#include <iostream>
#include<fstream>
using namespace std;
/*
  Author: Wanying Cao
*/
void insertionSort(int x[],int n) {
    for (int i = 1; i < n; i++) {
        if (x[i - 1] > x[i]) {
            int temp = x[i];
            for (int j = i - 1; j >= 0; j--) {
                if (x[j] > temp)
                {
                    x[j + 1] = x[j];
                }
                else
                {
                    x[j+1] = temp;
                    break;
                }
            }
        }
    }
}

int main() {
    int n;
    ifstream in("hw3.dat");
    if (!in)
    {
        cout << "file open error" << '\n';
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
    insertionSort(array, n);
    cout<< "After insertion sort array: ";
    for (int i = 0; i < n; ++i) {
        cout<< array[i]<<" ";
    }
    cout<< "\n";
    return 0;
}