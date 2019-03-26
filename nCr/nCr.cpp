#include <iostream>
#include <random>
using namespace std;
/*
  Author: Wanying Cao
*/
double noMemo(int n, int r){
    double num=1.0,den=1.0;
    if (r > n/2){
        r = n-r;
    }
    if(r==0||r==n){
        return 1;
    }
    for (int i = r; i > 1 ; i--) {
        den*=i;
    }
    int k = n -r +1;
    for (int j = n; j >= k; j--) {
        num*=j;
    }
    return num/den;
    //cout << "without memoization, choose(n,r) = "<< choose;
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
    static double memo[500][500]={1};
    if(r==0||r==n){
        memo[n][r]=1;
    }
    // memo[n][r]=memo[n][n-r];
    if (memo[n][r]!=0) {
        return memo[n][r];
    }
    return memo[n][r]=choose(n-1,r-1)+choose(n-1,r);
}

int main() {
    int numTrials = 10000000;
    //  cin >> numTrials;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,500);

    for (int i = 0; i < numTrials; i++) {
        int n = distribution(generator);
        uniform_int_distribution<int> rdist(0,n);
        int r = rdist(generator);
        choose(n,r);
    }
}
