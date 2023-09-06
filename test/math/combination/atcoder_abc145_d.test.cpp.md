---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/combination.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc145/tasks/abc145_d
    links:
    - https://atcoder.jp/contests/abc145/tasks/abc145_d
  bundledCode: "#line 1 \"test/math/combination/atcoder_abc145_d.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc145/tasks/abc145_d\n\n#line 1 \"src/math/combination.hpp\"\
    \n\n\n\n#include <array>\n\ntemplate<class T, int SIZE = 1100000, T MOD = 1000000007>\n\
    class Combination {\nprivate:\n\tstd::array<T, SIZE> fac, finv, inv;\n\npublic:\n\
    \tCombination() {\n\t\tfac[0] = fac[1] = inv[1] = finv[0] = finv[1] = 1;\n\t\t\
    for (int i = 2; i < SIZE; ++i) {\n\t\t\tfac[i] = fac[i - 1] * i % MOD;\n\t\t\t\
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;\n\t\t\tfinv[i] = finv[i - 1] *\
    \ inv[i] % MOD;\n\t\t}\n\t}\n\n\tT inverse(int n) { return inv[n]; }\n\n\tT factorial(int\
    \ n) { return fac[n]; }\n\n\tT inverse_factorial(int n) { return finv[n]; }\n\n\
    \tT permutation(int n, int r) {\n\t\tif (n < r || n < 0 || r < 0) return 0;\n\t\
    \treturn fac(n) * finv(n - r);\n\t}\n\n\tT combination(int n, int r) {\n\t\tif\
    \ (n < r || n < 0 || r < 0) return 0;\n\t\treturn fac[n] * (finv[r] * finv[n -\
    \ r] % MOD) % MOD;\n\t}\n};\n\n\n#line 4 \"test/math/combination/atcoder_abc145_d.test.cpp\"\
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
  path: test/math/combination/atcoder_abc145_d.test.cpp
  requiredBy: []
  timestamp: '2023-09-06 15:21:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/combination/atcoder_abc145_d.test.cpp
layout: document
redirect_from:
- /verify/test/math/combination/atcoder_abc145_d.test.cpp
- /verify/test/math/combination/atcoder_abc145_d.test.cpp.html
title: test/math/combination/atcoder_abc145_d.test.cpp
---
