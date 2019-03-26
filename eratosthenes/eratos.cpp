#include <iostream>
#include <cmath>
using namespace std;
/*
  Author: Wanying Cao
*/
void era(int n){
    int p[n];
    p[2]=1;
    for (int i = 3; i <= n ; i+=2) {
        p[i]= 1;
    }
    for (long j = 3; j <= n; j+=2) {
        if(p[j]==1){
            for (long k = j*j; k <= n; k+=2*j) {
                p[k]=0;
            }
        }
    }
    int court=0;
    if(n<2){
        cout << " the number of primes from 1 to n is " << court;
    }
    else{
        court+=p[2];
        for(int i = 3; i <= n; i+=2){
            court+= p[i];
        }
    cout << " the number of primes from 1 to n is " << court;
    }
}

int main() {
    int n;
    cout<<"Input one number n: ";
    cin >> n;
    era(n);
    return 0;
}

/*
bool isPrime(int n){
    for (int i = 3; i <= sqrt(n); i+=2) {
        if(n % i ==0){
            return false;
        }
    }
    return true;
}

int courtP(int n){
    int court =1;
    if(n<2){
        court =0;
        return court;
    }

    for(int i = 3; i <= n; i+=2){
        if(isPrime(i)){
            court++;
        }
    }
    return court;
}

int main() {
    int n;
    cout<<"Input one number n: ";
    cin >> n;
    cout << " the number of primes from 1 to n is " << courtP(n);;
    return 0;
}

*/