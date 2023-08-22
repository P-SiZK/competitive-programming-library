---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/extended_gcd/ntl_1_e.test.cpp
    title: test/math/extended_gcd/ntl_1_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/extended_gcd.hpp\"\ntemplate<class T>\nT extended_gcd(T\
    \ a, T b, T &x, T &y) { // ax+by=gcd(a,b)\n\tif (b == 0) {\n\t\tx = 1;\n\t\ty\
    \ = 0;\n\t\treturn a;\n\t}\n\tT d = extended_gcd(b, a % b, y, x);\n\ty -= a /\
    \ b * x;\n\treturn d;\n}\n\ntemplate<class T>\nT modinv(T a, T mod) { // a,mod\u306F\
    \u4E92\u3044\u306B\u7D20\n\tT x, y;\n\textended_gcd(a, mod, x, y);\n\treturn (x\
    \ % mod + mod) % mod;\n}\n"
  code: "template<class T>\nT extended_gcd(T a, T b, T &x, T &y) { // ax+by=gcd(a,b)\n\
    \tif (b == 0) {\n\t\tx = 1;\n\t\ty = 0;\n\t\treturn a;\n\t}\n\tT d = extended_gcd(b,\
    \ a % b, y, x);\n\ty -= a / b * x;\n\treturn d;\n}\n\ntemplate<class T>\nT modinv(T\
    \ a, T mod) { // a,mod\u306F\u4E92\u3044\u306B\u7D20\n\tT x, y;\n\textended_gcd(a,\
    \ mod, x, y);\n\treturn (x % mod + mod) % mod;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/extended_gcd.hpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/extended_gcd/ntl_1_e.test.cpp
documentation_of: src/math/extended_gcd.hpp
layout: document
redirect_from:
- /library/src/math/extended_gcd.hpp
- /library/src/math/extended_gcd.hpp.html
title: src/math/extended_gcd.hpp
---
