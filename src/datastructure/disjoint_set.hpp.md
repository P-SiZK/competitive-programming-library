---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/kruskal.hpp
    title: Kruskal
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/disjoint_set/aoj_dsl_1_a.test.cpp
    title: test/datastructure/disjoint_set/aoj_dsl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal/aoj_grl_2_a.test.cpp
    title: test/graph/kruskal/aoj_grl_2_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructure/disjoint_set.hpp\"\n\n\n\n#include <vector>\n\
    \nclass DisjointSet {\nprivate:\n\tstd::vector<int> rank, size, p;\n\tint num\
    \ = 0;\n\npublic:\n\tDisjointSet(int n) : rank(n), size(n, 1), p(n), num(n) {\n\
    \t\tfor (int i = 0; i < n; i++) p[i] = i;\n\t}\n\n\tbool same(int x, int y) {\
    \ return root(x) == root(y); }\n\n\tvoid unite(int x, int y) {\n\t\tx = root(x),\
    \ y = root(y);\n\t\tif (x == y) return;\n\t\tnum--;\n\t\tif (rank[x] > rank[y])\
    \ {\n\t\t\tp[y] = x;\n\t\t\tsize[x] += size[y];\n\t\t} else {\n\t\t\tp[x] = y;\n\
    \t\t\tsize[y] += size[x];\n\t\t\tif (rank[x] == rank[y]) rank[y]++;\n\t\t}\n\t\
    }\n\n\tint root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }\n\n\tint\
    \ get_size(int x) { return size[root(x)]; }\n\n\t[[nodiscard]] int forest_size()\
    \ const { return num; }\n};\n\n\n"
  code: "#ifndef DATASTRUCTURE_DISJOINT_SET_HPP\n#define DATASTRUCTURE_DISJOINT_SET_HPP\n\
    \n#include <vector>\n\nclass DisjointSet {\nprivate:\n\tstd::vector<int> rank,\
    \ size, p;\n\tint num = 0;\n\npublic:\n\tDisjointSet(int n) : rank(n), size(n,\
    \ 1), p(n), num(n) {\n\t\tfor (int i = 0; i < n; i++) p[i] = i;\n\t}\n\n\tbool\
    \ same(int x, int y) { return root(x) == root(y); }\n\n\tvoid unite(int x, int\
    \ y) {\n\t\tx = root(x), y = root(y);\n\t\tif (x == y) return;\n\t\tnum--;\n\t\
    \tif (rank[x] > rank[y]) {\n\t\t\tp[y] = x;\n\t\t\tsize[x] += size[y];\n\t\t}\
    \ else {\n\t\t\tp[x] = y;\n\t\t\tsize[y] += size[x];\n\t\t\tif (rank[x] == rank[y])\
    \ rank[y]++;\n\t\t}\n\t}\n\n\tint root(int x) { return p[x] == x ? x : p[x] =\
    \ root(p[x]); }\n\n\tint get_size(int x) { return size[root(x)]; }\n\n\t[[nodiscard]]\
    \ int forest_size() const { return num; }\n};\n\n#endif // DATASTRUCTURE_DISJOINT_SET_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/disjoint_set.hpp
  requiredBy:
  - src/graph/kruskal.hpp
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/disjoint_set/aoj_dsl_1_a.test.cpp
  - test/graph/kruskal/aoj_grl_2_a.test.cpp
documentation_of: src/datastructure/disjoint_set.hpp
layout: document
title: Disjoint Set (Union-find)
---
