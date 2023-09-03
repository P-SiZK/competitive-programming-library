---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/combination/abc145_d.test.cpp
    title: test/math/combination/abc145_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/combination.hpp\"\n\n\n\n#include <cstddef>\n\n\
    template<class T, std::size_t SIZE = 1100000, T MOD = 1000000007>\nclass Combination\
    \ {\nprivate:\n\tT fac[SIZE], finv[SIZE], inv[SIZE];\n\npublic:\n\tCombination()\
    \ {\n\t\tfac[0] = fac[1] = inv[1] = finv[0] = finv[1] = 1;\n\t\tfor (std::size_t\
    \ i = 2; i < SIZE; ++i) {\n\t\t\tfac[i] = fac[i - 1] * i % MOD;\n\t\t\tinv[i]\
    \ = MOD - inv[MOD % i] * (MOD / i) % MOD;\n\t\t\tfinv[i] = finv[i - 1] * inv[i]\
    \ % MOD;\n\t\t}\n\t}\n\n\tT factorial(int n) { return fac[n]; }\n\n\tT inverse_factorial(int\
    \ n) { return finv[n]; }\n\n\tT combination(int n, int r) {\n\t\tif (n < r ||\
    \ n < 0 || r < 0) return 0;\n\t\treturn fac[n] * (finv[r] * finv[n - r] % MOD)\
    \ % MOD;\n\t}\n};\n\n\n"
  code: "#ifndef MATH_COMBINATION_HPP\n#define MATH_COMBINATION_HPP\n\n#include <cstddef>\n\
    \ntemplate<class T, std::size_t SIZE = 1100000, T MOD = 1000000007>\nclass Combination\
    \ {\nprivate:\n\tT fac[SIZE], finv[SIZE], inv[SIZE];\n\npublic:\n\tCombination()\
    \ {\n\t\tfac[0] = fac[1] = inv[1] = finv[0] = finv[1] = 1;\n\t\tfor (std::size_t\
    \ i = 2; i < SIZE; ++i) {\n\t\t\tfac[i] = fac[i - 1] * i % MOD;\n\t\t\tinv[i]\
    \ = MOD - inv[MOD % i] * (MOD / i) % MOD;\n\t\t\tfinv[i] = finv[i - 1] * inv[i]\
    \ % MOD;\n\t\t}\n\t}\n\n\tT factorial(int n) { return fac[n]; }\n\n\tT inverse_factorial(int\
    \ n) { return finv[n]; }\n\n\tT combination(int n, int r) {\n\t\tif (n < r ||\
    \ n < 0 || r < 0) return 0;\n\t\treturn fac[n] * (finv[r] * finv[n - r] % MOD)\
    \ % MOD;\n\t}\n};\n\n#endif // MATH_COMBINATION_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/combination.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/combination/abc145_d.test.cpp
documentation_of: src/math/combination.hpp
layout: document
title: "\u7D44\u307F\u5408\u308F\u305B"
---
