---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
    title: test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructure/binary_indexed_tree.hpp\"\n\n\n\n#include\
    \ <vector>\n\ntemplate<class T>\nclass BinaryIndexedTree {\nprivate:\n\tint n;\n\
    \tstd::vector<T> tree; // 1-indexed\n\npublic:\n\tBinaryIndexedTree(int n) : n(n),\
    \ tree(n + 1) {}\n\n\tvoid add(int i, T x) {\n\t\twhile (i <= n) {\n\t\t\ttree[i]\
    \ += x;\n\t\t\ti += i & -i;\n\t\t}\n\t}\n\n\tT sum(int i) {\n\t\tT s(0);\n\t\t\
    while (i > 0) {\n\t\t\ts += tree[i];\n\t\t\ti -= i & -i;\n\t\t}\n\t\treturn s;\n\
    \t}\n\n\tT find(int l, int r) { // [l, r)\n\t\treturn sum(r - 1) - sum(l - 1);\n\
    \t}\n};\n\ntemplate<class T>\nlong long inversion_number(std::vector<T> const\
    \ &v) {\n\tint const N = v.size();\n\tBinaryIndexedTree<T> bit(N);\n\tlong long\
    \ res = 0;\n\tfor (int i = 0; i < N; ++i) {\n\t\tres += i - bit.sum(v[i]);\n\t\
    \tbit.add(v[i], 1);\n\t}\n\treturn res;\n}\n\n\n"
  code: "#ifndef DATASTRUCTURE_BINARY_INDEXED_TREE_HPP\n#define DATASTRUCTURE_BINARY_INDEXED_TREE_HPP\n\
    \n#include <vector>\n\ntemplate<class T>\nclass BinaryIndexedTree {\nprivate:\n\
    \tint n;\n\tstd::vector<T> tree; // 1-indexed\n\npublic:\n\tBinaryIndexedTree(int\
    \ n) : n(n), tree(n + 1) {}\n\n\tvoid add(int i, T x) {\n\t\twhile (i <= n) {\n\
    \t\t\ttree[i] += x;\n\t\t\ti += i & -i;\n\t\t}\n\t}\n\n\tT sum(int i) {\n\t\t\
    T s(0);\n\t\twhile (i > 0) {\n\t\t\ts += tree[i];\n\t\t\ti -= i & -i;\n\t\t}\n\
    \t\treturn s;\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\treturn sum(r - 1)\
    \ - sum(l - 1);\n\t}\n};\n\ntemplate<class T>\nlong long inversion_number(std::vector<T>\
    \ const &v) {\n\tint const N = v.size();\n\tBinaryIndexedTree<T> bit(N);\n\tlong\
    \ long res = 0;\n\tfor (int i = 0; i < N; ++i) {\n\t\tres += i - bit.sum(v[i]);\n\
    \t\tbit.add(v[i], 1);\n\t}\n\treturn res;\n}\n\n#endif // DATASTRUCTURE_BINARY_INDEXED_TREE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
documentation_of: src/datastructure/binary_indexed_tree.hpp
layout: document
title: Binary Indexed Tree (Fenwick Tree)
---
