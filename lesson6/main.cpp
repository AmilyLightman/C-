#include <iostream>
using namespace std;
/*
   Author: Wanying Cao
*/
#include<cmath>
#include<iostream>
using namespace std;
int main(){
    cout << -3.0/7*(log(3/7)/log(2))-4.0/7*(log(4/7)/log(2));
}

/*
#include <iostream>
#include <fstream>
#include<vector>
#include <cstring>
using namespace std;

class Point{
private:double x,y;
public:
    Point():x(),y(){}
    Point(double x, double y) : x(x), y(y) {}
    friend ostream& operator <<(ostream& s, const Point& p) {
        return s << p.x << p.y<< ' ';
    }
};

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
        if (len < capacity){
            len++;
            return;
        }
        else{
            T *old=data;
            capacity *= 2;
            data= new T[capacity];
            for (int i = 0; i < len; i++)
                data[i] = old[i];
            len++;
            delete [] old;
        }
    }

public:
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

    void addEnd(T val){
        checkGrow();
        data[len-1] = val;
    }

    void removeStart(){
        for (int i = 0; i < len-1; i++)
            data[i]=data[i+1];
        len--;
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


class ConvexHull :public GrowArray<Point>
{
private:
    int n, nsqr;
    double minx, maxx, miny, maxy;
    GrowArray* L;
public:
    ConvexHull(int n) :n(n)
    {
        nsqr = n*n;
        L = new GrowArray[nsqr];
        minx = maxx = miny = maxy = 0;
    }
    ~ConvexHull()
    {
        delete[] L;
    }
    void read(string fn)
    {
        ifstream f(fn);
        string str;
        double x, y;
        if (!f.eof())
        {
            f >> str; x = stod(str);
            f >> str; y = stod(str);
            this->addEnd(Point(x, y));
            minx = x;
            maxx = x;
            miny = y;
            maxy = y;
        }
        while (!f.eof())
        {
            f >> str; x = stod(str);
            f >> str; y = stod(str);
            addEnd(Point(x, y));
            minx = x < minx ? x : minx;
            maxx = x > maxx ? x : maxx;
            miny = y < miny ? y : miny;
            maxy = y > maxy ? y : maxy;
        }
        f.close();
        fillGrids();
    }
    void printAllListSizes()
    {
        cout << "AllListSize = " << size() << endl;
        for (int i = 0; i < nsqr; i++)
        {
            cout << "List_" << i << "_Size = " << L[i].size() << endl;
        }
    }
    void printMinMax()
    {
        cout << "minx = " << minx << endl;
        cout << "maxx = " << maxx << endl;
        cout << "miny = " << miny << endl;
        cout << "maxy = " << maxy << endl;
    }
    void fillGrids()
    {
        double min, max;
        min = minx < miny ? minx : miny;
        max = maxx > maxy ? maxx : maxy;
        double ival = (max - min) / n;
        cout << max << endl;
        cout << min << endl;
        cout << ival << endl;
        for (int i = 0; i < size(); i++)
        {
            double di, dj;
            di = (max - data[i].x) / ival;
            dj = (data[i].y - min) / ival;
            if (di - (int)di == 0 || dj - (int)dj == 0)
                continue;
            L[(int)di*n + (int)dj].addEnd(data[i]);
        }
    }
    void printPerimeterClockWiseOrder()
    {
        for (int i = 0; i < n; i++) //up line
            printList(i);
        for (int j = 2; j < n; j++) //right row
            printList(j*n - 1);
        for (int i = 0; i < n; i++) //down line
            printList(nsqr - 1 - i);
        for (int j = n-1; j > 0; j--) //left row
            printList(j*n);
    }
    void printList(int i)
    {
        cout << "All points in List_" << i << ":" << endl;
        cout << "\t" << L[i] << endl;
    }
};

int main()
{
    ConvexHull ch(16);
    ch.read("convexhullpoints.dat");
    ch.printAllListSizes();
    ch.printMinMax();
    ch.printPerimeterClockWiseOrder();

    system("pause");
    return 0;
}



#include<vector>
#include<list>

int main() {
    vector<int> a;
    for (int i = 0; i < 10; ++i) {
        a.push_back(i);
    }
    for (vector<int>::const_iterator i = a.begin(); i!= a.end; i++) {
        cout << *i;
    }
    for (vector<int>::iterator i = a.begin(); i!= a.end; i++) {
         *i *= 2;
    }
    for (vector<int>::reverse_iterator i = a.rbegin(); i!= a.rend; i++) {
        cout << *i;
    }
}
 */
