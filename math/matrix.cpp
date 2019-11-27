#include <iostream>
#include <vector>

using namespace std;

//BEGIN
template <typename T>
class Matrix {
public:
	vector<vector<T> > A;

	Matrix() {}
	Matrix(size_t n) :A(n, vector<T>(n, 0)) {}
	Matrix(size_t n, size_t m) :A(n, vector<T>(m, 0)) {}
	Matrix(vector<vector<T> > A) :A(A) {}

	size_t height() const { return A.size(); }
	size_t width() const { return A[0].size(); }

	vector<T>& operator[](size_t k) { return A[k]; }
	const vector<T>& operator[](size_t k) const { return A[k]; }

	Matrix& operator+=(const Matrix& B) {
		size_t n = height(), m = width();
		assert(n == B.height() && m == B.width());
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < m; ++j)
				(*this)[i][j] += B[i][j];
		return *this;
	}
	Matrix& operator-=(const Matrix& B) {
		size_t n = height(), m = width();
		assert(n == B.height() && m == B.width());
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < m; ++j)
				(*this)[i][j] -= B[i][j];
		return *this;
	}
	Matrix& operator*=(const Matrix& B) {
		size_t n = height(), m = B.width(), p = width();
		assert(p == B.height());
		vector<vector<T> > C(n, vector<T>(m));
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < m; ++j)
				for (size_t k = 0; k < p; ++k)
					C[i][j] += (*this)[i][k] * B[k][j];
		A.swap(C);
		return *this;
	}

	Matrix operator+(const Matrix& B) const { return Matrix(A) += B; }
	Matrix operator-(const Matrix& B) const { return Matrix(A) -= B; }
	Matrix operator*(const Matrix& B) const { return Matrix(A) *= B; }

	static Matrix Identity(size_t n) {
		Matrix I(n);
		for (size_t i = 0; i < n; ++i) I[i][i] = 1;
		return I;
	}

	Matrix pow(long long n) const {
		Matrix res = Matrix::Identity(height()), tmp(A);
		while (n > 0) {
			if (n & 1) res *= tmp;
			tmp *= tmp;
			n >>= 1;
		}
		return res;
	}
};
//END

int main() {
	

	return 0;
}
