---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/datastructure/disjoint_set/dsl_1_a.test.cpp
    title: test/datastructure/disjoint_set/dsl_1_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructure/disjoint_set.cpp\"\n#include <vector>\n\
    \nusing namespace std;\n\nclass DisjointSet {\nprivate:\n\tvector<int> rank, size,\
    \ p;\n\tint num = 0;\n\npublic:\n\tDisjointSet(int n) {\n\t\tnum = n;\n\t\trank.assign(n,\
    \ 0);\n\t\tsize.assign(n, 1);\n\t\tp.assign(n, 0);\n\t\tfor (int i = 0; i < n;\
    \ i++) p[i] = i;\n\t}\n\n\tbool same(int x, int y) { return root(x) == root(y);\
    \ }\n\n\tvoid unite(int x, int y) {\n\t\tx = root(x), y = root(y);\n\t\tif (x\
    \ == y) return;\n\t\tnum--;\n\t\tif (rank[x] > rank[y]) {\n\t\t\tp[y] = x;\n\t\
    \t\tsize[x] += size[y];\n\t\t} else {\n\t\t\tp[x] = y;\n\t\t\tsize[y] += size[x];\n\
    \t\t\tif (rank[x] == rank[y]) rank[y]++;\n\t\t}\n\t}\n\n\tint root(int x) { return\
    \ p[x] == x ? x : p[x] = root(p[x]); }\n\n\tint get_size(int x) { return size[root(x)];\
    \ }\n\n\tint forest_size() { return num; }\n};\n"
  code: "#include <vector>\n\nusing namespace std;\n\nclass DisjointSet {\nprivate:\n\
    \tvector<int> rank, size, p;\n\tint num = 0;\n\npublic:\n\tDisjointSet(int n)\
    \ {\n\t\tnum = n;\n\t\trank.assign(n, 0);\n\t\tsize.assign(n, 1);\n\t\tp.assign(n,\
    \ 0);\n\t\tfor (int i = 0; i < n; i++) p[i] = i;\n\t}\n\n\tbool same(int x, int\
    \ y) { return root(x) == root(y); }\n\n\tvoid unite(int x, int y) {\n\t\tx = root(x),\
    \ y = root(y);\n\t\tif (x == y) return;\n\t\tnum--;\n\t\tif (rank[x] > rank[y])\
    \ {\n\t\t\tp[y] = x;\n\t\t\tsize[x] += size[y];\n\t\t} else {\n\t\t\tp[x] = y;\n\
    \t\t\tsize[y] += size[x];\n\t\t\tif (rank[x] == rank[y]) rank[y]++;\n\t\t}\n\t\
    }\n\n\tint root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }\n\n\tint\
    \ get_size(int x) { return size[root(x)]; }\n\n\tint forest_size() { return num;\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/disjoint_set.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/datastructure/disjoint_set/dsl_1_a.test.cpp
documentation_of: src/datastructure/disjoint_set.cpp
layout: document
redirect_from:
- /library/src/datastructure/disjoint_set.cpp
- /library/src/datastructure/disjoint_set.cpp.html
title: src/datastructure/disjoint_set.cpp
---
