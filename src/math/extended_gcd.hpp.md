---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/extended_gcd/ntl_1_e.test.cpp
    title: test/math/extended_gcd/ntl_1_e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/extended_gcd.hpp\"\n\n\n\ntemplate<class T>\nT\
    \ extended_gcd(T a, T b, T &x, T &y) { // ax+by=gcd(a,b)\n\tif (b == 0) {\n\t\t\
    x = 1;\n\t\ty = 0;\n\t\treturn a;\n\t}\n\tT d = extended_gcd(b, a % b, y, x);\n\
    \ty -= a / b * x;\n\treturn d;\n}\n\ntemplate<class T>\nT modinv(T a, T mod) {\
    \ // a,mod\u306F\u4E92\u3044\u306B\u7D20\n\tT x, y;\n\textended_gcd(a, mod, x,\
    \ y);\n\treturn (x % mod + mod) % mod;\n}\n\n\n"
  code: "#ifndef MATH_EXTENDED_GCD_HPP\n#define MATH_EXTENDED_GCD_HPP\n\ntemplate<class\
    \ T>\nT extended_gcd(T a, T b, T &x, T &y) { // ax+by=gcd(a,b)\n\tif (b == 0)\
    \ {\n\t\tx = 1;\n\t\ty = 0;\n\t\treturn a;\n\t}\n\tT d = extended_gcd(b, a % b,\
    \ y, x);\n\ty -= a / b * x;\n\treturn d;\n}\n\ntemplate<class T>\nT modinv(T a,\
    \ T mod) { // a,mod\u306F\u4E92\u3044\u306B\u7D20\n\tT x, y;\n\textended_gcd(a,\
    \ mod, x, y);\n\treturn (x % mod + mod) % mod;\n}\n\n#endif // MATH_EXTENDED_GCD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/extended_gcd.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/extended_gcd/ntl_1_e.test.cpp
documentation_of: src/math/extended_gcd.hpp
layout: document
redirect_from:
- /library/src/math/extended_gcd.hpp
- /library/src/math/extended_gcd.hpp.html
title: src/math/extended_gcd.hpp
---
