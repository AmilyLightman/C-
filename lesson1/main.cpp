#include <iostream>
#include <cmath>
using namespace std;
#include <iostream>
#include <iomanip>
using namespace std;
void noMemo(int n, int r){
    double num=1.0,den=1.0;
    double choose;
    for (int i = r; i >=1 ; i--) {
        den*=i;
    }
    for (int j = n; j >= (n-r+1); j--) {
        num*=j;
    }
    choose=num/den;
    cout << "without memoization, choose(n,r) = "<< choose;
}
/*
	 Make sure your choose function works for test data
                  1
                1   1
              1   2   1
            1   3   3   1
          1   4   6   4   1
        1   5   10  10  5   1
      1   6   15  20  15  6   1
 */

double choose(int n, int r){
    static int memo[n][r]={1};
    if(r==0||n==r){
        memo[n][r]=1;
    }
    //memo[n][r]=memo[n][n-r];
    if (memo[n][r]!=0)
    {
        return memo[n][r];
    }
    return choose(n-1,r-1)+choose(n-1,r);
}

int main() {
    int testCases[][3] = {
            {0, 0, 1},

            {1, 0, 1},
            {1, 1, 1},

            {2, 0, 1},
            {2, 1, 2},
            {2, 2, 1},

            {5, 0, 1},
            {5, 1, 5},
            {5, 2, 10},

            {6, 3, 20}
    };
    const int numTestCases = 10;

    for (int i = 0; i < numTestCases; i++) {
        int n = testCases[i][0];
        int r = testCases[i][1];
        int result = testCases[i][2];

        if (choose(n, r) != result) {
            cerr << "Failed test case: choose(" << n << ", " << r << ") = " << result << '\n';
        }
    }

    cout << "Large number tests\n";
    cout << setprecision(15);
    cout << choose(52, 6) << "\n";
    cout << choose(52, 26) << "\n";
    cout << choose(150, 5) << "\n";
}
/*
int main() {
    int n;
    cin>> n;
    cout << mfibo(n);
}

int fibo(int n){
    int a=1,b=1,c;
    for(int i=0;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return n;
}

int fibo2(int n){
    if(n<=2)
        return 1;
    return fibo2(n-1)+fibo2(n-2);

}

int mfibo(int n){
    static int afibo[200]={0};
    if(n<=2)
        return 1;
    if(afibo[n]!=0)
        return afibo[n];
    return afibo[n]=mfibo(n-1)+mfibo(n-2);

}



bool isPrime(int n){ //O(n)
    for (int i=2;i<n;i++){
        if(n%i==0){
            return false; //omega(1)
        }
    }
    return true;
}

bool Prime(int n){ //O(sqrt(n))
    int sn=sqrt(n)+1;
    for (int i=2;i<=sn;i++){
        if(n%i==0){
            return false; //omega(1)
        }
    }
    return true;
}


void bubbleSort(int x[],int n){
    for (int i = 0; i < n; ++i) {
        if(x[i] < x[i+1]){
            int temp =x[i];
            x[i]=x[i+1];
            x[i+1]=temp;

            x[i]^=x[i+1];
            x[i+1]^=x[i];
            x[i]^=x[i+1];

            x[i]+=x[i+1];
            x[i+1]=x[i]-x[i+1];
            x[i]=x[i+1]-x[i];
        }
    }
}

int main(){
    int y[]={1,5,2,4,3};
    size =;
    bubbleSort(y[],size)
}
*/