#include <iostream>
using namespace std;
/*
 *Author: Wanying Cao (10440141)
 * Cite: Christian Jensen for how to use "[]"
 */
class IllegalSize {
};

class Matrix {
private:
	uint32_t rows,cols;
	double* m;
	Matrix(uint32_t rows, uint32_t cols) : rows(rows), cols(cols), m(new double[rows*cols]) {}
public:
	Matrix(uint32_t rows, uint32_t cols, double v) : Matrix(rows,cols) {
		for (uint32_t i = 0; i < rows*cols; i++) {
			m[i] = v;
		}
	}
	Matrix(const Matrix& orig) : Matrix(orig.rows,orig.cols){
		for (uint32_t i = 0; i < rows*cols; i++) {
			m[i] = orig.m[i];
		}
	}

	// add move constructor for 20% bonus
    Matrix(Matrix&& orig):Matrix(orig.rows,orig.cols){
		m=orig.m;
		orig.m=nullptr;
	}

	Matrix& operator =(const Matrix& orig) {
		Matrix copy(orig);
		rows = orig.rows;
		cols = orig.cols;
		swap(m, copy.m);
		return *this;
	}

	~Matrix() {
		delete [] m;
	}

	//C++ order in memory for static-sized arrays
	// int x[5][2]; // x[0][0] x[0][1] x[1][0] x[1][1] ....

	double operator()(uint32_t r, uint32_t c) const {
		return m[r * cols + c ];
	}
	double& operator()(uint32_t r, uint32_t c) {
		return m[r * cols + c ];
	}
	const double* operator[](uint32_t n) const {
		return &m[n*this->cols];
	}
	double* operator[](uint32_t n) {
		return &m[n*this->cols];
	}

	friend  Matrix operator +(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			throw IllegalSize();
		Matrix ans(a.rows, a.cols);
		for (uint32_t i = 0; i < a.rows*a.cols; i++) {
			ans.m[i] = a.m[i]+b.m[i];
		}
		return ans;
	}

	friend Matrix operator *(const Matrix& a, const Matrix& b) {
		if (a.cols != b.rows)
			throw IllegalSize();
		Matrix ans(a.rows, b.cols, 0.0);
		for (uint32_t i = 0; i < a.rows*b.cols; i++) {
			for (int j = 0; j < a.cols; j++) {
				ans.m[i] += a.m[a.cols*(i/b.cols)+j]*b.m[i/b.rows+j*b.cols];
			}
		}
		return ans;
	}

	friend ostream& operator<<(ostream& s, const Matrix& m) {
		for (uint32_t i = 0, c = 0; i < m.rows; i++) {
			for (uint32_t j = 0; j < m.cols; j++, c++) {
				s << m.m[c] << '\t';
			}
			s << '\n';
		}
		return s;
	}
};


int main() {
	try {
		Matrix a(4, 3, 0.0);
		cout << a(2,2)<< '\n';
		a(2,2) = 1.5;
		a[2][1] = 2.5;
		Matrix b(4, 3, 0.0);
		b(1,2) = 1.2;
		b(0,0) = -1.1;
		Matrix c = a + b;
		cout << c << '\n';

		Matrix d(3,2,1.0);   // 4x3   x 3x2 = 4x2 matrix
		cout<< "Matrix e = a * d;\n";
		cout<<"a\n"<<a<<'\n';
		cout<<"d\n"<<d<<'\n';
		Matrix e = a * d;
		cout<< e << '\n';
		b = d;
		cout << d << '\n';
		d = e + d;
	}
	catch(IllegalSize e) {
		cout << "Illegal size -- throw this one back!\n";
	}
}
