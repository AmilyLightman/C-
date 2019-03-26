#include <iostream>
using namespace std;
#if 0
int *p = a;
int p= a[0]; //error   *p = &a[0]
double *q= &b[4];
double *q= b + 4;

void f (int x){
    cout << x;
    x=0;
}
void g (int &x){
    cout << x << '\n';
    x=0;
}
void h (int* x){
    cout << *x;
    *x=0;
}
int main()
{
    int a;
    int *p = &a;
    cout << p << '\t' << &a << '\n';
    cout << &p << '\n';
    f(a);
    cout << a << '\n';
    g(a);
    cout << a << '\n';
    h(&a); //pass address of a, a could change...
    cout << a << '\n';
    h(nullptr);
    return 0;
}

int main(){
    int a =  1010101;
    double *p;
    // p=&a;  this doesnot work
    p = (double*) &a;
    cout << *p << '\n';
    return 0;
}

class Vehicle { // class becomes abstract with pure virtual function
private:
    double speed;
public:
    Vehicle(double speed) : speed(speed) {}
    friend ostream& operator <<(ostream& s, const Vehicle& v) {
        return s << v.speed;
    }
    virtual	void payToll() const = 0; // a class that contains 1 or more pure virtual functions is abstract
};

// has speed and number of passengers
class Bus : public Vehicle { // A bus IS_A Vehicle  IS_A KIND OF      use inheritance
private:
    int numPassengers;
public:
    Bus(double speed, int numPassengers)
            : Vehicle(speed), numPassengers(numPassengers)  { // the order of initialization is the order in memory.  Specifying out of order is IGNORED
        //this->speed = speed; //not allowed
    }
    void payToll() const {
        cout << "$4";
    }
};

// has a speed and weight and number of axles
class Truck : public Vehicle {
private:
    double weight;
    int numAxles;
public:
    Truck(double speed, double weight, int numAxles)
            : Vehicle(speed), weight(weight), numAxles(numAxles) {}
    void payToll() const {
        cout << '$' << 4 * numAxles;
    }

};

// has color and speed
class Car : public Vehicle {
private:
    string color;
public:
    Car(double speed, const string& color)
            : Vehicle(speed), color(color) {}
    void payToll() const {
        cout << "$15";
    }
};

int main(){
   Vehicle* v[1000];
   cout << sizeof(Vehicle*) << '\n';
   Car c1(55, "red");
   Bus b1(90, 28);
   Truck t1(48, 12000, 6);
   t1.payToll();
   v[0] = &c1;
   v[1] = &t1;
   v[2] = &b1;
   for(int i=0; i<3; i++)
   {
       //(*v[i]).payToll();   // polymorphic call(1 name different actions)
       v[i]->payToll();

   }
   //c[0] = Truck(...);
   //c[1] = Car(...);
   //c[2] = Bus(...);
    return 0;
}


int main(){
    int a = 0;
    for (int i=0;i<3; i++){
        a+=2;
        const int b=a;
        cout << a << '\n' << b  <<'\n' ;
    }
}

class Fraction {
private:
    int num, den;
public:
    Fraction() : Fraction(0, 1) {} //call Fraction(int num, int den)
    Fraction(int n) : Fraction(n, 1) {}  //call Fraction(int num, int den)
    Fraction(int n, int den) : num(n), den(den)     //call private
    {
        //num   this->num;
    }

    void print() const {
        cout << num << '/' << den << "\n";
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
        return (this->num * r.den + r.num * this->den, this->den * r.den);
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
    f3.print();
    f3= f2.add(f4);
    f3.print();
}

class A
{

};

class Fraction
{
private:
    uint32_t num, den;
public:
    Fraction(uint32_t n, uint32_t d): num(n),den(d){}

    friend Fraction operator+(Fraction a, Fraction b){
            return Fraction(a.num * b.den + b.num * a.den, a.den * b.den);
    }
    friend ostream& operator<<(ostream&s, Fraction f){
        s << f.num <<'/' << f.den;
        return s;
    }
};

int main()
{
    int x;
    Fraction f1(1,2);
    Fraction f2(1,2);
    A a1;
    Fraction f3=f1+f2;
    cout << f3 << '\n';
    cout << sizeof(char) << '\n';
    cout << sizeof(x) << '\n';
    cout << sizeof(a1) << '\n';
    cout << sizeof(f1) << '\n';
}

int main(){
    int a = 2, b = 3;
    int c = a++; // c = 4, a = 5
    int c = ++a; // a = 6, c = 6
    int d = b++ - --a; // a = 5, d = 3 - 5 = -2, b = 4
}
#endif

int main(){
    int a = 2;
    int x [10];
    int *p =x;
    int y [10] = {3};
    p=y;
    //int *q =&a;
    cout << x << '\n';
    cout << *p << '\n'; // 3
    p++;
    cout << *p << '\n';

    *p =19;
    ++ *p;  //*p = 20
    int q = *p++; // (q = *p) -> (p++)  q = 20, p piont to y[2]
    (*p)++; // y[2] = 1
    q = (*p)++; // q = 1, y[2] = 2
    q = *++p; // p = &y[3]  q = *p = 0
    q = ++*p; // y[3] = 1  q = 1
}


