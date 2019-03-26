#include <iostream>
#include <fstream>
using namespace std;
/*
	 @Author: Wanying Cao ID:10440141
	 @cite: Google()
*/
void stats(double *array,int n);

int main() {
    int n = 0, i;
    ifstream f("/Users/caowanying/CLionProjects/10/2f.dat");
    double array[256];
    while (!f.eof() )
    {
        while(f >> array[n])
        {
            n++;
        }
        f.close();
    }
    for(i = 0; i < n; i++)
    {
        cout << "array["<< i << "] = " << array[i]<< ' '<<'\n';
    }
    stats(array, n);
    return 0;
}

void stats(double *array,int n) {
    double sum = 0, mean;
    int j;
    for (j = 1; j < n; j++)
    {
        sum += array[j];
    }
    mean = sum / (n-1) ;
    cout << "sum = " << sum <<' '<< "mean = " <<mean <<'\n';
}

