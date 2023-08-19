---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
    title: test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructure/binary_indexed_tree.cpp\"\n#include <iostream>\n\
    #include <vector>\n\nusing namespace std;\n\ntemplate<class T>\nstruct BinaryIndexedTree\
    \ {\n\tint n;\n\tvector<T> tree; // 1-indexed\n\n\tBinaryIndexedTree(int n) :\
    \ n(n), tree(n + 1) {}\n\n\tvoid add(int i, T x) {\n\t\twhile (i <= n) {\n\t\t\
    \ttree[i] += x;\n\t\t\ti += i & -i;\n\t\t}\n\t}\n\n\tT sum(int i) {\n\t\tT s(0);\n\
    \t\twhile (i > 0) {\n\t\t\ts += tree[i];\n\t\t\ti -= i & -i;\n\t\t}\n\t\treturn\
    \ s;\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\t\treturn sum(r - 1) - sum(l\
    \ - 1);\n\t}\n};\n\nlong long inversion_number(const vector<int> &v) {\n\tconst\
    \ int n = v.size();\n\tBinaryIndexedTree<int> bit(n);\n\tlong long res = 0;\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tres += i - bit.sum(v[i]);\n\t\tbit.add(v[i],\
    \ 1);\n\t}\n\treturn res;\n}\n"
  code: "#include <iostream>\n#include <vector>\n\nusing namespace std;\n\ntemplate<class\
    \ T>\nstruct BinaryIndexedTree {\n\tint n;\n\tvector<T> tree; // 1-indexed\n\n\
    \tBinaryIndexedTree(int n) : n(n), tree(n + 1) {}\n\n\tvoid add(int i, T x) {\n\
    \t\twhile (i <= n) {\n\t\t\ttree[i] += x;\n\t\t\ti += i & -i;\n\t\t}\n\t}\n\n\t\
    T sum(int i) {\n\t\tT s(0);\n\t\twhile (i > 0) {\n\t\t\ts += tree[i];\n\t\t\t\
    i -= i & -i;\n\t\t}\n\t\treturn s;\n\t}\n\n\tT find(int l, int r) { // [l, r)\n\
    \t\treturn sum(r - 1) - sum(l - 1);\n\t}\n};\n\nlong long inversion_number(const\
    \ vector<int> &v) {\n\tconst int n = v.size();\n\tBinaryIndexedTree<int> bit(n);\n\
    \tlong long res = 0;\n\tfor (int i = 0; i < n; ++i) {\n\t\tres += i - bit.sum(v[i]);\n\
    \t\tbit.add(v[i], 1);\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/binary_indexed_tree.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/binary_indexed_tree/alds1_5_d.test.cpp
documentation_of: src/datastructure/binary_indexed_tree.cpp
layout: document
redirect_from:
- /library/src/datastructure/binary_indexed_tree.cpp
- /library/src/datastructure/binary_indexed_tree.cpp.html
title: src/datastructure/binary_indexed_tree.cpp
---
