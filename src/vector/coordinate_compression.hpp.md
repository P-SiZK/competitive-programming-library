---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/vector/inversion_number.hpp
    title: "\u8EE2\u5012\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/vector/inversion_number/aoj_alds1_5_d.test.cpp
    title: test/vector/inversion_number/aoj_alds1_5_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/vector/inversion_number/aoj_alds1_5_d.test.cpp
documentation_of: src/vector/coordinate_compression.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---
