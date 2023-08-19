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
  bundledCode: "#line 1 \"src/math/mod_int.cpp\"\n#include <iostream>\n\nusing namespace\
    \ std;\n\ntemplate<class T, T MOD = 1000000007>\nstruct ModInt {\n\tT x;\n\n\t\
    ModInt() : x(0) {}\n\n\tModInt(long long y) {\n\t\tx = y % MOD;\n\t\tif (x < 0)\
    \ x += MOD;\n\t}\n\n\tModInt &operator+=(const ModInt &a) {\n\t\tif ((x += a.x)\
    \ >= MOD) x -= MOD;\n\t\treturn *this;\n\t}\n\n\tModInt &operator-=(const ModInt\
    \ &a) {\n\t\tif ((x += MOD - a.x) >= MOD) x -= MOD;\n\t\treturn *this;\n\t}\n\n\
    \tModInt &operator*=(const ModInt &a) {\n\t\tx = 1LL * x * a.x % MOD;\n\t\treturn\
    \ *this;\n\t}\n\n\tModInt &operator/=(const ModInt &a) {\n\t\t*this *= a.inv();\n\
    \t\treturn *this;\n\t}\n\n\tModInt operator+(const ModInt &a) const { return ModInt(x)\
    \ += a; }\n\n\tModInt operator-(const ModInt &a) const { return ModInt(x) -= a;\
    \ }\n\n\tModInt operator*(const ModInt &a) const { return ModInt(x) *= a; }\n\n\
    \tModInt operator/(const ModInt &a) const { return ModInt(x) /= a; }\n\n\tModInt\
    \ operator-() const { return ModInt(-x); }\n\n\tbool operator==(const ModInt a)\
    \ const { return x == a.x; }\n\n\tbool operator!=(const ModInt a) const { return\
    \ x != a.x; }\n\n\tbool operator<(const ModInt a) const { return x < a.x; }\n\n\
    \tfriend ostream &operator<<(ostream &os, const ModInt &a) {\n\t\treturn os <<\
    \ a.x;\n\t}\n\n\tfriend istream &operator>>(istream &is, ModInt &a) {\n\t\tT t;\n\
    \t\tis >> t;\n\t\ta = ModInt(t);\n\t\treturn is;\n\t}\n\n\tModInt inv() const\
    \ {\n\t\tT a = x, b = MOD, u = 1, v = 0;\n\t\twhile (b > 0) {\n\t\t\tT t = a /\
    \ b;\n\t\t\ta -= t * b, u -= t * v;\n\t\t\tswap(a, b);\n\t\t\tswap(u, v);\n\t\t\
    }\n\t\treturn ModInt(u);\n\t}\n\n\tModInt pow(long long n) const {\n\t\tModInt\
    \ res(1), tmp(x);\n\t\twhile (n > 0) {\n\t\t\tif (n & 1) res *= tmp;\n\t\t\ttmp\
    \ *= tmp;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tstatic ModInt comb(long\
    \ long n, long long k) {\n\t\tModInt num(1), den(1);\n\t\tfor (int i = 0; i <\
    \ k; ++i) {\n\t\t\tnum *= ModInt(n - i);\n\t\t\tden *= ModInt(i + 1);\n\t\t}\n\
    \t\treturn num / den;\n\t}\n};\n"
  code: "#include <iostream>\n\nusing namespace std;\n\ntemplate<class T, T MOD =\
    \ 1000000007>\nstruct ModInt {\n\tT x;\n\n\tModInt() : x(0) {}\n\n\tModInt(long\
    \ long y) {\n\t\tx = y % MOD;\n\t\tif (x < 0) x += MOD;\n\t}\n\n\tModInt &operator+=(const\
    \ ModInt &a) {\n\t\tif ((x += a.x) >= MOD) x -= MOD;\n\t\treturn *this;\n\t}\n\
    \n\tModInt &operator-=(const ModInt &a) {\n\t\tif ((x += MOD - a.x) >= MOD) x\
    \ -= MOD;\n\t\treturn *this;\n\t}\n\n\tModInt &operator*=(const ModInt &a) {\n\
    \t\tx = 1LL * x * a.x % MOD;\n\t\treturn *this;\n\t}\n\n\tModInt &operator/=(const\
    \ ModInt &a) {\n\t\t*this *= a.inv();\n\t\treturn *this;\n\t}\n\n\tModInt operator+(const\
    \ ModInt &a) const { return ModInt(x) += a; }\n\n\tModInt operator-(const ModInt\
    \ &a) const { return ModInt(x) -= a; }\n\n\tModInt operator*(const ModInt &a)\
    \ const { return ModInt(x) *= a; }\n\n\tModInt operator/(const ModInt &a) const\
    \ { return ModInt(x) /= a; }\n\n\tModInt operator-() const { return ModInt(-x);\
    \ }\n\n\tbool operator==(const ModInt a) const { return x == a.x; }\n\n\tbool\
    \ operator!=(const ModInt a) const { return x != a.x; }\n\n\tbool operator<(const\
    \ ModInt a) const { return x < a.x; }\n\n\tfriend ostream &operator<<(ostream\
    \ &os, const ModInt &a) {\n\t\treturn os << a.x;\n\t}\n\n\tfriend istream &operator>>(istream\
    \ &is, ModInt &a) {\n\t\tT t;\n\t\tis >> t;\n\t\ta = ModInt(t);\n\t\treturn is;\n\
    \t}\n\n\tModInt inv() const {\n\t\tT a = x, b = MOD, u = 1, v = 0;\n\t\twhile\
    \ (b > 0) {\n\t\t\tT t = a / b;\n\t\t\ta -= t * b, u -= t * v;\n\t\t\tswap(a,\
    \ b);\n\t\t\tswap(u, v);\n\t\t}\n\t\treturn ModInt(u);\n\t}\n\n\tModInt pow(long\
    \ long n) const {\n\t\tModInt res(1), tmp(x);\n\t\twhile (n > 0) {\n\t\t\tif (n\
    \ & 1) res *= tmp;\n\t\t\ttmp *= tmp;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn res;\n\
    \t}\n\n\tstatic ModInt comb(long long n, long long k) {\n\t\tModInt num(1), den(1);\n\
    \t\tfor (int i = 0; i < k; ++i) {\n\t\t\tnum *= ModInt(n - i);\n\t\t\tden *= ModInt(i\
    \ + 1);\n\t\t}\n\t\treturn num / den;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod_int.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/mod_int.cpp
layout: document
redirect_from:
- /library/src/math/mod_int.cpp
- /library/src/math/mod_int.cpp.html
title: src/math/mod_int.cpp
---
