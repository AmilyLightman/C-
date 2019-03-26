#include <iostream>
#include <random>
#include <cmath>
#include <fstream>
using namespace std;
/*
   Author: Wanying Cao
*/
class GrowArray{
private:
    int capacity;
    int len;
    int* data;

    void checkGrow(){ // double the size
        if(len == 0) {
            data=new int[capacity];
        }
        if (len < capacity){
            len++;
            return;
        }
        int *old=data;
        capacity *= 2;
        data= new int[capacity];
        for (int i = 0; i < len; i++)
            data[i] = old[i];
        len++;
        delete [] old;
    }

public:
    GrowArray(): data(nullptr),capacity(1),len(0){}

    ~GrowArray(){
        delete [] data;
    }

    GrowArray(const GrowArray& orig):capacity(orig.capacity),len(orig.len),data(new int[capacity]){
        for (int i = 0; i < len; i++) {
            this->data[i]=orig.data[i];
        }
    }

    GrowArray& operator =(const GrowArray& g){
        GrowArray copy(g);
        this->len=g.len;
        this->capacity=g.capacity;
        this->data=g.data;
        return *this;
    }

    void addStart(int val){
        checkGrow();
        int *old = data;
        data= new int[capacity];
        data[0]=val;
        for (int i = 1; i < len; i++) {
            data[i]=old[i-1];
        }
        delete [] old;
    }

    void insert(int pos, int val){
        checkGrow();
        int *old = data;
        data= new int[capacity];
        for (int i = 0; i < pos; i++) {
            data[i]=old[i];
        }
        data[pos]=val;
        for (int j = pos+1; j < len; j++) {
            data[j]=old[j-1];
        }
        delete [] old;
    }

    void addEnd(int val){
        checkGrow();
        data[len-1] = val;
    }

    void removeStart(){
        for (int i = 0; i < len-1; i++)
            data[i]=data[i+1];
        len--;
    }

    int removeEnd(){
        len--;
        return data[len];
    }

    void remove(int pos){
        int *old = data;
        data= new int[capacity];
        for (int i = 0; i < pos; i++) {
            data[i]=old[i];
        }
        for (int j = pos; j < len-1; j++) {
            data[j]=old[j+1];
        }
        delete [] old;
    }

    int size()const{
        return len;
    }
    int get(int pos){
        return data[pos];
    }
    void set(int pos, int val){
        data[pos]=val;
    }

    friend ostream& operator <<(ostream& s, const GrowArray& orig) {
        for (int i = 0; i < orig.len; i++) {
            s << orig.data[i] << ' ';
        }
        return s;
    }

};

int main(){
    GrowArray L1;
    L1.addEnd(5);
    L1.addStart(3);
    GrowArray L2 = L1;
    GrowArray L3;
    L2 = L3;
    //f(L1);
    const int n = 100;
    for (int i = 0; i < n; i++){ // 1+2+3 + ... + n
        L1.addEnd(i);
    }
    L1.insert(2, 19); // insert the 19 before the 0
    L1.removeEnd(); // 9
    L1.removeStart(); // 3
    cout << L1 << "\n";
    cout << L2 << "\n";
    cout << L3 << "\n";

}
