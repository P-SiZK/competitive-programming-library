---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/combination/abc145_d.test.cpp
    title: test/math/combination/abc145_d.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/combination.cpp\"\nconst int MOD = 1000000007;\n\
    const int MAX = 1100000;\n\nlong long fac[MAX], finv[MAX], inv[MAX];\n\nvoid init_combination()\
    \ {\n\tfac[0] = fac[1] = inv[1] = finv[0] = finv[1] = 1;\n\tfor (int i = 2; i\
    \ < MAX; ++i) {\n\t\tfac[i] = fac[i - 1] * i % MOD;\n\t\tinv[i] = MOD - inv[MOD\
    \ % i] * (MOD / i) % MOD;\n\t\tfinv[i] = finv[i - 1] * inv[i] % MOD;\n\t}\n}\n\
    \nlong long combination(int n, int r) {\n\tif (n < r || n < 0 || r < 0) return\
    \ 0;\n\treturn fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;\n}\n"
  code: "const int MOD = 1000000007;\nconst int MAX = 1100000;\n\nlong long fac[MAX],\
    \ finv[MAX], inv[MAX];\n\nvoid init_combination() {\n\tfac[0] = fac[1] = inv[1]\
    \ = finv[0] = finv[1] = 1;\n\tfor (int i = 2; i < MAX; ++i) {\n\t\tfac[i] = fac[i\
    \ - 1] * i % MOD;\n\t\tinv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;\n\t\tfinv[i]\
    \ = finv[i - 1] * inv[i] % MOD;\n\t}\n}\n\nlong long combination(int n, int r)\
    \ {\n\tif (n < r || n < 0 || r < 0) return 0;\n\treturn fac[n] * (finv[r] * finv[n\
    \ - r] % MOD) % MOD;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/combination.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/combination/abc145_d.test.cpp
documentation_of: src/math/combination.cpp
layout: document
redirect_from:
- /library/src/math/combination.cpp
- /library/src/math/combination.cpp.html
title: src/math/combination.cpp
---
