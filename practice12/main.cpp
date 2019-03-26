#include "Account.hh"
#include <cstring>
using namespace std;

class Elephant {
private:
    string name;
public:
    Elephant(const string& name) : name(name) {}
    Elephant() : name() {}
    friend ostream& operator <<(ostream& s, const Elephant& e) {
        return s << e.name;
    }
};

int main() {
    GrowArray<int> a;
    GrowArray<char> b(1000);
    for (int i = 0; i < 10; i++) {
        a.addEnd(i);
    }
    a.removeEnd();
    cout << a;

    GrowArray<Elephant> e;
    e.addEnd(Elephant("Alice"));
    e.addEnd(Elephant("Betty"));
    cout << e << '\n';
}
#if 0//#include "Account.hh"
#include <iostream>
using namespace std;
int main() {
    int a = 2;
    int &r = a;

    const int b =3;
    const int*q =&b;
    q = &a;
    a=1;
    cout<< q<<'\t';
    cout<< *q<<'\n';
    cout<< b<<'\n';
    cout<< a<<'\n';
}



int main() {
    Account a("Dov", 10000000);
    a.deposit(50);
    cout<< a.getBalance()<< '\n';
    while (a.withdraw(1000000))
    {

    }
    return 0;
}






banking:  Main.cpp  Account.cpp  Account.hh

        g++ Main.cpp Account.cpp -o(output) banking

make -k clean
#endif