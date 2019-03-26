#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/*
    @author Wanying Cao (cwid: 10440141)
*/
// donot us #define, its confusing
const double PI = 3.14159265358979;

class Shape { // abstract class
private:
    double x, y;
public:
    Shape(double x, double y): x(x), y(y){}
    //double getX() const{return x;}
    //double getY() const{return y;}
    // pure virtural function ->if class has virtural, its abstract
    virtual double area() const = 0;  // shape is abstract (you cannot make one)
            // cannot instantiate an object
};

class Rect: public Shape {
private:
    double  width, height;
public:
    Rect(double x,double y,double w,double h): Shape(x,y), width(w), height(h){}
    double area () const {return width * height;}
};
class Circle: public Shape{
private:
    double radius;
public:
    Circle(double x,double y,double r): Shape(x,y), radius(r){}
    double area() const {return PI * radius * radius;}
};
class Line: public Shape{
private:
    double x1,y1;
public:
    Line(double x,double y,double x1,double y1): Shape(x,y), x1(x1),y1(y1){}
    double area() const{ return 0;}
};
int main() {
    Rect r1(100, 50, 20, 40);	// Rect(x,y, width, height)
    cout << r1.area() << '\n';
    Circle c1(400, 300, 50); // Circle(x,y,radius)
    cout << c1.area() << '\n'; // area should be pi * radius squared
    Line L1(0,0, 300, 400);
    cout << L1.area() << '\n'; // area should be 0
#if 0// vector<shape> // error, its try to make one shape;
    vector< const Shape*> shapes;
    shapes.push_back(&c1);
    shapes.push_back(&r1);
    shapes.push_back(&L1);
    for(int i = 0; i<shapes.size();i++)
    {
        cout << shapes[i]->area;
    }

    vector<int>a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(4);
    vector<Rect>;
# endif
}