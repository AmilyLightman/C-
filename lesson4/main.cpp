#include <iostream>
#include<random>
using namespace std;

class LinkedList{
private:
    class Node{
    public:
        Node*next;
        int val;
        Node(Node*next,int val):next(next),val(val){}
    };
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList():head(nullptr),tail(nullptr),size(0){}
    ~LinkedList(){
        if(tail==nullptr){
            return;
        }
        for(Node*p=head;p!=nullptr;){
            Node*temp =p;
            p=p->next;
            delete temp;
        }
    }
    void addStart(int val){
        Node* p= new Node(head,val);
        if(tail==nullptr){
            tail=p;
        }
        head=p;
        delete p;
        size++;
    }
    void addEnd(int val){
        Node* p=new Node(nullptr,val);
        if(head==nullptr){
            head=p;
        }
        else{
            tail->next=p;
        }
        tail=p;
        delete p;
        size++;

    }
    int removeStart(){
        if(tail==nullptr){
            cout<< "cannot delete";
        }
        else if(head==tail){
            int temp=head->val;
            delete head;
            head=tail=nullptr;
            return temp;
        }
        else{
            int temp=head->val;
            Node* p=head;
            head=head->next;
            delete p;
            //p=nullptr;
            return temp;
        }

    }
    int removeEnd() {
        if(head== nullptr){
            cout<< "cannot delete";
        }
        else if(head==tail){
            int temp=tail->val;
            delete tail;
            head=tail=nullptr;
            return temp;
        }
        else{
            int temp=tail->val;
            Node*p;
            for (p=head; p->next!=tail;p=p->next) {
                ;
            }
            tail=p;
            p=tail->next;
            delete p;
            tail->next=nullptr;
            return temp;
        }
    }
    bool isEmpty()const{
        return size==0;
    }

};

int main(){

    LinkedList a;
    a.addEnd(1);
    a.addStart(10);
    a.addStart(5);
    a.removeStart();
    a.removeEnd();
}


/*
int random(int a,int b){
    return (a+rand()%(b-a+1));
}

int powermod(int a, int n, int m){
    int prod =1; // a^49  49= 32+16+1 =110001
    while(n>0){
        if(n%2!=0)
            prod =prod * a % m;
        a= a*a % m;
        n= n/2 ;//n >> 1;
    }
}


bool MillerRabin(int p, int k){
    for (int i = 0; i < k; ++i) {
        int a = random(2, p - 2);
        int d = p - 1;
        int s = 0;
        while (d & 2 == 0){
            s++;
            d >> 1;
    }
    int x= powermod(a,d,p);
        if(x==1||x==p-1)
            continue;
        for (int j = 0; j < s-1; ++j) {
            x=x*x%p;
            if(x==1)
                return false;
            if(x==p-1)
                goto nextTry;
        }
        return false;
        nextTry:;
    }
}

int main(){
    cout << MillerRabin(17,3)<<'\n';
    cout << MillerRabin(1000,5)<<'\n';
    cout << MillerRabin(10001,5)<<'\n';
    cout << MillerRabin(561,5)<<'\n';
}



//Fermat

int random(int a,int b){
    return a+rand()%(b-a+1);
}

 int powermod(int a, int n, int m){
   int prod =1; // a^49  49= 32+16+1 =110001
   while(n>0){
       if(n%2!=0)
           prod =prod * a % m;
       a= a*a % m;
       n= n/2 ;//n >> 1;
   }
}


bool Fermat(int p, int k){
    for (int i = 0; i < k; ++i) {
        int a = random(2,p-1);
        if(powermod(a,p-1,p)!=1)
            return false;
    }
    return true;
}

int main(){
    cout << Fermat(17,3)<<'\n';
    cout << Fermat(1000,5)<<'\n';
    cout << Fermat(10001,5)<<'\n';
    cout << Fermat(561,5)<<'\n';
}
 */