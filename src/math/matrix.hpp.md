---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/matrix.hpp\"\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T>\nclass Matrix {\nprivate:\n\tvector<vector<T>> mat;\n\
    \npublic:\n\tMatrix(size_t n) : mat(n, vector<T>(n, 0)) {}\n\n\tMatrix(size_t\
    \ n, size_t m) : mat(n, vector<T>(m, 0)) {}\n\n\tMatrix(vector<vector<T>> mat)\
    \ : mat(mat) {}\n\n\t[[nodiscard]] size_t height() const { return mat.size();\
    \ }\n\n\t[[nodiscard]] size_t width() const { return mat[0].size(); }\n\n\tvector<T>\
    \ &operator[](size_t k) { return mat[k]; }\n\n\tvector<T> const &operator[](size_t\
    \ k) const { return mat[k]; }\n\n\tMatrix &operator+=(Matrix const &b) {\n\t\t\
    size_t n = height(), m = width();\n\t\tassert(n == b.height() && m == b.width());\n\
    \t\tfor (size_t i = 0; i < n; ++i)\n\t\t\tfor (size_t j = 0; j < m; ++j) (*this)[i][j]\
    \ += b[i][j];\n\t\treturn *this;\n\t}\n\n\tMatrix &operator-=(Matrix const &b)\
    \ {\n\t\tsize_t n = height(), m = width();\n\t\tassert(n == b.height() && m ==\
    \ b.width());\n\t\tfor (size_t i = 0; i < n; ++i)\n\t\t\tfor (size_t j = 0; j\
    \ < m; ++j) (*this)[i][j] -= b[i][j];\n\t\treturn *this;\n\t}\n\n\tMatrix &operator*=(Matrix\
    \ const &b) {\n\t\tsize_t n = height(), m = b.width(), p = width();\n\t\tassert(p\
    \ == b.height());\n\t\tvector<vector<T>> c(n, vector<T>(m));\n\t\tfor (size_t\
    \ i = 0; i < n; ++i)\n\t\t\tfor (size_t j = 0; j < m; ++j)\n\t\t\t\tfor (size_t\
    \ k = 0; k < p; ++k)\n\t\t\t\t\tc[i][j] += (*this)[i][k] * b[k][j];\n\t\tmat.swap(c);\n\
    \t\treturn *this;\n\t}\n\n\tMatrix operator+(Matrix const &b) const { return Matrix(mat)\
    \ += b; }\n\n\tMatrix operator-(Matrix const &b) const { return Matrix(mat) -=\
    \ b; }\n\n\tMatrix operator*(Matrix const &b) const { return Matrix(mat) *= b;\
    \ }\n\n\tstatic Matrix identity(size_t n) {\n\t\tMatrix id(n);\n\t\tfor (size_t\
    \ i = 0; i < n; ++i) id[i][i] = 1;\n\t\treturn id;\n\t}\n\n\tMatrix pow(long long\
    \ n) const {\n\t\tMatrix res = Matrix::identity(height()), tmp(mat);\n\t\twhile\
    \ (n > 0) {\n\t\t\tif (n & 1) res *= tmp;\n\t\t\ttmp *= tmp;\n\t\t\tn >>= 1;\n\
    \t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#include <vector>\n\nusing namespace std;\n\ntemplate<class T>\nclass Matrix\
    \ {\nprivate:\n\tvector<vector<T>> mat;\n\npublic:\n\tMatrix(size_t n) : mat(n,\
    \ vector<T>(n, 0)) {}\n\n\tMatrix(size_t n, size_t m) : mat(n, vector<T>(m, 0))\
    \ {}\n\n\tMatrix(vector<vector<T>> mat) : mat(mat) {}\n\n\t[[nodiscard]] size_t\
    \ height() const { return mat.size(); }\n\n\t[[nodiscard]] size_t width() const\
    \ { return mat[0].size(); }\n\n\tvector<T> &operator[](size_t k) { return mat[k];\
    \ }\n\n\tvector<T> const &operator[](size_t k) const { return mat[k]; }\n\n\t\
    Matrix &operator+=(Matrix const &b) {\n\t\tsize_t n = height(), m = width();\n\
    \t\tassert(n == b.height() && m == b.width());\n\t\tfor (size_t i = 0; i < n;\
    \ ++i)\n\t\t\tfor (size_t j = 0; j < m; ++j) (*this)[i][j] += b[i][j];\n\t\treturn\
    \ *this;\n\t}\n\n\tMatrix &operator-=(Matrix const &b) {\n\t\tsize_t n = height(),\
    \ m = width();\n\t\tassert(n == b.height() && m == b.width());\n\t\tfor (size_t\
    \ i = 0; i < n; ++i)\n\t\t\tfor (size_t j = 0; j < m; ++j) (*this)[i][j] -= b[i][j];\n\
    \t\treturn *this;\n\t}\n\n\tMatrix &operator*=(Matrix const &b) {\n\t\tsize_t\
    \ n = height(), m = b.width(), p = width();\n\t\tassert(p == b.height());\n\t\t\
    vector<vector<T>> c(n, vector<T>(m));\n\t\tfor (size_t i = 0; i < n; ++i)\n\t\t\
    \tfor (size_t j = 0; j < m; ++j)\n\t\t\t\tfor (size_t k = 0; k < p; ++k)\n\t\t\
    \t\t\tc[i][j] += (*this)[i][k] * b[k][j];\n\t\tmat.swap(c);\n\t\treturn *this;\n\
    \t}\n\n\tMatrix operator+(Matrix const &b) const { return Matrix(mat) += b; }\n\
    \n\tMatrix operator-(Matrix const &b) const { return Matrix(mat) -= b; }\n\n\t\
    Matrix operator*(Matrix const &b) const { return Matrix(mat) *= b; }\n\n\tstatic\
    \ Matrix identity(size_t n) {\n\t\tMatrix id(n);\n\t\tfor (size_t i = 0; i < n;\
    \ ++i) id[i][i] = 1;\n\t\treturn id;\n\t}\n\n\tMatrix pow(long long n) const {\n\
    \t\tMatrix res = Matrix::identity(height()), tmp(mat);\n\t\twhile (n > 0) {\n\t\
    \t\tif (n & 1) res *= tmp;\n\t\t\ttmp *= tmp;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn\
    \ res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.hpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/matrix.hpp
layout: document
redirect_from:
- /library/src/math/matrix.hpp
- /library/src/math/matrix.hpp.html
title: src/math/matrix.hpp
---
