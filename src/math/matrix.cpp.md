---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/matrix.cpp\"\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T>\nclass Matrix {\npublic:\n\tvector<vector<T>> A;\n\
    \n\tMatrix(size_t n) : A(n, vector<T>(n, 0)) {}\n\n\tMatrix(size_t n, size_t m)\
    \ : A(n, vector<T>(m, 0)) {}\n\n\tMatrix(vector<vector<T>> A) : A(A) {}\n\n\t\
    [[nodiscard]] size_t height() const { return A.size(); }\n\n\t[[nodiscard]] size_t\
    \ width() const { return A[0].size(); }\n\n\tvector<T> &operator[](size_t k) {\
    \ return A[k]; }\n\n\tconst vector<T> &operator[](size_t k) const { return A[k];\
    \ }\n\n\tMatrix &operator+=(const Matrix &B) {\n\t\tsize_t n = height(), m = width();\n\
    \t\tassert(n == B.height() && m == B.width());\n\t\tfor (size_t i = 0; i < n;\
    \ ++i)\n\t\t\tfor (size_t j = 0; j < m; ++j) (*this)[i][j] += B[i][j];\n\t\treturn\
    \ *this;\n\t}\n\n\tMatrix &operator-=(const Matrix &B) {\n\t\tsize_t n = height(),\
    \ m = width();\n\t\tassert(n == B.height() && m == B.width());\n\t\tfor (size_t\
    \ i = 0; i < n; ++i)\n\t\t\tfor (size_t j = 0; j < m; ++j) (*this)[i][j] -= B[i][j];\n\
    \t\treturn *this;\n\t}\n\n\tMatrix &operator*=(const Matrix &B) {\n\t\tsize_t\
    \ n = height(), m = B.width(), p = width();\n\t\tassert(p == B.height());\n\t\t\
    vector<vector<T>> C(n, vector<T>(m));\n\t\tfor (size_t i = 0; i < n; ++i)\n\t\t\
    \tfor (size_t j = 0; j < m; ++j)\n\t\t\t\tfor (size_t k = 0; k < p; ++k)\n\t\t\
    \t\t\tC[i][j] += (*this)[i][k] * B[k][j];\n\t\tA.swap(C);\n\t\treturn *this;\n\
    \t}\n\n\tMatrix operator+(const Matrix &B) const { return Matrix(A) += B; }\n\n\
    \tMatrix operator-(const Matrix &B) const { return Matrix(A) -= B; }\n\n\tMatrix\
    \ operator*(const Matrix &B) const { return Matrix(A) *= B; }\n\n\tstatic Matrix\
    \ Identity(size_t n) {\n\t\tMatrix I(n);\n\t\tfor (size_t i = 0; i < n; ++i) I[i][i]\
    \ = 1;\n\t\treturn I;\n\t}\n\n\tMatrix pow(long long n) const {\n\t\tMatrix res\
    \ = Matrix::Identity(height()), tmp(A);\n\t\twhile (n > 0) {\n\t\t\tif (n & 1)\
    \ res *= tmp;\n\t\t\ttmp *= tmp;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn res;\n\t}\n\
    };\n"
  code: "#include <vector>\n\nusing namespace std;\n\ntemplate<class T>\nclass Matrix\
    \ {\npublic:\n\tvector<vector<T>> A;\n\n\tMatrix(size_t n) : A(n, vector<T>(n,\
    \ 0)) {}\n\n\tMatrix(size_t n, size_t m) : A(n, vector<T>(m, 0)) {}\n\n\tMatrix(vector<vector<T>>\
    \ A) : A(A) {}\n\n\t[[nodiscard]] size_t height() const { return A.size(); }\n\
    \n\t[[nodiscard]] size_t width() const { return A[0].size(); }\n\n\tvector<T>\
    \ &operator[](size_t k) { return A[k]; }\n\n\tconst vector<T> &operator[](size_t\
    \ k) const { return A[k]; }\n\n\tMatrix &operator+=(const Matrix &B) {\n\t\tsize_t\
    \ n = height(), m = width();\n\t\tassert(n == B.height() && m == B.width());\n\
    \t\tfor (size_t i = 0; i < n; ++i)\n\t\t\tfor (size_t j = 0; j < m; ++j) (*this)[i][j]\
    \ += B[i][j];\n\t\treturn *this;\n\t}\n\n\tMatrix &operator-=(const Matrix &B)\
    \ {\n\t\tsize_t n = height(), m = width();\n\t\tassert(n == B.height() && m ==\
    \ B.width());\n\t\tfor (size_t i = 0; i < n; ++i)\n\t\t\tfor (size_t j = 0; j\
    \ < m; ++j) (*this)[i][j] -= B[i][j];\n\t\treturn *this;\n\t}\n\n\tMatrix &operator*=(const\
    \ Matrix &B) {\n\t\tsize_t n = height(), m = B.width(), p = width();\n\t\tassert(p\
    \ == B.height());\n\t\tvector<vector<T>> C(n, vector<T>(m));\n\t\tfor (size_t\
    \ i = 0; i < n; ++i)\n\t\t\tfor (size_t j = 0; j < m; ++j)\n\t\t\t\tfor (size_t\
    \ k = 0; k < p; ++k)\n\t\t\t\t\tC[i][j] += (*this)[i][k] * B[k][j];\n\t\tA.swap(C);\n\
    \t\treturn *this;\n\t}\n\n\tMatrix operator+(const Matrix &B) const { return Matrix(A)\
    \ += B; }\n\n\tMatrix operator-(const Matrix &B) const { return Matrix(A) -= B;\
    \ }\n\n\tMatrix operator*(const Matrix &B) const { return Matrix(A) *= B; }\n\n\
    \tstatic Matrix Identity(size_t n) {\n\t\tMatrix I(n);\n\t\tfor (size_t i = 0;\
    \ i < n; ++i) I[i][i] = 1;\n\t\treturn I;\n\t}\n\n\tMatrix pow(long long n) const\
    \ {\n\t\tMatrix res = Matrix::Identity(height()), tmp(A);\n\t\twhile (n > 0) {\n\
    \t\t\tif (n & 1) res *= tmp;\n\t\t\ttmp *= tmp;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn\
    \ res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/matrix.cpp
layout: document
redirect_from:
- /library/src/math/matrix.cpp
- /library/src/math/matrix.cpp.html
title: src/math/matrix.cpp
---
