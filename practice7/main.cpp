#include <iostream>
using namespace std;
int main() {
    int a = 5;
    const int &b=a;
    a=6;
    cout<<b<<endl;
    return 0;
}
#if 0
int main()
{
    int x[]={4,3,2,1};
    int *p = &x[0]; //*p = &x[0]=4
    int *q = &x[3]; //*q = &x[3]=1
    *p++  = *q--; //*p = &x[0]=1,*q=&x[2]=2
    cout<< *p<< ' '<<*q<<'\n';
    for(p=&x[3];p>x;p--)
    {
        cout<< *p << ' ';
    }
    cout<<'\n';
    for(p=&x[3];p>=x;p--)
    {
        cout<< *p << ' ';
    }
    cout<<'\n';
}

class DynamicArray
{
    private:
    int *p;int size_;

    public:
    DynamicArray():p(nullptr),size_(0){}
    DynamicArray( const DynamicArray& orig):size_(orig.size_)
    {
        p =new int[size_];
        for(int i=0;i < size_;i++)
        {
            p[i]=orig.p[i];
        }
    }
    ~DynamicArray():
    {
        delete [] p;
    }
int size() const {return size_;}
void addEnd(int v)
{
    int *old = p;
    p = new int[size_+1];
    for(int i=0;i < size_;i++)
    {p[i] = old[i];}
    p[size_] =v;
    delete old;
    size_++;
}

friend ostream& operator << (ostream& s, DynamicArray f)
{
    for(int i=0;i<a.size(); i++)
    {
        s<< p[i];
        return s;
    }
}
};
int main()
{
    int*p= new int;
    *p =5;
    delete p;
    p = new int[1000];
    for(int i=0;i<1000;i++)
    {
        p[i]=i;
    }
    delete []p; // delete p -> crash!! must only delete pointers allocated with new
    int*q = new int[10];
    q++;

    delete []q; //crash!! you did not delete the pointers you were given
}


#include <stdlib.h> //for random, but dont use it

int main()
{
    int a[]= {1,3,5};
    int b[10]= {2};
    int n;
    cin >> n;
    int c[n]; // new int[n]
    for(int i=0;i<n; i++)
    {
        c[i]=rand();//
    }
    for(int *p =&c[n-1];p>=c;p--)
    {
        cout << *p << ' ';
    }
}



int realn(int x[3][3])
{
    for (int i=0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> x[i][j];
        }
    }
    for (int i=0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<< x[i][j];
        }
    }

}
int add(int x[3][3],int a[3][3],int b[3][3])
{
    for (int i=0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            x[i][j]=a[i][j]+b[i][j];
        }
    }
}
int main() {
    int x[3][3];
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int b[3][3]={9,8,7,6,5,4,3,2,1};
    add(x,a,b);
    for (int i=0;i<3;i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<< x[i][j];
        }
        cout<<'\n';
    }
  return 0;
}
#endif