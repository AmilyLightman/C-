#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*
  Author: Wanying Cao
*/
template<typename T>
class LinkedList {
private:
    class Node {
    public:
        Node *next;
        T val;
        Node(Node *next, const T &v) : next(next), val(v) {}
    };

    Node *head;
    Node *tail;
    int l=0;

public:
    LinkedList() : head(nullptr), tail(nullptr), l(0) {}

    ~LinkedList() {
        for (Node* p = head; p != nullptr;) {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
    }

    void addStart(const T &v) {
        Node *temp = new Node(head, v);
        if (tail == nullptr) {
            tail = temp;
        }
        head = temp;
        l++;
    }

    void addEnd(const T &v) {
        Node *temp = new Node(nullptr, v);
        if (head == nullptr) {
            head = temp;
            return;
        } else {
            tail->next = temp;
        }
        tail = temp;
        l++;
    }

    int size() {
        int count = 0;
        for (Node *p = head; p != nullptr; p = p->next) {
            count++;
        }
        return count;
    }

    int size2() {
        return l;
    }

    T get(int pos) {
        Node *p = head;
        for (int i = 0; i < pos; i++) {
            p = p->next;
        }
        return p->val;
    }

    int removeStart() {
        Node *temp = head;
        head = head->next;
        l--;
        //return temp->val;
        delete temp;
    }

    int removeEnd() {
        Node *temp = head;
        for(;temp->next!=tail;temp=temp->next){
           ;
        }
        tail=temp;
        temp=tail->next;
        tail->next=nullptr;
        //return temp->val;
        delete temp;
        l--;
    }

    LinkedList(const LinkedList &orig) {
        if (orig.head == nullptr) {
            head = nullptr;
            return;
        }
        Node *src = orig.head;
        Node *dest = orig.head->next;
        while (src != nullptr) {
            //dest->next= src->next;
            dest = dest->next;
            src = src->next;
        }
    }
    void print(){
        vector<int> iter;
        for( Node* temp=head;temp!=nullptr;temp=temp->next) {
            iter.push_back(temp->val);
        }
        for (vector<int>::const_iterator i=iter.begin();i!=iter.end();i++) {
            cout<< *i << ' ';
        }
        cout<< '\n';
    }

    void print2(){
        for (Node* temp=head; temp!= nullptr;temp=temp->next) {
            cout<< temp->val << ' ';
        }
        cout<< '\n';
    }
};
    int main() {
        LinkedList<int> L1;
        string s;
        int from,step,end,num;
        char c;
        ifstream f("HW4b.txt");
        //ifstream f("/Users/caowanying/CLionProjects/LinkedList/HW4b.txt");
        if(!f){
            cout<< "file open error"<<'\n';
        }
        while(!f.eof()){
            f >> s;
            if(s == "ADD_FRONT"){
                f >> from >> c >> step >> c >> end;
                for(int i=from;i<=end;i+=step){
                    //cout<< i;
                    L1.addStart(i);
                }
            }
            else if(s == "ADD_BACK"){
                f >> from >> c >> step >> c >> end;
                for(int i=from;i<=end;i+=step)
                L1.addEnd(i);
            }
            else if(s == "REMOVE_FRONT"){
                f >> num;
                for (int i = 0; i < num; i++) {
                    L1.removeStart();
                }
            }
            else if(s == "REMOVE_BACK"){
                f >> num;
                for (int i = 0; i < num; i++) {
                    L1.removeEnd();
                }
            }
            else if(s == "OUTPUT"){
                L1.print();
            }
        }
        f.close();


    }

/*
template<typename T>
class LinkedList {
private:
    class Node {
    public:
        Node *next;
        Node *prev;
        T val;

        Node(Node *next, Node *prev, const T &v) : next(next), prev(prev), val(v) {}
    };

    Node *head;
    Node *tail;
    int l;

public:
    LinkedList() : head(nullptr), tail(nullptr), l(0) {}

    ~LinkedList() {
        for (Node *p = head; p != nullptr;) {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
    }

    void addStart(const T &v) {
        Node *temp = new Node(head, nullptr, v);

        if (tail == nullptr) {
            tail = temp;
        } else {
            head->prev = temp;
        }
        head = temp;
        l++;
        delete temp;
    }

    void addEnd(const T &v) {
        Node *temp = new Node(nullptr, tail, v);
        if (head == nullptr) {
            head = temp;
            return;
        } else {
            tail->next = temp;
        }
        tail = temp;
        l++;
        delete temp;
    }

    int size() {
        int count = 0;
        for (Node *p = head; p != nullptr; p = p->next) {
            count++;
        }
        return count;
    }

    int size2() {
        return l;
    }

    int get(int pos) {
        Node *p = head;
        for (int i = 0; i < pos; i++) {
            p = p->next;
        }
        return p->val;
    }

    int removeStart() {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        l--;
        delete temp;
    }

    int removeEnd() {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        l--;
    }

    LinkedList(const LinkedList &orig) {
        if (orig.head == nullptr) {
            head = nullptr;
            return;
        }
        Node *src = orig.head;
        Node *dest = orig.head->next;
        while (src != nullptr) {
            //dest->next= src->next;
            dest = dest->next;
            src = src->next;
        }
    }

    LinkedList<int> f() {
        LinkedList a;
        a.addEnd(5);
        a.addStart(4);
        return a;



        class Iterator{
        private:
            Node* current;
        public:
            Iterator(DoublelinkedList<T>& list): current(list.head){}
            bool hasNext(){
                return current!= nullptr;
            }
        };
}
};
 for(vector<int>:: iterator i= a.begin();i!=a.end; i++){
 cout << *i << ' ';
 cout << '\n';

 */