#include <vector>

using namespace std;

template<class T>
class Matrix {
private:
	vector<vector<T>> mat;

public:
	Matrix(size_t n) : mat(n, vector<T>(n, 0)) {}

	Matrix(size_t n, size_t m) : mat(n, vector<T>(m, 0)) {}

	Matrix(vector<vector<T>> mat) : mat(mat) {}

	[[nodiscard]] size_t height() const { return mat.size(); }

	[[nodiscard]] size_t width() const { return mat[0].size(); }

	vector<T> &operator[](size_t k) { return mat[k]; }

	vector<T> const &operator[](size_t k) const { return mat[k]; }

	Matrix &operator+=(Matrix const &b) {
		size_t n = height(), m = width();
		assert(n == b.height() && m == b.width());
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < m; ++j) (*this)[i][j] += b[i][j];
		return *this;
	}

	Matrix &operator-=(Matrix const &b) {
		size_t n = height(), m = width();
		assert(n == b.height() && m == b.width());
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < m; ++j) (*this)[i][j] -= b[i][j];
		return *this;
	}

	Matrix &operator*=(Matrix const &b) {
		size_t n = height(), m = b.width(), p = width();
		assert(p == b.height());
		vector<vector<T>> c(n, vector<T>(m));
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < m; ++j)
				for (size_t k = 0; k < p; ++k)
					c[i][j] += (*this)[i][k] * b[k][j];
		mat.swap(c);
		return *this;
	}

	Matrix operator+(Matrix const &b) const { return Matrix(mat) += b; }

	Matrix operator-(Matrix const &b) const { return Matrix(mat) -= b; }

	Matrix operator*(Matrix const &b) const { return Matrix(mat) *= b; }

	static Matrix identity(size_t n) {
		Matrix id(n);
		for (size_t i = 0; i < n; ++i) id[i][i] = 1;
		return id;
	}

	Matrix pow(long long n) const {
		Matrix res = Matrix::identity(height()), tmp(mat);
		while (n > 0) {
			if (n & 1) res *= tmp;
			tmp *= tmp;
			n >>= 1;
		}
		return res;
	}
};
