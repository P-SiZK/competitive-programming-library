---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/divisor.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate<class T>\nstd::vector<T> divisor(T n) {\n\tstd::vector<T> res;\n\t\
    for (T i = 1; i * i <= n; ++i) {\n\t\tif (n % i == 0) {\n\t\t\tres.push_back(i);\n\
    \t\t\tif (i * i != n) res.push_back(n / i);\n\t\t}\n\t}\n\tstd::sort(res.begin(),\
    \ res.end());\n\treturn res;\n}\n"
  code: "#include <algorithm>\n#include <vector>\n\ntemplate<class T>\nstd::vector<T>\
    \ divisor(T n) {\n\tstd::vector<T> res;\n\tfor (T i = 1; i * i <= n; ++i) {\n\t\
    \tif (n % i == 0) {\n\t\t\tres.push_back(i);\n\t\t\tif (i * i != n) res.push_back(n\
    \ / i);\n\t\t}\n\t}\n\tstd::sort(res.begin(), res.end());\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisor.hpp
  requiredBy: []
  timestamp: '2023-08-31 13:01:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/divisor.hpp
layout: document
redirect_from:
- /library/src/math/divisor.hpp
- /library/src/math/divisor.hpp.html
title: src/math/divisor.hpp
---
