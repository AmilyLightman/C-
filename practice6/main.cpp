#include <iostream>
#include <cmath>
using namespace std;

//  extern void f(); / void f();  link

int main(){
    int y[10]={1,2,3,4};
    int a = 2;
    //int &r = a;  // int &r;  is error
    int* p = &a;
    *p=3;
    cout<< a<< '\n';
    int* q = &y[3];
    cout<< * q<< '\n';
    const int* r = &a;
    cout<< a<< *r << '\n';
    r ++;
    a=5;
    cout<< a << *r << '\n';
    int* const w = &a;
    (*w)++;
    a =3;
    cout<< a << *w << '\n';
    const int * const x = &a;
    a=0;
    cout<< a << *x << '\n';
    //int i = &a;
   // cout<< i;
}
#if 0
int main() {
     int x[10],z[10];
    x[0]=5;
    int* const p=x;
    cout<< x[0]<<p[0]<<'\n';
    p[0]=22;
    // p++;   error, cannot move p
    const int y[10]={3};
    const int* q= &y[10]; // error *p = 99
    const int *r =z;
    z[0]= 55;
    r++;
    const int* const u =y;

int a=2,b=3;
   int x[10];
    int *p=x;
    cout << *p;
    int y[10]={3};
    p=y;           // y[0]
    cout << *p;
    p++;           // y[1]
    *p = 19;
    cout << y[10];
    ++*p;  // *p +1   -> *p = 20
    int q = *p++;  //q = *p, p++  -> q = 20, *p point y[2]
    (*p)++; // y[2] = 1;
    q = (*p)++; // q = 1, y[2] = 2;
    q= *++p; // *p point y[3] , q = 0;
            q =++*p; // y[3] = 1, q = 1;
    int *z = &a;
    cout << *z;
   p = &y[3];  // address
    //cout << p;
   a=5;
    cout << *z;
    int *const w = &a;
    cout << *w;
    a=1;
    cout << *w;
    cout << *z;
    const int *r = &a;
    const int *const x = &a;
}

class Vec3d
{
private:
    double x,y,z;
public:
    Vec3d (double x=0,double y=0, double z=0): x(x), y(y), z(z) {}

    friend ostream& operator << ( ostream& os, const Vec3d& a)
    {
        os << '(' << a.x <<',' << a.y << ',' << a.z << ')';
        return os;
    }

    friend Vec3d operator +( Vec3d a, Vec3d b)
    {
        Vec3d sum;
        sum.x = a.x + b.x;
        sum.y = a.y + b.y;
        sum.z = a.z + a.z;
        return sum;
    }

    friend Vec3d operator -( Vec3d a, Vec3d b)
    {
        Vec3d sum;
        sum.x = a.x - b.x;
        sum.y = a.y - b.y;
        sum.z = a.z - a.z;
        return sum;
    }

    friend Vec3d operator -( Vec3d a)
    {
        Vec3d sum;
        sum.x = -a.x;
        sum.y = -a.y;
        sum.z = -a.z;
        return sum;
    }

    friend double dot(const Vec3d a, const Vec3d b);

    static double dot(const Vec3d a, const Vec3d b)
    {
        return (a.x*b.x+a.y*b.y+a.z*b.z);
    }

    double dot(const Vec3d& a)
    const {
        double sum;
        sum = this->x*a.x + this->y*a.y + this->z*a.z;
        return sum;
    }

    double mag()
    const{
        return sqrt(x*x+y*y+z*z);
    }

    double magSq()
    const{
        return x*x+y*y+z*z;
    }

    double dist(const Vec3d& a)
    const{
        return sqrt(pow(this->x-a.x,2)+pow(this->y-a.y,2)+pow(this->z-a.z,2));
    }


};

double dot(const Vec3d a, const Vec3d b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}






int main() {
    // use friend operators
    const Vec3d a(1.0,2.5,3.5); // double precision!
    const Vec3d b(2.0);         //(2,0,0)
    const Vec3d c(2.0,3.5);     //(2,3.5,0)
    //const Vec3d d(); // d is a function that returns Vec3d
    const Vec3d e;

    const Vec3d f = a + e;
    const Vec3d g = b - e; // d is not an object, pick a different one
    double x = dot(f, g); // regular function
    double y = Vec3d::dot(f,g); // static function
    double z = f.dot(g); // method
    const Vec3d h = -b;

    double dist = f.mag(); // square root of sum of square
    double dist2 = f.magSq(); // sum of square
    double dist3 = f.dist(g); // sqrt or sum of square of diff
    cout << a << '\n';
    cout << b << '\n';
    cout << c << '\n';
    cout << e << '\n';
    cout << f << '\n';
    cout << g << '\n';
    cout << h << '\n';
    //cout << dist << '\t' << dist2 << '\t' << dist3;
    cout << dist << '\n';
    cout << dist2 << '\n';
    cout << dist3 << '\n';
}


2 / 6 pts
void readIn(int x[ 3 ][ 3 ]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >>
                x[i][j]
                    ;
}

//a+b

void add(int c[ 3 ][ 3 ], int a[ 3 ][ 3 ], int b[ 3 ][ 3 ]) {
    for (int i = 0; i < 3; i++)
        for (int j =0; j < 3; j++)
            c[ i ][ j ] =
                    ;
}

// a - b

void subtract(int c[ 3 ][ 3 ], int a[ 3 ][ 3 ], int b[ 3 ][ 3 ]) {
    for (int i = 0; i < 3; i++)
        for (int j =0; j < 3; j++)
            c[ i ][ j ] =
                    ;
}

//a*b

void multiply(int c[ 3 ][ 3 ], int a[ 3 ][ 3 ], int b[ 3 ][ 3 ]) {
    int n=0;
    int i2,j2;
    for (int i = 0; i < 3; i++)
    {
        for (int j =0; j < 3; j++)
        {


            ;
            for(i2=0,j2=0;i2<3,j2<3;i2++,j2++)
                n+=
                        ;
            c[ i ][ j ] = n;
        }
    }
}

void print(int x[ 3 ][ 3 ]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout <<
                 x[i][j]
                 << " ";
        cout << "/";
    }
}
int main()
{
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int b[3][3]={9,8,7,6,5,4,3,2,1};
    int c[3][3];
    multiply(c,a,b);
    print(c);
}

30 24 18 /84 69 54 /138 114 90 /




int x[]={0,1,2,3,4,5};
    int a = 2;
    int* p = &a;
    int* q = &x[3];
    const int* r = &a;
    int* const w = &a;
    const int * const x = &a;

int main(){
    int a = 2, b = 3;
    int c = a++; // c = 4, a = 5
    int c = ++a; // a = 6, c = 6
    int d = b++ - --a; // a = 5, d = 3 - 5 = -2, b = 4
}
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
#endif


