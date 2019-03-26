#include <iostream>
#include <stdint.h>
using namespace std;

template<typename T>  // check it
class Complex{
private:
    T r,i;
};

class IllegalSize{};

class Matrix{
private:
    uint32_t rows, cols;
    double** m;    // complex and slow
    Matrix ( uint32_t rows,uint32_t cols): rows(rows), cols(cols),
                                 m(new double *[rows]){
        for(uint32_t i=0;i<rows;i++)
        {
            m[i] = new double[cols];
        }
    }

public:
    Matrix(uint32_t rows, uint32_t cols, double v): Matrix(rows,cols){
        for(uint32_t i=0;i<rows;i++)
        {
            for(uint32_t j=0;j<cols;j++)
            {
                m[i][j]=v;
            }
            //for(uint32_t i=0;i<rows;i++) {
              //  m[i] = new double[cols];
            //for(uint32_t j=0; j<cols;j++) { m[i][j]=v; }}
        }
    }

    //Matrix (Matrix&& orig): rows(orig.rows), cols(orig.cols),m(orig.m){
    //    orig.m =nullptr;}

    Matrix (const Matrix& orig):rows(orig.rows), cols(orig.cols), m(new double *[rows]) {
        for (uint32_t i = 0; i < rows; i++) {
            double *temp = m[i] = new double[cols];
            for (uint32_t j = 0; j < cols; j++) {
                m[i][j] = orig.m[i][j];
            }
        }
    }

    Matrix& operator =(const Matrix& orig){  // void operator =(const Matrix& orig)
        Matrix copy(orig);// Matrix copy = orig;
        rows = orig.rows;
        cols = orig.cols;
        swap(m, copy.m);
        return *this;
    }

    ~Matrix(){
        for (int i = 0; i < rows; i++) {
            delete[] m[i];
        }
    }

    double& operator()(uint32_t r, uint32_t c){
        //if(r>=rows || c >cols)
         //   throw BadIndex(_FILE_,_LINE_);
        return m[r][c];
    }
    double operator()(uint32_t r, uint32_t c) const{
        return m[r][c];
    }
    double* operator[](uint32_t r){
        return m[r];
    }
    const double* operator[](uint32_t r) const {
        return m[r];
    }


    friend Matrix operator + (const Matrix& a, const Matrix& b) {
        if (a.rows != b.rows || a.cols!=b.cols)
        {
            throw IllegalSize();
        }
        Matrix ans(a.rows,a.cols, 0.0);
        for(int i = 0; i < a.rows; i++)
        {
            for(int j = 0; j < a.cols; j++){
                ans.m[i][j] = a.m[i][j] +b.m[i][j];
            }
        }
        return ans;
    }
    friend Matrix operator * (const Matrix& a, const Matrix& b) {
        if (a.cols!=b.rows)
        {
            throw IllegalSize();
        }
        Matrix ans(a.rows,b.cols, 0.0);
        for(uint32_t i = 0; i < a.rows; i++) {
            for(uint32_t j = 0; j < b.cols; j++){
                double dot = 0;
                for(uint32_t k = 0; k < a.cols; k++){
                    dot += a(i,k)* b(k,j); //ans.m[i][j] = a.m[i][j] * b.m[j][i];
                    ans(i,j) = dot;
                }
            }
        }
        return ans;
    }

    friend ostream& operator << (ostream& s, Matrix f) {
        for(int i=0;i<f.rows;i++){
            for (int j = 0; j < f.cols; j++) {
                s << f(i,j)<<'\t';
            }
            cout<<'\n';
        }
        return s;
    }
};

int main() {
    Matrix a(4,3, 0.0);
    cout << a(2,2);
    a(2,2) = 1.5;
    a[2][1] = 2.5;  // not great
    Matrix b(4,3, 0.0);
    b(1,2) = 1.2;
    b(0,0) = -1.1;
    Matrix c = a+b;
    cout << c << '\n';

    Matrix d(3,2,1.0);
    Matrix e = a * d;
    cout << e << '\n';

    b=d;
    cout << b << '\n';
    return 0;
}