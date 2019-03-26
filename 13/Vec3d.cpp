#include <iostream>
#include <cmath>
using namespace std;
/*
    @author Wanying Cao (cwid: 10440141)
*/
class Vec3d {
private:
    double a,b,c;
public:
    Vec3d (double a=0.0, double b=0.0, double c=0.0): a(a),b(b),c(c){}
    friend Vec3d operator +(Vec3d a, Vec3d e){
        Vec3d ans(a.a+e.a, a.b+e.b, a.c+e.c);
        return ans;
    }
    friend Vec3d operator -(Vec3d b, Vec3d c){
        Vec3d ans(b.a-c.a, b.b-c.b, b.c-c.c);
        return ans;
    }
    friend Vec3d operator -(Vec3d b) {
        Vec3d ans(0.0-b.a,0.0-b.b,0.0-b.c);
        return ans;
    }
   friend ostream& operator << (ostream& s , Vec3d f);
    friend double dot( Vec3d f, Vec3d g);

    double dot(const Vec3d g) const {
        double ans = this->a * g.a+ this->b * g.b + this->c * g.c;
        return ans;
    }
double mag() const {
    double ans = sqrt(pow(this->a,2) + pow(this->b,2) + pow(this->c,2));
    return ans;
    }
double magSq() const {
    double ans = pow(this->a,2) + pow(this->b,2) + pow(this->c,2);
    return ans;
    }
double dist( const Vec3d g) const {
    double ans = sqrt(pow(this->a - g.b,2) + pow(this->b - g.b,2) + pow(this->c - g.c,2));
    return ans;
    }
};
ostream& operator << (ostream& s , Vec3d f)
{
    s <<'('<< f.a <<','<< f.b <<','<< f.c <<')';
    return s;
}
double dot(Vec3d f, Vec3d g)  {
    double ans=f.a*g.a+f.b*g.b +f.c*g.c;
    return ans;
}

int main() {
    // use friend operators
    const Vec3d a(1.0,2.5,3.5); // double precision!
    const Vec3d b(2.0);         //(2,0,0)
    const Vec3d c(2.0,3.5);     //(2,3.5,0)
    const Vec3d e;              //(0,0,0)

    const Vec3d f = a + e;
    const Vec3d g = b - c; // d is not an object, pick a different one
    double x = dot(f, g); // regular function  f.x*g.x + f.y*g.y + f.z*g.z
    //	double y = Vec3d::dot(f,g); // static function
    double z = f.dot(g); // method
    const Vec3d h = -b;

    double dist = f.mag(); // square root of sum of square
    double dist2 = f.magSq(); // sum of square
    double dist3 = f.dist(g); // sqrt or sum of square of diff
    //dx = f.x-g.x  dy = f.y - g.y      dx*dx + dy*dy...
    cout << a << '\n';
    cout << b << '\n';
    cout << c << '\n';
    cout << e << '\n';
    cout << f << '\n';
    cout << g << '\n';
    cout << h << '\n';
    cout << dist << '\n';
    cout << dist2 << '\n';
    cout << dist3 << '\n';
}
