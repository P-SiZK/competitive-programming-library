---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/sieve_of_eratosthenes.hpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
  bundledCode: "#line 1 \"test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp\"\n\
    // verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\n\
    \n#line 1 \"src/math/sieve_of_eratosthenes.hpp\"\n\n\n\n#include <numeric>\n#include\
    \ <vector>\n\nclass SieveOfEratosthenes {\nprivate:\n\tstd::vector<int> min_factor;\n\
    \npublic:\n\tSieveOfEratosthenes(int n) : min_factor(n + 1) {\n\t\tstd::iota(min_factor.begin(),\
    \ min_factor.end(), 0);\n\t\tfor (int p = 2; p * p <= n; ++p) {\n\t\t\tif (min_factor[p]\
    \ < p) continue;\n\t\t\tfor (int q = p * p; q <= n; q += p) {\n\t\t\t\tif (min_factor[q]\
    \ == q) min_factor[q] = p;\n\t\t\t}\n\t\t}\n\t}\n\n\tbool is_prime(int n) { return\
    \ n > 1 && min_factor[n] == n; }\n\n\tstd::vector<std::pair<int, int>> factorize(int\
    \ n) {\n\t\tstd::vector<std::pair<int, int>> res;\n\t\twhile (n > 1) {\n\t\t\t\
    int p = min_factor[n];\n\t\t\tint exp = 0;\n\t\t\twhile (min_factor[n] == p) {\n\
    \t\t\t\tn /= p;\n\t\t\t\t++exp;\n\t\t\t}\n\t\t\tres.emplace_back(p, exp);\n\t\t\
    }\n\t\treturn res;\n\t}\n\n\tstd::vector<int> divisor(int n) {\n\t\tstd::vector<int>\
    \ res{1};\n\t\tfor (auto const &[p, exp] : factorize(n)) {\n\t\t\tint sz = res.size();\n\
    \t\t\tfor (int i = 0; i < sz; ++i) {\n\t\t\t\tint x = 1;\n\t\t\t\tfor (int j =\
    \ 0; j < exp; ++j) {\n\t\t\t\t\tx *= p;\n\t\t\t\t\tres.push_back(res[i] * x);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n\n#line 4 \"test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp\"\
    \n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tint a, b, c;\n\
    \tcin >> a >> b >> c;\n\tint res = 0;\n\tfor (auto d : SieveOfEratosthenes(c).divisor(c))\
    \ {\n\t\tif (a <= d && d <= b) ++res;\n\t}\n\tcout << res << endl;\n\n\treturn\
    \ 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\n\
    \n#include \"src/math/sieve_of_eratosthenes.hpp\"\n\n#include <iostream>\n\nusing\
    \ namespace std;\n\nint main() {\n\tint a, b, c;\n\tcin >> a >> b >> c;\n\tint\
    \ res = 0;\n\tfor (auto d : SieveOfEratosthenes(c).divisor(c)) {\n\t\tif (a <=\
    \ d && d <= b) ++res;\n\t}\n\tcout << res << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/math/sieve_of_eratosthenes.hpp
  isVerificationFile: true
  path: test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 15:34:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp
layout: document
redirect_from:
- /verify/test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp
- /verify/test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp.html
title: test/math/sieve_of_eratosthenes/aoj_itp1_3_d.test.cpp
---
