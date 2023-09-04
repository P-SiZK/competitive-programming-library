---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/3079.test.cpp
    title: test/math/matrix/3079.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/itp1_7_d.test.cpp
    title: test/math/matrix/itp1_7_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/matrix.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <cstddef>\n#include <vector>\n\ntemplate<class T>\nclass Matrix {\nprivate:\n\
    \tstd::vector<std::vector<T>> mat;\n\npublic:\n\tMatrix(std::size_t n) : mat(n,\
    \ std::vector<T>(n)) {}\n\n\tMatrix(std::size_t n, std::size_t m) : mat(n, std::vector<T>(m))\
    \ {}\n\n\tMatrix(std::initializer_list<std::vector<T>> init) : mat(init) {}\n\n\
    \tMatrix(std::vector<std::vector<T>> &mat) : mat(mat) {}\n\n\t[[nodiscard]] std::size_t\
    \ height() const { return mat.size(); }\n\n\t[[nodiscard]] std::size_t width()\
    \ const { return mat[0].size(); }\n\n\tstd::vector<T> &operator[](std::size_t\
    \ k) { return mat[k]; }\n\n\tstd::vector<T> const &operator[](std::size_t k) const\
    \ { return mat[k]; }\n\n\tMatrix &operator+=(Matrix const &b) {\n\t\tstd::size_t\
    \ n = height(), m = width();\n\t\tassert(n == b.height() && m == b.width());\n\
    \t\tfor (std::size_t i = 0; i < n; ++i)\n\t\t\tfor (std::size_t j = 0; j < m;\
    \ ++j) (*this)[i][j] += b[i][j];\n\t\treturn *this;\n\t}\n\n\tMatrix &operator-=(Matrix\
    \ const &b) {\n\t\tstd::size_t n = height(), m = width();\n\t\tassert(n == b.height()\
    \ && m == b.width());\n\t\tfor (std::size_t i = 0; i < n; ++i)\n\t\t\tfor (std::size_t\
    \ j = 0; j < m; ++j) (*this)[i][j] -= b[i][j];\n\t\treturn *this;\n\t}\n\n\tMatrix\
    \ &operator*=(Matrix const &b) {\n\t\tstd::size_t n = height(), m = b.width(),\
    \ p = width();\n\t\tassert(p == b.height());\n\t\tstd::vector<std::vector<T>>\
    \ c(n, std::vector<T>(m));\n\t\tfor (std::size_t i = 0; i < n; ++i)\n\t\t\tfor\
    \ (std::size_t j = 0; j < m; ++j)\n\t\t\t\tfor (std::size_t k = 0; k < p; ++k)\
    \ c[i][j] += (*this)[i][k] * b[k][j];\n\t\tmat.swap(c);\n\t\treturn *this;\n\t\
    }\n\n\tMatrix operator+(Matrix const &b) const { return Matrix(*this) += b; }\n\
    \n\tMatrix operator-(Matrix const &b) const { return Matrix(*this) -= b; }\n\n\
    \tMatrix operator*(Matrix const &b) const { return Matrix(*this) *= b; }\n\n\t\
    static Matrix identity(std::size_t n) {\n\t\tMatrix id(n);\n\t\tfor (std::size_t\
    \ i = 0; i < n; ++i) id[i][i] = 1;\n\t\treturn id;\n\t}\n\n\t[[nodiscard]] Matrix\
    \ pow(long long n) const {\n\t\tMatrix res = Matrix::identity(height()), tmp(*this);\n\
    \t\twhile (n > 0) {\n\t\t\tif (n & 1) res *= tmp;\n\t\t\ttmp *= tmp;\n\t\t\tn\
    \ >>= 1;\n\t\t}\n\t\treturn res;\n\t}\n};\n\n\n"
  code: "#ifndef MATH_MATRIX_HPP\n#define MATH_MATRIX_HPP\n\n#include <cassert>\n\
    #include <cstddef>\n#include <vector>\n\ntemplate<class T>\nclass Matrix {\nprivate:\n\
    \tstd::vector<std::vector<T>> mat;\n\npublic:\n\tMatrix(std::size_t n) : mat(n,\
    \ std::vector<T>(n)) {}\n\n\tMatrix(std::size_t n, std::size_t m) : mat(n, std::vector<T>(m))\
    \ {}\n\n\tMatrix(std::initializer_list<std::vector<T>> init) : mat(init) {}\n\n\
    \tMatrix(std::vector<std::vector<T>> &mat) : mat(mat) {}\n\n\t[[nodiscard]] std::size_t\
    \ height() const { return mat.size(); }\n\n\t[[nodiscard]] std::size_t width()\
    \ const { return mat[0].size(); }\n\n\tstd::vector<T> &operator[](std::size_t\
    \ k) { return mat[k]; }\n\n\tstd::vector<T> const &operator[](std::size_t k) const\
    \ { return mat[k]; }\n\n\tMatrix &operator+=(Matrix const &b) {\n\t\tstd::size_t\
    \ n = height(), m = width();\n\t\tassert(n == b.height() && m == b.width());\n\
    \t\tfor (std::size_t i = 0; i < n; ++i)\n\t\t\tfor (std::size_t j = 0; j < m;\
    \ ++j) (*this)[i][j] += b[i][j];\n\t\treturn *this;\n\t}\n\n\tMatrix &operator-=(Matrix\
    \ const &b) {\n\t\tstd::size_t n = height(), m = width();\n\t\tassert(n == b.height()\
    \ && m == b.width());\n\t\tfor (std::size_t i = 0; i < n; ++i)\n\t\t\tfor (std::size_t\
    \ j = 0; j < m; ++j) (*this)[i][j] -= b[i][j];\n\t\treturn *this;\n\t}\n\n\tMatrix\
    \ &operator*=(Matrix const &b) {\n\t\tstd::size_t n = height(), m = b.width(),\
    \ p = width();\n\t\tassert(p == b.height());\n\t\tstd::vector<std::vector<T>>\
    \ c(n, std::vector<T>(m));\n\t\tfor (std::size_t i = 0; i < n; ++i)\n\t\t\tfor\
    \ (std::size_t j = 0; j < m; ++j)\n\t\t\t\tfor (std::size_t k = 0; k < p; ++k)\
    \ c[i][j] += (*this)[i][k] * b[k][j];\n\t\tmat.swap(c);\n\t\treturn *this;\n\t\
    }\n\n\tMatrix operator+(Matrix const &b) const { return Matrix(*this) += b; }\n\
    \n\tMatrix operator-(Matrix const &b) const { return Matrix(*this) -= b; }\n\n\
    \tMatrix operator*(Matrix const &b) const { return Matrix(*this) *= b; }\n\n\t\
    static Matrix identity(std::size_t n) {\n\t\tMatrix id(n);\n\t\tfor (std::size_t\
    \ i = 0; i < n; ++i) id[i][i] = 1;\n\t\treturn id;\n\t}\n\n\t[[nodiscard]] Matrix\
    \ pow(long long n) const {\n\t\tMatrix res = Matrix::identity(height()), tmp(*this);\n\
    \t\twhile (n > 0) {\n\t\t\tif (n & 1) res *= tmp;\n\t\t\ttmp *= tmp;\n\t\t\tn\
    \ >>= 1;\n\t\t}\n\t\treturn res;\n\t}\n};\n\n#endif // MATH_MATRIX_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.hpp
  requiredBy: []
  timestamp: '2023-09-04 16:54:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/matrix/3079.test.cpp
  - test/math/matrix/itp1_7_d.test.cpp
documentation_of: src/math/matrix.hpp
layout: document
title: "\u884C\u5217"
---
