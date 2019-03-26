#include <iostream>
using namespace std;

const;


class Fraction {
private:
    int num, den;
public:
    Fraction() : Fraction(0, 1) {} //call Fraction(int num, int den)
    Fraction(int n) : Fraction(num, 1) {}  //call Fraction(int num, int den)
    Fraction(int num, int den) : num(num), den(den)     //call private
    {
        //num   this->num;
    }

    void print() const {
        cout << num << '/' << den;
    }

    Fraction add(Fraction r) const {
        Fraction ans(this->num * r.den + r.num * this->den, this->den * r.den);
        //ans.num = ;
        //ans.den = ;
        //this->num this-> den for add    r.num r.den for r
        return ans;
    }

    Fraction add1(Fraction r) {
        Fraction ans(num * r.den + r.num * den, den * r.den);
        //this->num this-> den for add    r.num r.den for r
        return ans;
    };

    Fraction add2(Fraction r) {
        return (num * r.den + r.num * den, den * r.den);
    }
};
    //  ; is really nesessery

int main(){
    Fraction f1;
    const Fraction f2(1,2);
    Fraction f3(5);
    Fraction f4(1,3);
    f1.print();
    f2.print();
    f3= f2.add(f4);
    f3.print;
}


//  A::f()   a.f()   sizeof(int);     ? :
// example  int c = a > b? a + 2 : b + 3;

//   next week quiz : class & const

class Fraction{
private:
    int num, den;
public:
   Fraction():{}
   void add(); // methods have the right to access private components

    friend ostream& operator << (ostream& s, Fraction f)//;
    {
        return s << f.num << '/' << f.den;
        // s << f.num << '/' << f.den;
        // return s;
    }
};

friend ostream&operater(ostream& ,Complex);
};
ostream& operater (ostream& s, Complex r)
{
    s << r.real << "+" << r.imag << "j \n";
    return s;
}
//friend
//ostream& operator << (ostream& s, Fraction f){
   // s << f.num << '/' << f.den;
   // return s;}

int main(){
    Fraction f1(1,2);
    Fraction f2(3);
    Fraction f3;
    cout << f1 <<'\n';

}


class Trace{
    private:
    string name;
    public:

    Trace(const string& functionName): name(functionName){
        cout<< "Entering function" << name <<'\n';
    }
    ~Trace(){
        cout<< "Leaving function" << name <<'\n';
    }
};

void g(){
    Trace t("g");  //Entering function g ...... Leaving function g
    cout << "a";
}

void f(){
    Trace t("f");  //Entering function f ...... Leaving function f
    cout << "b";
    g();
    cout << "c";
}

int main (){
    cout << "d";
    f();
    cout << "f";
}




Extra:

list of sth.
vecctor (singer block of memory like an array but can grow)
         inserting at the beginning or the midder very expensive
list (linked list), slower than vector for building, but much faster
         for

map   look up x-->y (tree)
unordered_map (hash table)



class Zebra{
private:

public:

};

int main(){
vector<int> a;
for(int i = 0; i < 10; i++)
a.push_back(i);

for(int i = a.size() - 1; i >=0; i--)
cout << a[i] << ' ';
cout << '\n';

list<Zebra>b;
b.push_back(Zebra("Fred"));
b.push_back("Alice");

    for(int i = 0; i < b.size(); i++)
        cout << b[i];

    for(list<Zebra>::iteartor i = b.begin(); i != b.end(); i++)
        cout << *i;

    for(auto x:b)
        cout << x;

}






