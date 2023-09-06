---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/extended_gcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/math/extended_gcd/aoj_ntl_1_e.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\n\n\
    #line 1 \"src/math/extended_gcd.hpp\"\n\n\n\ntemplate<class T>\nT extended_gcd(T\
    \ a, T b, T &x, T &y) { // ax+by=gcd(a,b)\n\tif (b == 0) {\n\t\tx = 1;\n\t\ty\
    \ = 0;\n\t\treturn a;\n\t}\n\tT d = extended_gcd(b, a % b, y, x);\n\ty -= a /\
    \ b * x;\n\treturn d;\n}\n\ntemplate<class T>\nT modinv(T a, T mod) { // a,mod\u306F\
    \u4E92\u3044\u306B\u7D20\n\tT x, y;\n\textended_gcd(a, mod, x, y);\n\treturn (x\
    \ % mod + mod) % mod;\n}\n\n\n#line 4 \"test/math/extended_gcd/aoj_ntl_1_e.test.cpp\"\
    \n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tint a, b, x,\
    \ y;\n\tcin >> a >> b;\n\textended_gcd(a, b, x, y);\n\tcout << x << \" \" << y\
    \ << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\n\
    \n#include \"src/math/extended_gcd.hpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n\tint a, b, x, y;\n\tcin >> a >> b;\n\textended_gcd(a,\
    \ b, x, y);\n\tcout << x << \" \" << y << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/math/extended_gcd.hpp
  isVerificationFile: true
  path: test/math/extended_gcd/aoj_ntl_1_e.test.cpp
  requiredBy: []
  timestamp: '2023-09-06 15:21:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/extended_gcd/aoj_ntl_1_e.test.cpp
layout: document
redirect_from:
- /verify/test/math/extended_gcd/aoj_ntl_1_e.test.cpp
- /verify/test/math/extended_gcd/aoj_ntl_1_e.test.cpp.html
title: test/math/extended_gcd/aoj_ntl_1_e.test.cpp
---
