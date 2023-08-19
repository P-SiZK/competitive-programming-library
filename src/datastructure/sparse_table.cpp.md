---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/sparse_table/dsl_3_d.test.cpp
    title: test/datastructure/sparse_table/dsl_3_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructure/sparse_table.cpp\"\n#include <vector>\n\
    \nusing namespace std;\n\ntemplate<class T, class F>\nclass SparseTable {\nprivate:\n\
    \tvector<vector<T>> table;\n\tvector<int> log_table;\n\tF f;\n\npublic:\n\tSparseTable(const\
    \ vector<T> &v, F f) : f(f) {\n\t\tint n = v.size(), h = 1;\n\t\twhile ((1 <<\
    \ h) <= n) ++h;\n\t\ttable.assign(h, vector<T>(n));\n\t\tlog_table.assign(n +\
    \ 1, 0);\n\t\tfor (int i = 2; i <= n; ++i) log_table[i] = log_table[i >> 1] +\
    \ 1;\n\n\t\tfor (int i = 0; i < n; ++i) table[0][i] = v[i];\n\t\tfor (int i =\
    \ 1, k = 1; i < h; ++i, k <<= 1)\n\t\t\tfor (int j = 0; j < n; ++j)\n\t\t\t\t\
    table[i][j] =\n\t\t\t\t\tf(table[i - 1][j], table[i - 1][min(j + k, n - 1)]);\n\
    \t}\n\n\tT query(int l, int r) { // [l, r)\n\t\tint k = log_table[r - l];\n\t\t\
    return f(table[k][l], table[k][r - (1 << k)]);\n\t}\n};\n"
  code: "#include <vector>\n\nusing namespace std;\n\ntemplate<class T, class F>\n\
    class SparseTable {\nprivate:\n\tvector<vector<T>> table;\n\tvector<int> log_table;\n\
    \tF f;\n\npublic:\n\tSparseTable(const vector<T> &v, F f) : f(f) {\n\t\tint n\
    \ = v.size(), h = 1;\n\t\twhile ((1 << h) <= n) ++h;\n\t\ttable.assign(h, vector<T>(n));\n\
    \t\tlog_table.assign(n + 1, 0);\n\t\tfor (int i = 2; i <= n; ++i) log_table[i]\
    \ = log_table[i >> 1] + 1;\n\n\t\tfor (int i = 0; i < n; ++i) table[0][i] = v[i];\n\
    \t\tfor (int i = 1, k = 1; i < h; ++i, k <<= 1)\n\t\t\tfor (int j = 0; j < n;\
    \ ++j)\n\t\t\t\ttable[i][j] =\n\t\t\t\t\tf(table[i - 1][j], table[i - 1][min(j\
    \ + k, n - 1)]);\n\t}\n\n\tT query(int l, int r) { // [l, r)\n\t\tint k = log_table[r\
    \ - l];\n\t\treturn f(table[k][l], table[k][r - (1 << k)]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/sparse_table.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/sparse_table/dsl_3_d.test.cpp
documentation_of: src/datastructure/sparse_table.cpp
layout: document
redirect_from:
- /library/src/datastructure/sparse_table.cpp
- /library/src/datastructure/sparse_table.cpp.html
title: src/datastructure/sparse_table.cpp
---
