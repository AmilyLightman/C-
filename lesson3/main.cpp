#include <iostream>
#include <cmath>

using namespace std;
/*
sorting midterm
 good sort O(n logn)
 bad sort O(n2)
 shuffling O(n)     FisherYeats

 searching and rootfinding
 O(n) omega(1)  average n/2->n
 linear search
 O(n) omega(1)  average  n/sth ->n
 binary search(thinking quicksort)  mid-element  // has to be sorted data
 O(log n) omega(1)  average n/2->n


int binarysearch(int x[],int n, int target){
    int L=0, R=n-1;
    if (target < x[L]|| target> x[R])
        return -1;
   while(L<=R) {
       int mid = (L + R) / 2;
       if (x[mid] > target) {
           R = mid - 1;
       }
       else if (x[mid] < target) {
           L = mid + 1;
       }
       else if (x[mid] == target) {
           return mid;
       }
       else{
           return -1;
       }
   }
}
int binarysearch(int x[],int L, int R, int target){
    if(L>R){
        return -1;
    }
    if (target < x[L]|| target> x[R])
        return -1;
    if (L<=R) {
        int mid = (L + R) / 2;
        if (x[mid] > target) {
            binarysearch(x, L, mid - 1, target) ;
        }
        if (x[mid] < target) {
            binarysearch(x, mid + 1, R, target) ;
        }
        if (x[mid] == target) {
            return mid;
        }
    }
    return -1;
}
int main(){
    int target=11;
    cin>>target;
    int x[]={1,3,4,5,6,9,10,19,20,26,41,40,99,200,221};
    cout<< binarysearch(x,sizeof(x)/sizeof(int),target)<<'\n';

}


double f1(double x){return x*x -2;}

typedef double (*FuncOneVar)(double x);


double bisection(FuncOneVar f,double a, double b, double eps){
double mid;
    double ya =f(a);
    double yb = f(b);
    if(ya*yb >0)
        throw "Function does not appear to cross zero\n";
    do{
    mid=(a+b)/2;
    double y =f(mid);
    if(y>0)
        b=mid;
    if(y<0)
        a=mid;
    else
        return mid;}
        while (b-a > eps);
        return mid;
}
int main(){
    cout << bisection(f1,0,3,.01)<<'\n';
    cout << bisection(f1,0,3,.0001)<<'\n';
    cout << bisection(f1,0,3,.000001)<<'\n';
}


Golden Mean Search
 PHI  quanquanhzongjianyigeshuxian
 = sqrt(5)+1)/2 =1.618;
 Quadratic(one hump) only one max



const double phi = (1+sqrt(5))/2;

double GoldenMeanSearch(int data[], int n)
{
    int L=0, R=n-1;
    double S =(R-L)/phi;
    int x=R-S, y=L+S;
    do{
    if (data[x]>data[y]){
        R=y;
        y=x;
        S =(R-L)/phi;
        x= R-S;
    }
    else{
        L=x;
        x=y;
        S =(R-L)/phi;
        y=L+S;
    }}
    while(L>R);
        return data[L];
}
int main(){
    int x[]={1,3,4,26,41,40,99,200,221,20,19,10,9,6,5};
    cout<< GoldenMeanSearch(x,sizeof(x)/sizeof(int))<<'\n';
}


 Number Theoretic Programming

 28=2*14 4*7 sqrt(n)

 Big A
 +
 size O(n+1) O(n)

 *
 size O(2n)  O(n2+n)


 a^x
 if(x%2==1)
 a* (x)^2)^2)^2...


 Femart


 Miler Rabin


*/


































