#include <iostream>
#include<fstream>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;
/*
  Author: Wanying Cao
*/
const double PHI = (1+sqrt(5))/2;
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
void insertionSort(int x[],int L, int R) {
    for (int i = L; i < R; i++) {
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
void partQuickSort(int x[],int L,int R, int k){    // O(n log n)
    long ran=random();
    int pivot = x[ran%(R-L)+L];
    //cout<<pivot;
    int i=L, j=R;
    while(i<j){
        while(x[i]<= pivot && i<R){
            i++;
        }
        while(x[j]> pivot){
            j--;
        }
        if(i<j){
            swap(x[i],x[j]);
        }
    }
    if(i-L>k){
        if (i - L > 1) {
            if(test(x,L,i))
                partQuickSort(x, L, i, k);
        }
        if (R - j > 1) {
            if(test(x,j,R))
                partQuickSort(x, j, R, k);
        }
    }
}

void knuth(int x[], int L, int R, int k){
    partQuickSort(x, L, R, k);
    insertionSort(x,L, R);
}

void timer(int orig[],double cost[],int n, int k) {
    int array[n];
    for (int i = 0; i < n; i++) {
        array[i] = orig[i];
   }
    auto start = system_clock::now();
    knuth(array, 0, n - 1, k);
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cost[k] = 1000 * double(duration.count()) * microseconds::period::num / microseconds::period::den;
//cout<< double(duration.count())* microseconds::period::num/microseconds::period::den <<'\n';
//double cost1 = double(duration.count())* microseconds::period::num/microseconds::period::den;
    cout << "k = " << k << " took: " << cost[k] << " ms\n";
}

int goldenMean(int orig[],int n){
    double cost[n];
    //int bestK = 0;
    int L= 10,R= 1000;
    double S= (R - L) / PHI ;
    int x1 = (int)(R - S), x2 =(int)(L + S);
    timer(orig, cost, n,L);
    timer(orig, cost, n,R);
    timer(orig, cost, n,x1);
    timer(orig, cost, n,x2);
    while(R-L>1) {
        if (cost[x1] <= cost[x2]) {
            R = x2;
            x2 = x1;
            S = (R - L) / PHI;
            x1 = (int)(R - S);
            timer(orig, cost, n,x1);
        }
        else
        {
            L = x1;
            x1 = x2;
            S = (R - L) / PHI;
            x2 =(int)( L + S);
            timer(orig, cost, n,x2);
        }
    }
    if(cost[L]>=cost[R])
    {
        return R;
    }
    return L;
}

/*
    if(k != 0){
        //cout << "cost[k] = " << cost[k] << "cost[bestK]= "<< cost[bestK];
        if( cost[k] < cost[bestK])
            bestK = k;

        //cout <<"bestK = "<< bestK<< '\n';
        }
    //cout<< "cost"<< cost << "s\n";

    cout <<"bestK = "<< bestK<< '\n'<< "cost = " << cost[bestK]<< " ms\n\n";
    return bestK;}*/


int main() {
    /*int k=200;
    cout << "Choose a k=";
    cin >> k;  */

    int n=10000;
    /*
    ifstream in("/Users/caowanying/CLionProjects/Knuth/hw3.dat");
    //ifstream in("hw3.dat");
    if (!in)
    {
        cout << "file open error" << endl;
        return 1;
    }
    in >> n;
    cout<< "n = " << n<<"\n";*/
    int orig[n];
    //cout<< "the original array: ";
    for (int i = 0; i < n; i++) {
        orig[i]=(int)(random()%n);
        //cout<< orig[i]<<" ";
    }
    cout<< "\n";

    int bestK= goldenMean(orig, n);
    knuth(orig, 0, n-1, bestK);
    cout <<"bestK = "<< bestK<< '\n';

    /*cout<< "After QuickSort array: ";
    for (int i = 0; i < n; ++i) {
        cout<< orig[i]<<" ";
    }
    cout<< "\n";
    return 0;*/
}

/*
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
void insertionSort(int x[],int L, int R) {
    for (int i = L; i < R; i++) {
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
void quickSort(int x[],int L,int R, int k){    // O(n log n)
    long ran=random();
    int pivot = x[ran%(R-L)+L];
    //cout<<pivot;
    int i=L, j=R;
    while(i<j){
        while(x[i]<= pivot && i<R){
            i++;
        }
        //cout<<i;
        while(x[j]> pivot){
            j--;
        }
        //cout<<j<<endl;
        if(i<j){
            swap(x[i],x[j]);
        }
    }
    if(i-L>k){
        if (i - L > 1) {
            if(test(x,L,i))
                quickSort(x, L, i, k);
        }
        if (R - j > 1) {
            if(test(x,j,R))
                quickSort(x, j, R, k);
        }
    }
}

int main() {
    int n;
    ifstream in("/Users/caowanying/CLionProjects/quickSort/hw2.dat");
    if (!in)
    {
        cout << "file open error" << endl;
        return 1;
    }
    in >> n;
    cout<< "n = " << n<<"\n";
    int array[n];
    cout<< "the original array: ";
    for (int i = 0; i < n; i++) {
        in >> array[i];
        cout<< array[i]<<" ";
    }
    cout<< "\n";
    cout<<  ""<<'\n';
int k=200;
cout << "Choose a k=";
cin >> k;

int k, bestK=0;
double cost=0.0,costK;
//long double cost[n];
for (k = 0; k < 200; k+=20) {
if(k == 0){
auto start = system_clock::now();
quickSort(array, 0, n-1,k);
insertionSort(array,0, n-1);
auto end= system_clock::now();
auto duration= duration_cast<microseconds>(end-start);
costK = 1000* double(duration.count())* microseconds::period::num/microseconds::period::den;
cout<< "costK = "<<costK<<"ms\n";
cost = costK;
cout<< "cost = "<<cost<<"ms\n";
bestK = 0;
//double cost1 = double(duration.count())* microseconds::period::num/microseconds::period::den;
//cout << cost1 <<'\n';
}
else{
auto start = system_clock::now();
quickSort(array, 0, n-1,k);
insertionSort(array,0, n-1);
auto end= system_clock::now();
auto duration= duration_cast<microseconds>(end-start);
costK = 1000* double(duration.count())* microseconds::period::num/microseconds::period::den;
cout<< "costK = "<<costK<<"ms\n";
if(costK< cost)
bestK = k;}
//cout<< "cost = "<< cost << "s\n";
cost= costK;
}
cout <<"bestK = "<< bestK<< '\n'<< " cost = " << cost<< "ms\n";
cout<< "After QuickSort array: ";
for (int i = 0; i < n; ++i) {
    cout<< array[i]<<" ";
}
return 0;
}
*/