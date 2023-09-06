---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/vector/inversion_number.hpp
    title: src/vector/inversion_number.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/vector/inversion_number/aoj_alds1_5_d.test.cpp
    title: test/vector/inversion_number/aoj_alds1_5_d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/vector/coordinate_compression.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <vector>\n\ntemplate<class T>\nclass CoordinateCompression\
    \ {\nprivate:\n\tstd::vector<T> x;\n\npublic:\n\tCoordinateCompression(std::vector<T>\
    \ const &v) : x(v.size()) {\n\t\tstd::partial_sort_copy(v.begin(), v.end(), x.begin(),\
    \ x.end());\n\t\tx.erase(std::unique(x.begin(), x.end()), x.end());\n\t}\n\n\t\
    [[nodiscard]] int size() const { return x.size(); }\n\n\tT operator[](int k) {\
    \ return x[k]; }\n\n\t[[nodiscard]] int get(T const &v) const {\n\t\treturn std::lower_bound(x.begin(),\
    \ x.end(), v) - x.begin();\n\t}\n};\n\n\n"
  code: "#ifndef VECTOR_COORDINATE_COMPRESSION\n#define VECTOR_COORDINATE_COMPRESSION\n\
    \n#include <algorithm>\n#include <vector>\n\ntemplate<class T>\nclass CoordinateCompression\
    \ {\nprivate:\n\tstd::vector<T> x;\n\npublic:\n\tCoordinateCompression(std::vector<T>\
    \ const &v) : x(v.size()) {\n\t\tstd::partial_sort_copy(v.begin(), v.end(), x.begin(),\
    \ x.end());\n\t\tx.erase(std::unique(x.begin(), x.end()), x.end());\n\t}\n\n\t\
    [[nodiscard]] int size() const { return x.size(); }\n\n\tT operator[](int k) {\
    \ return x[k]; }\n\n\t[[nodiscard]] int get(T const &v) const {\n\t\treturn std::lower_bound(x.begin(),\
    \ x.end(), v) - x.begin();\n\t}\n};\n\n#endif // VECTOR_COORDINATE_COMPRESSION\n"
  dependsOn: []
  isVerificationFile: false
  path: src/vector/coordinate_compression.hpp
  requiredBy:
  - src/vector/inversion_number.hpp
  timestamp: '2023-09-06 14:54:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/vector/inversion_number/aoj_alds1_5_d.test.cpp
documentation_of: src/vector/coordinate_compression.hpp
layout: document
redirect_from:
- /library/src/vector/coordinate_compression.hpp
- /library/src/vector/coordinate_compression.hpp.html
title: src/vector/coordinate_compression.hpp
---
