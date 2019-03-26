#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
/*
  Author: Wanying Cao
*/

class Point{
private:double x,y;
public:
    Point():x(),y(){}
    Point(double x, double y) : x(x), y(y) {}
    friend ostream& operator <<(ostream& s, const Point& p) {
        return s << p.x <<' '<< p.y<< '\n';
    }
};
template <typename T>
class GrowArray{
private:
    int capacity;
    int len;
    T* data;
    void checkGrow(){ // double the size
        if(len == 0) {
            data=new T[capacity];
        }
        if (len >= capacity){
            T *old=data;
            capacity *= 2;
            data= new T[capacity];
            for (int i = 0; i < len; i++)
                data[i] = old[i];
            delete [] old;
        }
        len++;
    }

public:
    double minx=-1, maxx=-1,miny=-1,maxy=-1;
    GrowArray(): data(nullptr),capacity(1),len(0){}

    ~GrowArray(){
        delete [] data;
    }

    GrowArray(const GrowArray& orig):capacity(orig.capacity),len(orig.len),data(new T[capacity]){
        for (int i = 0; i < len; i++) {
            this->data[i]=orig.data[i];
        }
    }

    GrowArray& operator =(const GrowArray& g){
        GrowArray copy(g);
        this->len=g.len;
        this->capacity=g.capacity;
        this->data=g.data;
        return *this;
    }

    void addStart(T val){
        checkGrow();
        T *old = data;
        data= new T[capacity];
        data[0]=val;
        for (int i = 1; i < len; i++) {
            data[i]=old[i-1];
        }
        delete [] old;
    }

    void insert(int pos, T val){
        checkGrow();
        T *old = data;
        data= new T[capacity];
        for (int i = 0; i < pos; i++) {
            data[i]=old[i];
        }
        data[pos]=val;
        for (int j = pos+1; j < len; j++) {
            data[j]=old[j-1];
        }
        delete [] old;
    }

    void addEnd(const T& val){
        checkGrow();
        data[len-1] = val;
    }

    T removeStart(){
        T temp= data[0];
        for (int i = 0; i < len-1; i++)
            data[i]=data[i+1];
        len--;
        return temp;
    }

    T removeEnd(){
        len--;
        return data[len];
    }

    void remove(int pos){
        T *old = data;
        data= new T[capacity];
        for (int i = 0; i < pos; i++) {
            data[i]=old[i];
        }
        for (int j = pos; j < len-1; j++) {
            data[j]=old[j+1];
        }
        delete [] old;
    }

    int size()const{
        return len;
    }
    T get(int pos){
        return data[pos];
    }
    void set(int pos, T val){
        data[pos]=val;
    }

    friend ostream& operator <<(ostream& s, const GrowArray& orig) {
        for (int i = 0; i < orig.len; i++) {
            s << orig.data[i] << ' ';
        }
        return s;
    }

};

class ConvexHull: public GrowArray<Point>{
private:
    int n, size;
    double minX,maxX,minY,maxY;
    double XperBox, YperBox;
    GrowArray<Point>* l;
public:
    ConvexHull(int n):n(n){
        size = n*n;
        l = new GrowArray<Point>[size];
    }

    ~ConvexHull(){
        delete [] l;
    }

    void read(string s){
        ifstream f(s);
        double x,y;
        int i = 0;
        if (!f)
        {
            cout << "file open error" << endl;
           //return 1;
        }
        while(!f.eof()){
            f >> x >> y;
            if (i==0){
                minX=maxX=x;
                minY=maxY=y;
                i++;
            }
            else{;}

            if(x<minX)
                minX=x;
            if(x>maxX)
                maxX=x;
            if(y<minY)
                minY=y;
            if(y>maxY)
                maxY=y;
        }
        divide(s);
        f.close();
    }

    void divide(string s) {
        XperBox = (n-1) / (maxX - minX);
        YperBox = (n-1) / (maxY - minY);
        int i,j;
        ifstream f(s);
        double x, y;
        if (!f) {
            cout << "file open error" << endl;
            //return 1;
        }
        while (!f.eof()) {
            f >> x >> y;
            i = (int) ((y - minY) * YperBox) ;
            j = (int) ((x - minX) * XperBox);
            l[i*n+j].addEnd(Point(x, y));

            if(l[i*n+j].minx == -1)
            l[i*n+j].minx=x;
            if(l[i*n+j].maxx == -1)
            l[i*n+j].maxx=x;
            if(l[i*n+j].miny == -1)
            l[i*n+j].miny=y;
            if(l[i*n+j].maxy == -1)
            l[i*n+j].maxy=y;

            if(x<l[i*n+j].minx)
                l[i*n+j].minx=x;
            if(x>l[i*n+j].maxx)
                l[i*n+j].maxx=x;
            if(y<l[i*n+j].miny)
                l[i*n+j].miny=y;
            if(y>l[i*n+j].maxy)
                l[i*n+j].maxy=y;

        }
    }

    void printAllListSizes(){
        cout << "Size of list "<< n << " * " << n<< " : \n";
        for(int i=0; i< n; i++) {
            for (int j = 0; j < n; j++) {
                cout << l[i * n + j].size() << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void printMinMax(){
        cout<<"For all pionts : \n";
        cout<< "Min X = " << minX <<'\n';
        cout<< "Max X = " << maxX <<'\n';
        cout<< "Min Y = " << minY <<'\n';
        cout<< "Max Y = " << maxY <<'\n';
        cout<<'\n';
    }
    void print(int i){
        //cout << ' '<<l[i] << '\n';
        cout << "list " << i << ": \n";
        cout<< "Min X = " << l[i].minx <<'\n';
        cout<< "Max X = " << l[i].maxx <<'\n';
        cout<< "Min Y = " << l[i].miny <<'\n';
        cout<< "Max Y = " << l[i].maxy << '\n';
        cout<<'\n';
    }
    void printPerimeterClockWiseOrder(){
        for (int i = 0; i < n; i++) //up line
            print(i);
        for (int j = 2; j < n; j++) //right row
            print(j*n - 1);
        for (int i = 0; i < n; i++) //down line
            print(size - 1 - i);
        for (int j = n-2; j > 0; j--) //left row
            print(j*n);
    }
};

int main(){
    ConvexHull ch(16); // create a 16x16 grid of GrowArray
    //ch.read("/Users/caowanying/CLionProjects/growArray/convexhullpoints.dat");
    ch.read("convexhullpoints.dat");
    ch.printAllListSizes(); // tell us how many are in each list
    ch.printMinMax(); // print minx, maxx, miny, maxy for the entire dataset
    ch.printPerimeterClockWiseOrder(); // p1,p2,p3,p4, p8,p12,p16...
    // for each growarray around the perimeter print xmin, xmax, ymin,ymax
    // this is the minimum, maximum for the x,y in THAT BOX
    /*
  example shown n=4
       -----------------------
       | p1 | p2  | p3  | p4 |
       |    |     |     |    |
       +----+-----+-----+----+
       | p5 | p6  | p7  | p8 |
       |    |     |     |    |
       +----+-----+-----+----+
       | p9 | p10 | p11 | p12|
       |    |     |     |    |
       +----+-----+-----+----+
       | p13| p14 | p15 | p16|
       |    |     |     |    |
       +----+-----+-----+----+
     */
}//  1 2 3 4 8 12 16 15 14 13 12 9 5

