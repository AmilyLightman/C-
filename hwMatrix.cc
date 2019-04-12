#include <iostream>
#include <fstream>
using namespace std;
/*
    @author Wanying Cao 
*/
class IllegalSize{};

class Matrix {
private:
    int rows, cols;
    double* m;
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols),
                                 m(new double[rows*cols]) {}

    Matrix(int rows, int cols, double val) : rows(rows), cols(cols),
                                             m(new double[rows*cols]) {
        for (int i = 0; i < rows*cols; i++)
            m[i] = val;
    }
    ~Matrix() {
        delete [] m;
    }
    Matrix(const Matrix& orig):rows(orig.rows),cols(orig.cols){
        m=new double[rows*cols];
        for (int i = 0; i < rows*cols; ++i) {
            m[i]=orig.m[i];
        }
    }

    Matrix(Matrix&& orig):rows(orig.rows),cols(orig.cols),m(orig.m){
        orig.m=nullptr;
    }

    Matrix operator =(const Matrix& orig) {
        Matrix copy(orig);
        rows= orig.rows;
        cols= orig.cols;
        swap(m,copy.m);
        return *this;
    }
    double operator()(int r, int c) const {
        return m[r*cols + c];
    }

    double& operator()(int r, int c) {
        return m[r*cols + c];
    }

    friend Matrix operator+(const Matrix& a, const Matrix& b){
        if(a.rows!=b.rows||a.cols!=b.cols){
            throw IllegalSize();
        }
        Matrix ans(a.rows,a.cols);
        for (int i = 0; i < a.rows*a.cols; ++i) {
            ans.m[i]=a.m[i]+b.m[i];
        }
        return ans;
    }

    friend Matrix operator *(const Matrix& a, const Matrix& b){
        if(a.cols!=b.rows){
            throw IllegalSize();
        }
        Matrix ans(a.rows,b.cols);
        for (int i = 0; i < a.rows; ++i) {
            for (int j = 0; j < b.cols; ++j) {
                double dot=0;
                for (int k = 0; k < a.cols; ++k) {
                    dot+=a.m[k+i*a.cols]*b.m[k*b.cols+j];
                }
                ans.m[i*ans.cols+j]=dot;
            }
        }
        return ans;
    }

    friend ostream& operator<<(ostream& s,const Matrix& mt){
        for (int i = 0; i < mt.rows; ++i) {
            for (int j = 0; j < mt.cols; ++j) {
                s<< mt.m[i*mt.cols+j]<<'\t';
            }
            s<< '\n';
        }
        return s;
    }

    int getRows(){
        return this->rows;
    }

    static Matrix read(ifstream& f){
        if (!f)
        {
            cout << "file open error" << endl;
            throw IllegalSize();
        }
        int rows,cols;
        f>> rows >> cols;
        Matrix ans(rows,cols);
        for (int i = 0; i < ans.rows*ans.cols; ++i) {
            f>>ans.m[i];
        }
    }
    void solve(Matrix A,Matrix B){

    }
};

int main() {
    Matrix m1(3, 4, 0.0);
    m1(1,2) = 1.5;  // Java: m1.set(1,2,1.5);
    Matrix m2(3, 4, 1.0);
    Matrix m3 = m1 + m2; // matrix addition
    cout << m3 << '\n';

    Matrix m4(4, 2, 0.5);
    m4(0,0) = 5.0;
    m4(0,2) = -1.0;
    Matrix m5 = m1 * m4;
    cout << m5 << '\n';
    ifstream f("hw5.dat");
    Matrix A = Matrix::read(f);
    vector<double> B = read(A.getRows(), f);
    vector<double> x = solve(A, B);
    for (auto v : x) {
        cout << v << '\t';
    }
    cout << '\n';
}

