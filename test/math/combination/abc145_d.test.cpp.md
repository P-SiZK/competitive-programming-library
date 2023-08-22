---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/combination.hpp
    title: src/math/combination.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc145/tasks/abc145_d
    links:
    - https://atcoder.jp/contests/abc145/tasks/abc145_d
  bundledCode: "#line 1 \"test/math/combination/abc145_d.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc145/tasks/abc145_d\n\n#line 1 \"src/math/combination.hpp\"\
    \n#include <cstddef>\n\ntemplate<class T, size_t SIZE = 1100000, T MOD = 1000000007>\n\
    class Combination {\nprivate:\n\tT fac[SIZE], finv[SIZE], inv[SIZE];\n\npublic:\n\
    \tCombination() {\n\t\tfac[0] = fac[1] = inv[1] = finv[0] = finv[1] = 1;\n\t\t\
    for (size_t i = 2; i < SIZE; ++i) {\n\t\t\tfac[i] = fac[i - 1] * i % MOD;\n\t\t\
    \tinv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;\n\t\t\tfinv[i] = finv[i - 1]\
    \ * inv[i] % MOD;\n\t\t}\n\t}\n\n\tT factorial(int n) { return fac[n]; }\n\n\t\
    T inverse_factorial(int n) { return finv[n]; }\n\n\tT combination(int n, int r)\
    \ {\n\t\tif (n < r || n < 0 || r < 0) return 0;\n\t\treturn fac[n] * (finv[r]\
    \ * finv[n - r] % MOD) % MOD;\n\t}\n};\n#line 4 \"test/math/combination/abc145_d.test.cpp\"\
    \n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tCombination<long\
    \ long> comb;\n\tint x, y;\n\tcin >> x >> y;\n\tint xx = -x + 2 * y, yy = 2 *\
    \ x - y;\n\tx = xx / 3, y = yy / 3;\n\tif (xx < 0 || yy < 0 || xx % 3 != 0 ||\
    \ yy % 3 != 0) cout << 0 << endl;\n\telse cout << comb.combination(x + y, x) <<\
    \ endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc145/tasks/abc145_d\n\
    \n#include \"src/math/combination.hpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n\tCombination<long long> comb;\n\tint x, y;\n\tcin >>\
    \ x >> y;\n\tint xx = -x + 2 * y, yy = 2 * x - y;\n\tx = xx / 3, y = yy / 3;\n\
    \tif (xx < 0 || yy < 0 || xx % 3 != 0 || yy % 3 != 0) cout << 0 << endl;\n\telse\
    \ cout << comb.combination(x + y, x) << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/math/combination.hpp
  isVerificationFile: true
  path: test/math/combination/abc145_d.test.cpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/combination/abc145_d.test.cpp
layout: document
redirect_from:
- /verify/test/math/combination/abc145_d.test.cpp
- /verify/test/math/combination/abc145_d.test.cpp.html
title: test/math/combination/abc145_d.test.cpp
---
