---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/divisor.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \nusing namespace std;\n\nvector<long long> divisor(long long n) {\n\tvector<long\
    \ long> res;\n\tfor (long long i = 1; i * i <= n; ++i) {\n\t\tif (n % i == 0)\
    \ {\n\t\t\tres.push_back(i);\n\t\t\tif (i * i != n) res.push_back(n / i);\n\t\t\
    }\n\t}\n\tsort(res.begin(), res.end());\n\treturn res;\n}\n"
  code: "#include <algorithm>\n#include <vector>\n\nusing namespace std;\n\nvector<long\
    \ long> divisor(long long n) {\n\tvector<long long> res;\n\tfor (long long i =\
    \ 1; i * i <= n; ++i) {\n\t\tif (n % i == 0) {\n\t\t\tres.push_back(i);\n\t\t\t\
    if (i * i != n) res.push_back(n / i);\n\t\t}\n\t}\n\tsort(res.begin(), res.end());\n\
    \treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisor.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/divisor.cpp
layout: document
redirect_from:
- /library/src/math/divisor.cpp
- /library/src/math/divisor.cpp.html
title: src/math/divisor.cpp
---
