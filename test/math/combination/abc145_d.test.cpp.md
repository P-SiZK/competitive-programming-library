---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/combination.cpp
    title: src/math/combination.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc145/tasks/abc145_d
    links:
    - https://atcoder.jp/contests/abc145/tasks/abc145_d
  bundledCode: "#line 1 \"test/math/combination/abc145_d.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc145/tasks/abc145_d\n\n#line 1 \"src/math/combination.cpp\"\
    \nconst int MOD = 1000000007;\nconst int MAX = 1100000;\n\nlong long fac[MAX],\
    \ finv[MAX], inv[MAX];\n\nvoid init_combination() {\n\tfac[0] = fac[1] = inv[1]\
    \ = finv[0] = finv[1] = 1;\n\tfor (int i = 2; i < MAX; ++i) {\n\t\tfac[i] = fac[i\
    \ - 1] * i % MOD;\n\t\tinv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;\n\t\tfinv[i]\
    \ = finv[i - 1] * inv[i] % MOD;\n\t}\n}\n\nlong long combination(int n, int r)\
    \ {\n\tif (n < r || n < 0 || r < 0) return 0;\n\treturn fac[n] * (finv[r] * finv[n\
    \ - r] % MOD) % MOD;\n}\n#line 4 \"test/math/combination/abc145_d.test.cpp\"\n\
    \n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tinit_combination();\n\
    \tint x, y;\n\tcin >> x >> y;\n\tint xx = -x + 2 * y, yy = 2 * x - y;\n\tx = xx\
    \ / 3, y = yy / 3;\n\tif (xx < 0 || yy < 0 || xx % 3 != 0 || yy % 3 != 0) cout\
    \ << 0 << endl;\n\telse cout << combination(x + y, x) << endl;\n\n\treturn 0;\n\
    }\n"
  code: "// verification-helper: PROBLEM https://atcoder.jp/contests/abc145/tasks/abc145_d\n\
    \n#include \"src/math/combination.cpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n\tinit_combination();\n\tint x, y;\n\tcin >> x >> y;\n\
    \tint xx = -x + 2 * y, yy = 2 * x - y;\n\tx = xx / 3, y = yy / 3;\n\tif (xx <\
    \ 0 || yy < 0 || xx % 3 != 0 || yy % 3 != 0) cout << 0 << endl;\n\telse cout <<\
    \ combination(x + y, x) << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/math/combination.cpp
  isVerificationFile: true
  path: test/math/combination/abc145_d.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/combination/abc145_d.test.cpp
layout: document
redirect_from:
- /verify/test/math/combination/abc145_d.test.cpp
- /verify/test/math/combination/abc145_d.test.cpp.html
title: test/math/combination/abc145_d.test.cpp
---
