---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/tree/euler_tour.hpp
    title: Euler Tour
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/sparse_table/dsl_3_d.test.cpp
    title: test/datastructure/sparse_table/dsl_3_d.test.cpp
  - icon: ':x:'
    path: test/tree/euler_tour/abc294_g.test.cpp
    title: test/tree/euler_tour/abc294_g.test.cpp
  - icon: ':x:'
    path: test/tree/euler_tour/grl_5_c.test.cpp
    title: test/tree/euler_tour/grl_5_c.test.cpp
  - icon: ':x:'
    path: test/tree/euler_tour/grl_5_d.test.cpp
    title: test/tree/euler_tour/grl_5_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/euler_tour/vertex_add_path_sum.test.cpp
    title: test/tree/euler_tour/vertex_add_path_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructure/sparse_table.hpp\"\n\n\n\n#include <vector>\n\
    \ntemplate<class T, class F>\nclass SparseTable {\nprivate:\n\tstd::vector<std::vector<T>>\
    \ table;\n\tstd::vector<int> log_table;\n\tF f;\n\npublic:\n\tSparseTable(std::vector<T>\
    \ const &v, F f) : f(f) {\n\t\tint n = v.size();\n\t\tint h = 1;\n\t\twhile ((1\
    \ << h) <= n) ++h;\n\t\ttable.assign(h, std::vector<T>(n));\n\t\tlog_table.assign(n\
    \ + 1, 0);\n\t\tfor (int i = 2; i <= n; ++i) log_table[i] = log_table[i >> 1]\
    \ + 1;\n\n\t\tfor (int i = 0; i < n; ++i) table[0][i] = v[i];\n\t\tfor (int i\
    \ = 1, k = 1; i < h; ++i, k <<= 1)\n\t\t\tfor (int j = 0; j < n; ++j)\n\t\t\t\t\
    table[i][j] = f(table[i - 1][j], table[i - 1][std::min(j + k, n - 1)]);\n\t}\n\
    \n\tT query(int l, int r) { // [l, r)\n\t\tint k = log_table[r - l];\n\t\treturn\
    \ f(table[k][l], table[k][r - (1 << k)]);\n\t}\n};\n\n\n"
  code: "#ifndef DATASTRUCTURE_SPARSE_TABLE_HPP\n#define DATASTRUCTURE_SPARSE_TABLE_HPP\n\
    \n#include <vector>\n\ntemplate<class T, class F>\nclass SparseTable {\nprivate:\n\
    \tstd::vector<std::vector<T>> table;\n\tstd::vector<int> log_table;\n\tF f;\n\n\
    public:\n\tSparseTable(std::vector<T> const &v, F f) : f(f) {\n\t\tint n = v.size();\n\
    \t\tint h = 1;\n\t\twhile ((1 << h) <= n) ++h;\n\t\ttable.assign(h, std::vector<T>(n));\n\
    \t\tlog_table.assign(n + 1, 0);\n\t\tfor (int i = 2; i <= n; ++i) log_table[i]\
    \ = log_table[i >> 1] + 1;\n\n\t\tfor (int i = 0; i < n; ++i) table[0][i] = v[i];\n\
    \t\tfor (int i = 1, k = 1; i < h; ++i, k <<= 1)\n\t\t\tfor (int j = 0; j < n;\
    \ ++j)\n\t\t\t\ttable[i][j] = f(table[i - 1][j], table[i - 1][std::min(j + k,\
    \ n - 1)]);\n\t}\n\n\tT query(int l, int r) { // [l, r)\n\t\tint k = log_table[r\
    \ - l];\n\t\treturn f(table[k][l], table[k][r - (1 << k)]);\n\t}\n};\n\n#endif\
    \ // DATASTRUCTURE_SPARSE_TABLE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/sparse_table.hpp
  requiredBy:
  - src/tree/euler_tour.hpp
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/tree/euler_tour/grl_5_d.test.cpp
  - test/tree/euler_tour/grl_5_c.test.cpp
  - test/tree/euler_tour/vertex_add_path_sum.test.cpp
  - test/tree/euler_tour/abc294_g.test.cpp
  - test/datastructure/sparse_table/dsl_3_d.test.cpp
documentation_of: src/datastructure/sparse_table.hpp
layout: document
title: Sparse Table
---
