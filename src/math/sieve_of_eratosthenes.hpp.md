---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/sieve_of_eratosthenes/aoj_1276.test.cpp
    title: test/math/sieve_of_eratosthenes/aoj_1276.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp
    title: test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/sieve_of_eratosthenes.hpp\"\n\n\n\n#include <numeric>\n\
    #include <vector>\n\nclass SieveOfEratosthenes {\nprivate:\n\tstd::vector<int>\
    \ min_factor;\n\npublic:\n\tSieveOfEratosthenes(int n) : min_factor(n + 1) {\n\
    \t\tstd::iota(min_factor.begin(), min_factor.end(), 0);\n\t\tfor (int p = 2; p\
    \ * p <= n; ++p) {\n\t\t\tif (min_factor[p] < p) continue;\n\t\t\tfor (int q =\
    \ p * p; q <= n; q += p) {\n\t\t\t\tif (min_factor[q] == q) min_factor[q] = p;\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tbool is_prime(int n) { return n > 1 && min_factor[n]\
    \ == n; }\n\n\tstd::vector<std::pair<int, int>> factorize(int n) {\n\t\tstd::vector<std::pair<int,\
    \ int>> res;\n\t\twhile (n > 1) {\n\t\t\tint p = min_factor[n];\n\t\t\tint exp\
    \ = 0;\n\t\t\twhile (min_factor[n] == p) {\n\t\t\t\tn /= p;\n\t\t\t\t++exp;\n\t\
    \t\t}\n\t\t\tres.emplace_back(p, exp);\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<int>\
    \ divisor(int n) {\n\t\tstd::vector<int> res{1};\n\t\tfor (auto const &[p, exp]\
    \ : factorize(n)) {\n\t\t\tint sz = res.size();\n\t\t\tfor (int i = 0; i < sz;\
    \ ++i) {\n\t\t\t\tint x = 1;\n\t\t\t\tfor (int j = 0; j < exp; ++j) {\n\t\t\t\t\
    \tx *= p;\n\t\t\t\t\tres.push_back(res[i] * x);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\
    \treturn res;\n\t}\n};\n\n\n"
  code: "#ifndef MATH_SIEVE_OF_ERATOSTHENES\n#define MATH_SIEVE_OF_ERATOSTHENES\n\n\
    #include <numeric>\n#include <vector>\n\nclass SieveOfEratosthenes {\nprivate:\n\
    \tstd::vector<int> min_factor;\n\npublic:\n\tSieveOfEratosthenes(int n) : min_factor(n\
    \ + 1) {\n\t\tstd::iota(min_factor.begin(), min_factor.end(), 0);\n\t\tfor (int\
    \ p = 2; p * p <= n; ++p) {\n\t\t\tif (min_factor[p] < p) continue;\n\t\t\tfor\
    \ (int q = p * p; q <= n; q += p) {\n\t\t\t\tif (min_factor[q] == q) min_factor[q]\
    \ = p;\n\t\t\t}\n\t\t}\n\t}\n\n\tbool is_prime(int n) { return n > 1 && min_factor[n]\
    \ == n; }\n\n\tstd::vector<std::pair<int, int>> factorize(int n) {\n\t\tstd::vector<std::pair<int,\
    \ int>> res;\n\t\twhile (n > 1) {\n\t\t\tint p = min_factor[n];\n\t\t\tint exp\
    \ = 0;\n\t\t\twhile (min_factor[n] == p) {\n\t\t\t\tn /= p;\n\t\t\t\t++exp;\n\t\
    \t\t}\n\t\t\tres.emplace_back(p, exp);\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<int>\
    \ divisor(int n) {\n\t\tstd::vector<int> res{1};\n\t\tfor (auto const &[p, exp]\
    \ : factorize(n)) {\n\t\t\tint sz = res.size();\n\t\t\tfor (int i = 0; i < sz;\
    \ ++i) {\n\t\t\t\tint x = 1;\n\t\t\t\tfor (int j = 0; j < exp; ++j) {\n\t\t\t\t\
    \tx *= p;\n\t\t\t\t\tres.push_back(res[i] * x);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\
    \treturn res;\n\t}\n};\n\n#endif // MATH_SIEVE_OF_ERATOSTHENES\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/sieve_of_eratosthenes.hpp
  requiredBy: []
  timestamp: '2023-11-13 15:34:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/sieve_of_eratosthenes/aoj_1276.test.cpp
  - test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp
documentation_of: src/math/sieve_of_eratosthenes.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
