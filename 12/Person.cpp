#include <iostream>
#include <string>
using namespace std;
/*
    @author Wanying Cao (cwid: 10440141)
*/

class Person{
private:
    string firstname, lastname;
    static int count;
public:
    Person(string i, string j): firstname(i),lastname(j){
        count++;
      //  cout << "Hello I'm just born! my name is: "<< firstname <<' ' << lastname << '\n';
    }
#if 0
~Person(){
        count--;
      cout << "Ugh! I'm dying " << '\n';}
#endif
    static int getCount(){ return count;}
    friend ostream& operator<<(ostream& s, Person r);
};

int Person::count = 0;
ostream& operator<<(ostream& s, Person r){
    s << r.firstname <<' ' << r.lastname ;
    return s;
}

int main() {
    Person a("Dov", "Kruger");
    Person b("Min", "Song");
    cout << a << '\n';
    cout << b << '\n';
    cout << Person::getCount() << '\n';
}
