#include <iostream>
#include <fstream>
using namespace std;
/*
    @author Wanying Cao (cwid: 10440141)
*/
//int array(int a) {}

int judge(int a[12][12], int i, int j)
{
    int n=0;
    n= a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];

    if(a[i][j] == 1)
    {
        if(n<2)
        {
            a[i][j] = 0;
        }
        else if(n > 3)
        {
            a[i][j] = 0;
        }
        else
        {
            a[i][j] = 1;
        }
    }
    else
    {
        if(n==3)
        {
            a[i][j] = 1;
        }
    }
    return a[i][j];
}

int main() {
    int a[12][12]={0,1,0,1,0,1,0,1,0,1,0,1,
                   1,0,1,0,1,0,0,1,0,1,0,1,
                   1,0,1,0,1,0,1,0,1,0,1,1,
                   0,1,0,1,0,1,0,0,1,0,1,0,
                   1,0,1,0,1,0,1,0,1,0,1,1,};
    ifstream f("~/hw3b.dat");
    f >> a[12][12];
    int const sum = 100, fra = 10;
    int const t = sum / fra;
    for (int x = 0 ; x <= t; x++)
    {
        for (int y=0 ; y <= fra; y++)
        {
            for (int i = 1; i < 11; i++)
            {
                for (int j = 1; j < 11; j++)
                {
                    judge(a, i, j);
                    {
                        if (y == 0)
                        {
                            if (a[i][j] == 1)
                            {
                                cout << '*';
                            } else {
                                cout << ' ';
                            }
                        }
                    }
                }
                if (y == 0){cout << '\n';}
            }
        }
        cout << '\n';
    }
    return 0;
}