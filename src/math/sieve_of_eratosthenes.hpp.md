---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/sieve_of_eratosthenes/aoj_1276.test.cpp
    title: test/math/sieve_of_eratosthenes/aoj_1276.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/sieve_of_eratosthenes.hpp\"\n\n\n\n#include <vector>\n\
    \nclass SieveOfEratosthenes {\nprivate:\n\tstd::vector<bool> is_prime;\n\tstd::vector<int>\
    \ min_factor;\n\npublic:\n\tSieveOfEratosthenes(int n) : is_prime(n + 1, true),\
    \ min_factor(n + 1, -1) {\n\t\tis_prime[0] = is_prime[1] = false;\n\t\tmin_factor[1]\
    \ = 1;\n\t\tfor (int p = 2; p * p <= n; ++p) {\n\t\t\tif (!is_prime[p]) continue;\n\
    \t\t\tmin_factor[p] = p;\n\t\t\tfor (int q = p * p; q <= n; q += p) {\n\t\t\t\t\
    is_prime[q] = false;\n\t\t\t\tif (min_factor[q] == -1) min_factor[q] = p;\n\t\t\
    \t}\n\t\t}\n\t}\n\n\tstd::vector<bool> prime_table() { return is_prime; }\n\n\t\
    std::vector<std::pair<int, int>> factorize(int n) {\n\t\tstd::vector<std::pair<int,\
    \ int>> res;\n\t\twhile (n > 1) {\n\t\t\tint p = min_factor[n];\n\t\t\tint exp\
    \ = 0;\n\t\t\twhile (min_factor[n] == p) {\n\t\t\t\tn /= p;\n\t\t\t\t++exp;\n\t\
    \t\t}\n\t\t\tres.emplace_back(p, exp);\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<int>\
    \ divisor(int n) {\n\t\tstd::vector<int> res{1};\n\t\tfor (auto const &[p, exp]\
    \ : factorize(n)) {\n\t\t\tint sz = res.size();\n\t\t\tfor (int i = 0; i < sz;\
    \ ++i) {\n\t\t\t\tint x = 1;\n\t\t\t\tfor (int j = 0; j < exp; ++j) {\n\t\t\t\t\
    \tx *= p;\n\t\t\t\t\tres.push_back(res[i] * x);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\
    \treturn res;\n\t}\n};\n\n\n"
  code: "#ifndef MATH_SIEVE_OF_ERATOSTHENES\n#define MATH_SIEVE_OF_ERATOSTHENES\n\n\
    #include <vector>\n\nclass SieveOfEratosthenes {\nprivate:\n\tstd::vector<bool>\
    \ is_prime;\n\tstd::vector<int> min_factor;\n\npublic:\n\tSieveOfEratosthenes(int\
    \ n) : is_prime(n + 1, true), min_factor(n + 1, -1) {\n\t\tis_prime[0] = is_prime[1]\
    \ = false;\n\t\tmin_factor[1] = 1;\n\t\tfor (int p = 2; p * p <= n; ++p) {\n\t\
    \t\tif (!is_prime[p]) continue;\n\t\t\tmin_factor[p] = p;\n\t\t\tfor (int q =\
    \ p * p; q <= n; q += p) {\n\t\t\t\tis_prime[q] = false;\n\t\t\t\tif (min_factor[q]\
    \ == -1) min_factor[q] = p;\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::vector<bool> prime_table()\
    \ { return is_prime; }\n\n\tstd::vector<std::pair<int, int>> factorize(int n)\
    \ {\n\t\tstd::vector<std::pair<int, int>> res;\n\t\twhile (n > 1) {\n\t\t\tint\
    \ p = min_factor[n];\n\t\t\tint exp = 0;\n\t\t\twhile (min_factor[n] == p) {\n\
    \t\t\t\tn /= p;\n\t\t\t\t++exp;\n\t\t\t}\n\t\t\tres.emplace_back(p, exp);\n\t\t\
    }\n\t\treturn res;\n\t}\n\n\tstd::vector<int> divisor(int n) {\n\t\tstd::vector<int>\
    \ res{1};\n\t\tfor (auto const &[p, exp] : factorize(n)) {\n\t\t\tint sz = res.size();\n\
    \t\t\tfor (int i = 0; i < sz; ++i) {\n\t\t\t\tint x = 1;\n\t\t\t\tfor (int j =\
    \ 0; j < exp; ++j) {\n\t\t\t\t\tx *= p;\n\t\t\t\t\tres.push_back(res[i] * x);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n#endif // MATH_SIEVE_OF_ERATOSTHENES\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/sieve_of_eratosthenes.hpp
  requiredBy: []
  timestamp: '2023-11-13 04:33:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/sieve_of_eratosthenes/aoj_1276.test.cpp
documentation_of: src/math/sieve_of_eratosthenes.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
