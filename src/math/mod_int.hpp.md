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
  bundledCode: "#line 1 \"src/math/mod_int.hpp\"\n\n\n\n#include <iostream>\n\ntemplate<class\
    \ T, T MOD = 1000000007>\nclass ModInt {\nprivate:\n\tT x;\n\npublic:\n\tModInt()\
    \ : x(0) {}\n\n\tModInt(long long y) : x(y % MOD) {\n\t\tif (x < 0) x += MOD;\n\
    \t}\n\n\tModInt &operator+=(ModInt const &a) {\n\t\tx += a.x;\n\t\tif (x >= MOD)\
    \ x -= MOD;\n\t\treturn *this;\n\t}\n\n\tModInt &operator-=(ModInt const &a) {\n\
    \t\tx += MOD - a.x;\n\t\tif (x >= MOD) x -= MOD;\n\t\treturn *this;\n\t}\n\n\t\
    ModInt &operator*=(ModInt const &a) {\n\t\tx = 1LL * x * a.x % MOD;\n\t\treturn\
    \ *this;\n\t}\n\n\tModInt &operator/=(ModInt const &a) {\n\t\t*this *= a.inv();\n\
    \t\treturn *this;\n\t}\n\n\tModInt operator+(ModInt const &a) const { return ModInt(x)\
    \ += a; }\n\n\tModInt operator-(ModInt const &a) const { return ModInt(x) -= a;\
    \ }\n\n\tModInt operator*(ModInt const &a) const { return ModInt(x) *= a; }\n\n\
    \tModInt operator/(ModInt const &a) const { return ModInt(x) /= a; }\n\n\tModInt\
    \ operator-() const { return ModInt(-x); }\n\n\tbool operator==(ModInt const &a)\
    \ const { return x == a.x; }\n\n\tbool operator!=(ModInt const &a) const { return\
    \ x != a.x; }\n\n\tbool operator<(ModInt const &a) const { return x < a.x; }\n\
    \n\tfriend std::ostream &operator<<(std::ostream &os, ModInt const &a) {\n\t\t\
    return os << a.x;\n\t}\n\n\tfriend std::istream &operator>>(std::istream &is,\
    \ ModInt &a) {\n\t\tT t;\n\t\tis >> t;\n\t\ta = ModInt(t);\n\t\treturn is;\n\t\
    }\n\n\tModInt inv() const {\n\t\tT a = x, b = MOD, u = 1, v = 0;\n\t\twhile (b\
    \ > 0) {\n\t\t\tT t = a / b;\n\t\t\ta -= t * b, u -= t * v;\n\t\t\tstd::swap(a,\
    \ b);\n\t\t\tstd::swap(u, v);\n\t\t}\n\t\treturn ModInt(u);\n\t}\n\n\tModInt pow(long\
    \ long n) const {\n\t\tModInt res(1), tmp(x);\n\t\twhile (n > 0) {\n\t\t\tif (n\
    \ & 1) res *= tmp;\n\t\t\ttmp *= tmp;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn res;\n\
    \t}\n\n\tstatic ModInt comb(long long n, long long k) {\n\t\tModInt num(1), den(1);\n\
    \t\tfor (int i = 0; i < k; ++i) {\n\t\t\tnum *= ModInt(n - i);\n\t\t\tden *= ModInt(i\
    \ + 1);\n\t\t}\n\t\treturn num / den;\n\t}\n};\n\n\n"
  code: "#ifndef MATH_MOD_INT_HPP\n#define MATH_MOD_INT_HPP\n\n#include <iostream>\n\
    \ntemplate<class T, T MOD = 1000000007>\nclass ModInt {\nprivate:\n\tT x;\n\n\
    public:\n\tModInt() : x(0) {}\n\n\tModInt(long long y) : x(y % MOD) {\n\t\tif\
    \ (x < 0) x += MOD;\n\t}\n\n\tModInt &operator+=(ModInt const &a) {\n\t\tx +=\
    \ a.x;\n\t\tif (x >= MOD) x -= MOD;\n\t\treturn *this;\n\t}\n\n\tModInt &operator-=(ModInt\
    \ const &a) {\n\t\tx += MOD - a.x;\n\t\tif (x >= MOD) x -= MOD;\n\t\treturn *this;\n\
    \t}\n\n\tModInt &operator*=(ModInt const &a) {\n\t\tx = 1LL * x * a.x % MOD;\n\
    \t\treturn *this;\n\t}\n\n\tModInt &operator/=(ModInt const &a) {\n\t\t*this *=\
    \ a.inv();\n\t\treturn *this;\n\t}\n\n\tModInt operator+(ModInt const &a) const\
    \ { return ModInt(x) += a; }\n\n\tModInt operator-(ModInt const &a) const { return\
    \ ModInt(x) -= a; }\n\n\tModInt operator*(ModInt const &a) const { return ModInt(x)\
    \ *= a; }\n\n\tModInt operator/(ModInt const &a) const { return ModInt(x) /= a;\
    \ }\n\n\tModInt operator-() const { return ModInt(-x); }\n\n\tbool operator==(ModInt\
    \ const &a) const { return x == a.x; }\n\n\tbool operator!=(ModInt const &a) const\
    \ { return x != a.x; }\n\n\tbool operator<(ModInt const &a) const { return x <\
    \ a.x; }\n\n\tfriend std::ostream &operator<<(std::ostream &os, ModInt const &a)\
    \ {\n\t\treturn os << a.x;\n\t}\n\n\tfriend std::istream &operator>>(std::istream\
    \ &is, ModInt &a) {\n\t\tT t;\n\t\tis >> t;\n\t\ta = ModInt(t);\n\t\treturn is;\n\
    \t}\n\n\tModInt inv() const {\n\t\tT a = x, b = MOD, u = 1, v = 0;\n\t\twhile\
    \ (b > 0) {\n\t\t\tT t = a / b;\n\t\t\ta -= t * b, u -= t * v;\n\t\t\tstd::swap(a,\
    \ b);\n\t\t\tstd::swap(u, v);\n\t\t}\n\t\treturn ModInt(u);\n\t}\n\n\tModInt pow(long\
    \ long n) const {\n\t\tModInt res(1), tmp(x);\n\t\twhile (n > 0) {\n\t\t\tif (n\
    \ & 1) res *= tmp;\n\t\t\ttmp *= tmp;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn res;\n\
    \t}\n\n\tstatic ModInt comb(long long n, long long k) {\n\t\tModInt num(1), den(1);\n\
    \t\tfor (int i = 0; i < k; ++i) {\n\t\t\tnum *= ModInt(n - i);\n\t\t\tden *= ModInt(i\
    \ + 1);\n\t\t}\n\t\treturn num / den;\n\t}\n};\n\n#endif // MATH_MOD_INT_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod_int.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/mod_int.hpp
layout: document
redirect_from:
- /library/src/math/mod_int.hpp
- /library/src/math/mod_int.hpp.html
title: src/math/mod_int.hpp
---
