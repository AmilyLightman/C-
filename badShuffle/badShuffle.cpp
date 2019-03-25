#include <iostream>
#include <random>
#include <cmath>
#include <cstdint>
#include <cstdlib>
/*
	 Wanying Cao
 */

using namespace std;
default_random_engine e;

void swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}


void testShuffle(const int n, const int trials) {
    int a[n];
    int l = n;
    int histogram[l][n];
    for (int i = 0; i <= l; i++){
        for (int j = 0; j <= n; j++) {
            histogram[i][j] =0;
           // cout << histogram[i][j]<< '\t';
        }
       // cout<<'\n';
    }
    for (int i = 0; i < n; i++) {
        histogram[0][i]= i;
        histogram[i][0]= i;
    }
    for (int t = 0; t <= trials; t++) {
        for (int i = n-1; i > 0; i--) {
            uniform_int_distribution<unsigned> u(0,n-1);
            int rand=u(e);
            histogram[i][rand]+=1;
            swap(a[i], a[rand]);
        }
          /*for (int i = 0; i < n; i++){
              a[i] = i;
              histogram[t+1][badShuffle(a, n)]+=1;
          }*/
      }

    for (int k = 0; k < l; k++) {
       if(k==0){
           cout<< "pos num\t";
       }
       else{
           cout<< k <<'\t';
       }
       for (int i = 0; i < n; i++) {
           cout << histogram[k][i]<<'\t';

       }
        cout<<'\n';
    }
}

int main() {
    int n = 10;
    int trials = 1000;
    int mean = trials/n;
    cout << "Try "<< trials << " times\n";
    cout << "Distribution should be "<< mean << " times\n";
    e.seed(0);               // always start testing with a deterministic random number generator!
    testShuffle(n, trials);
    cout << '\n';

}
