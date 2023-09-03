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
  bundledCode: "#line 1 \"src/math/divisor.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <vector>\n\ntemplate<class T>\nstd::vector<T> divisor(T n) {\n\tstd::vector<T>\
    \ res;\n\tfor (T i = 1; i * i <= n; ++i) {\n\t\tif (n % i == 0) {\n\t\t\tres.push_back(i);\n\
    \t\t\tif (i * i != n) res.push_back(n / i);\n\t\t}\n\t}\n\tstd::sort(res.begin(),\
    \ res.end());\n\treturn res;\n}\n\n\n"
  code: "#ifndef MATH_DIVISOR_HPP\n#define MATH_DIVISOR_HPP\n\n#include <algorithm>\n\
    #include <vector>\n\ntemplate<class T>\nstd::vector<T> divisor(T n) {\n\tstd::vector<T>\
    \ res;\n\tfor (T i = 1; i * i <= n; ++i) {\n\t\tif (n % i == 0) {\n\t\t\tres.push_back(i);\n\
    \t\t\tif (i * i != n) res.push_back(n / i);\n\t\t}\n\t}\n\tstd::sort(res.begin(),\
    \ res.end());\n\treturn res;\n}\n\n#endif // MATH_DIVISOR_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisor.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/divisor.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---
