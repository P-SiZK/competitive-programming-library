---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/sparse_table/aoj_dsl_3_d.test.cpp
    title: test/datastructure/sparse_table/aoj_dsl_3_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructure/sparse_table.hpp\"\n\n\n\n#include <vector>\n\
    #include <algorithm>\n\ntemplate<class T, class F>\nclass SparseTable {\nprivate:\n\
    \tstd::vector<std::vector<T>> table;\n\tstd::vector<int> log_table;\n\tF f;\n\n\
    public:\n\tSparseTable(std::vector<T> const &v, F f) : f(f) {\n\t\tint n = v.size();\n\
    \t\tint h = 1;\n\t\twhile ((1 << h) <= n) ++h;\n\t\ttable.assign(h, std::vector<T>(n));\n\
    \t\tlog_table.assign(n + 1, 0);\n\t\tfor (int i = 2; i <= n; ++i) log_table[i]\
    \ = log_table[i >> 1] + 1;\n\n\t\tfor (int i = 0; i < n; ++i) table[0][i] = v[i];\n\
    \t\tfor (int i = 1, k = 1; i < h; ++i, k <<= 1)\n\t\t\tfor (int j = 0; j < n;\
    \ ++j)\n\t\t\t\ttable[i][j] = f(table[i - 1][j], table[i - 1][std::min(j + k,\
    \ n - 1)]);\n\t}\n\n\tT query(int l, int r) { // [l, r)\n\t\tint k = log_table[r\
    \ - l];\n\t\treturn f(table[k][l], table[k][r - (1 << k)]);\n\t}\n};\n\n\n"
  code: "#ifndef DATASTRUCTURE_SPARSE_TABLE_HPP\n#define DATASTRUCTURE_SPARSE_TABLE_HPP\n\
    \n#include <vector>\n#include <algorithm>\n\ntemplate<class T, class F>\nclass\
    \ SparseTable {\nprivate:\n\tstd::vector<std::vector<T>> table;\n\tstd::vector<int>\
    \ log_table;\n\tF f;\n\npublic:\n\tSparseTable(std::vector<T> const &v, F f) :\
    \ f(f) {\n\t\tint n = v.size();\n\t\tint h = 1;\n\t\twhile ((1 << h) <= n) ++h;\n\
    \t\ttable.assign(h, std::vector<T>(n));\n\t\tlog_table.assign(n + 1, 0);\n\t\t\
    for (int i = 2; i <= n; ++i) log_table[i] = log_table[i >> 1] + 1;\n\n\t\tfor\
    \ (int i = 0; i < n; ++i) table[0][i] = v[i];\n\t\tfor (int i = 1, k = 1; i <\
    \ h; ++i, k <<= 1)\n\t\t\tfor (int j = 0; j < n; ++j)\n\t\t\t\ttable[i][j] = f(table[i\
    \ - 1][j], table[i - 1][std::min(j + k, n - 1)]);\n\t}\n\n\tT query(int l, int\
    \ r) { // [l, r)\n\t\tint k = log_table[r - l];\n\t\treturn f(table[k][l], table[k][r\
    \ - (1 << k)]);\n\t}\n};\n\n#endif // DATASTRUCTURE_SPARSE_TABLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/sparse_table.hpp
  requiredBy: []
  timestamp: '2023-12-12 23:23:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/sparse_table/aoj_dsl_3_d.test.cpp
documentation_of: src/datastructure/sparse_table.hpp
layout: document
title: Sparse Table
---
