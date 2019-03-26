#include <iostream>
using namespace std;
/*
    @author Wanying Cao (cwid: 10440141)
*/
using namespace std;
class Complex{
private:
    double real, imag;
public:
    Complex(double real, double imag):real(real), imag(imag){}

    Complex add(Complex b) const
    {
        Complex ans(this->real + b.real, this->imag + b.imag);
        return ans;
    }
    Complex minus(Complex b) const
    {
        Complex ans(this->real - b.real, this->imag - b.imag);
        return ans;
    }
    Complex e() const
    {
        Complex ans(-real, -imag);
        return ans;
    }
    void print() const
    {
    cout << '(' << real << '+' << imag << 'j' <<  ')'<<'\n';
    }
    friend Complex operator +(Complex a, Complex b){
        Complex ans(a.real+b.real,a.imag+b.imag);
        return ans;
    }
    friend Complex operator -(Complex a, Complex b){
        Complex ans(a.real-b.real,a.imag-b.imag);
        return ans;
    }
    friend Complex operator -(Complex a){
        Complex ans(0-a.real,0-a.imag);
        return ans;
    }
    friend ostream& operator << (ostream &s, Complex f){
        if(f.imag > 0) {
            s << '(' << f.real << '+' << f.imag <<'j'<< ')' ;}
        else{
            s << '(' << f.real << f.imag <<'j'<< ')' ;}
        return s;
    }
};


int main() {
    Complex a(2.5, 1.0); // double precision
    Complex b(1.2, 2.3);
    Complex c = a + b;
    Complex d = a - b;
    Complex e = -a;
    a.print();
    cout << a << " + " << b << " = " << c << '\n';
    cout << a << " - " << b << " = " << d << '\n';
    cout << "-" << a << " = " << e << '\n';
    return 0;
}
