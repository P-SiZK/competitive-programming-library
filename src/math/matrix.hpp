#ifndef MATH_MATRIX_HPP
#define MATH_MATRIX_HPP

#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <vector>

template<class T>
class Matrix {
private:
	std::vector<std::vector<T>> mat;

public:
	Matrix(std::size_t n) : mat(n, std::vector<T>(n)) {}

	Matrix(std::size_t n, std::size_t m) : mat(n, std::vector<T>(m)) {}

	Matrix(std::initializer_list<std::vector<T>> init) : mat(init) {}

	Matrix(std::vector<std::vector<T>> &mat) : mat(mat) {}

	[[nodiscard]] std::size_t height() const { return mat.size(); }

	[[nodiscard]] std::size_t width() const { return mat[0].size(); }

	std::vector<T> &operator[](std::size_t k) { return mat[k]; }

	std::vector<T> const &operator[](std::size_t k) const { return mat[k]; }

	Matrix &operator+=(Matrix const &b) {
		std::size_t n = height(), m = width();
		assert(n == b.height() && m == b.width());
		for (std::size_t i = 0; i < n; ++i)
			for (std::size_t j = 0; j < m; ++j) (*this)[i][j] += b[i][j];
		return *this;
	}

	Matrix &operator-=(Matrix const &b) {
		std::size_t n = height(), m = width();
		assert(n == b.height() && m == b.width());
		for (std::size_t i = 0; i < n; ++i)
			for (std::size_t j = 0; j < m; ++j) (*this)[i][j] -= b[i][j];
		return *this;
	}

	Matrix &operator*=(Matrix const &b) {
		std::size_t n = height(), m = b.width(), p = width();
		assert(p == b.height());
		std::vector<std::vector<T>> c(n, std::vector<T>(m));
		for (std::size_t i = 0; i < n; ++i)
			for (std::size_t j = 0; j < m; ++j)
				for (std::size_t k = 0; k < p; ++k) c[i][j] += (*this)[i][k] * b[k][j];
		mat.swap(c);
		return *this;
	}

	Matrix operator+(Matrix const &b) const { return Matrix(*this) += b; }

	Matrix operator-(Matrix const &b) const { return Matrix(*this) -= b; }

	Matrix operator*(Matrix const &b) const { return Matrix(*this) *= b; }

	static Matrix identity(std::size_t n) {
		Matrix id(n);
		for (std::size_t i = 0; i < n; ++i) id[i][i] = 1;
		return id;
	}

	[[nodiscard]] Matrix pow(long long n) const {
		Matrix res = Matrix::identity(height()), tmp(*this);
		while (n > 0) {
			if (n & 1) res *= tmp;
			tmp *= tmp;
			n >>= 1;
		}
		return res;
	}
};

#endif // MATH_MATRIX_HPP
