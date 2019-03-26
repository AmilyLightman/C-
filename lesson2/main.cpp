#include <iostream>
#include <cmath>
using namespace std;
/*
  Author: Wanying Cao
*/

int main(){
    int array[5]={3,9,2,5,7};
    selectSort(array,5);

}


/*

shuffling is opposite of sorting
 how many ways are there  to order n elements?  n!
 n=10^6  n!

 entropy
 we expect it is easier to shuffle than sort
 //rand() is not useful  if x=rand(); y=rand(); they actually correlated
#include <random>
#include<iostream>
void badshuffle(int x[],int n){
 int y[n];
 int r;
 for(int i =n-1; i>=0; i--){  //O(n)
    do
     r = random(0,i);
    while(x[r]==0){  // 1+1
    y[i] =x[r];
    x[r]=0;
    }
  }
}

 void FischerYates(){
 for(n-1; 0;)
 int r =ramdom(0,n-1)
 swap x[i],x[r]
 }


 // int n=1000000;
 int x[n];
 int hist[10]={0};
 for i 0 to n {
 hist[x[i]]++
int count=0
 for i 0 to 10{
 for j 0 to hist[i]{
 x[count++]=i;
 }
 }
 }

class Person{
 fname,lname
 age
 }


bubblesort/ selectionsort
//  https://www.cnblogs.com/chenxiwenruo/p/8529525.html

insertion  best for small, when the data is already nearly sorted
quicksort  fastest(but vulnerable), best for general sorting unless sth goes wrong with pivot
heapsort  good when quicksort fails, fallback for quicksort
mergesort  best when data exceeds memory

 sort have ay least omega(n)



 void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        bool done =true;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                done =false;
            }
        }
        if(done)
            break;
    }
}

 void selectSort(int a[],int n){
       for (int j= n-1; j>0; j--){
        int max= a[0], maxpos = 0;
        for(int i=j+1;i<j;i++){
            if(a[i] > max){
                max = a[i];
                maxpos=i;
            }
        }
       int temp =a[maxpos];
       a[maxpos] =a[j];
       a[j]=temp;
    }
}

 void insertionSort(int x[],int n){
    for(int i=1;i<n;i++){
        if(x[i-1]>x[i]){
          int temp=a[i];
          for(int j=i-1; i>=0;i--){
              if(x[j]>temp){
              x[j+1]=x[j];
              }
              else{
              x[j+1]=temp;
              break;
              }
          }
      }
}


// quickSort is all about choose a right pivot

 pivot = x[L] will turn into selection sort, dont do it
 pivot = x[R] equally stupid

 pivot = x[random(L,R)]
 pivot = (x[L] + x[R])/2     // not good EX.{1 3 5 7 8 6 4 2}
 pivot = (x[L] + x[R] + x[L+R])/3     // better but EX.{1 4 3 6 5 2}

 void quickSort(int x[],int L,int R){    // O(n log n)
    pivot = x[random(L,R)];
    int i=L, j=R;
    while(i<j){

    while(x[i]< pivot){
    i++;
    }
    while(x[j]> pivot){
    j--;
    }
    if(i<j){
        swap(x[i],x[j])
       }
    }
    if(more than size 1){
        quickSort(x,L,i or j);
        }
        if(more than size 1){
        quickSort(x,i or j,R);
        }
}
 // if testing with random data, make sure it is repeatable
 Java EX.  Random r = new Random(0)  //new Random(i)  i-> 0 to n
 print and if it fail, repeat it


 int quick_partition(int a[],int l,int r){
    int x=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<=x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;

}

void quickSort(int x[],int L,int R){
    if(L<R){
        int mid=quick_partition(x,L,R);
        quickSort(x,L,mid-1);
        quickSort(x,mid+1,R);
    }
}

 Quicksort
 pass =1  n= 10^6
 pass =2  n= 5* 10^5   2 function calls
 pass = log2(n) =  n =2  500k function calls

  KnuthOptimizeQuicksort(int x[], int n){
  partialQuicksort(x,0,n-1); //go until smallest partition size k=200
  insertionsort(x);
  }



void makeheap(){
 for (int i=n/2; i>=0;i--){
 makesubheap(x,i);
 }
 }

 void makesubheap(x,i){
 if (2i+1>x.length)
 return;
 if (2i+2>x.length)
 if (x[2i+1]>x[i])
 swap (x[i],x[2i+1]);
 if x[2i+1]> x[2i>2]{
 if(x[2i+1]>x[i])
 swap (x[i],x[2i+1]);
 makesubheap(x,2i+1);
 }
 else{
 if(x[2i+2]>x[i])
 swap (x[i],x[2i+2]);
 makesubheap(x,2i+2);
 }
 }

  void heapsort(){
  makeheap(x,n);
  for(i = n-1; i>0; i--){
  swap(x[0],x[i])
   makesubheap(x,0);
  }
  }



void mergesort(int x[], int n){

 }



class Bitvec{
private:
    uint32_t size;
    uint64_t* bits;
public:
    Bitvec(uint32_t size, bool b): size(size), bits(new uint64_t[(size+63)/64]){
        uint64_t val = b ?0xFFFFFFFFFFFFFFFF : 0;
        for (int i = 0; i < size; i++) {
            bits[i] = 0;
        }
    }
    ~Bitvec(){delete [] bits;}
    Bitvec(const Bitvec& orig) = delete;
    Bitvec& operator =(const Bitvec& orig)=delete;

    void set(uint32_t i){
        bits[i/64] |=1 << (i % 64);  //   bits[i >> 6] |=1 << (i & 0x3f); same
    }

    void clear(uint32_t i){
        bits[i/64] &= ~(1 << (i % 64));  //   bits[i >> 6] &= (1 << (i & 0x3f)); same
    }

    bool test(uint32_t i){
        return (bits[i/64] & (1 << (i%64))) != 0;
    }
};
*/