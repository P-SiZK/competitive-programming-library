---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal/grl_2_a.test.cpp
    title: test/graph/kruskal/grl_2_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/kruskal.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\nusing namespace std;\n\ntemplate<class T>\nstruct Edge {\n\tint\
    \ from, to;\n\tT cost;\n\n\tEdge(int from, int to, T cost) : from(from), to(to),\
    \ cost(cost) {}\n};\n\ntemplate<class T>\nbool cmp(Edge<T> const &a, Edge<T> const\
    \ &b) {\n\treturn a.cost < b.cost;\n}\n\nclass DisjointSet {\nprivate:\n\tvector<int>\
    \ rank, p;\n\npublic:\n\tDisjointSet(int n) {\n\t\trank.assign(n, 0);\n\t\tp.assign(n,\
    \ 0);\n\t\tfor (int i = 0; i < n; i++) p[i] = i;\n\t}\n\n\tbool same(int x, int\
    \ y) { return root(x) == root(y); }\n\n\tvoid unite(int x, int y) {\n\t\tx = root(x),\
    \ y = root(y);\n\t\tif (x == y) return;\n\t\tif (rank[x] > rank[y]) {\n\t\t\t\
    p[y] = x;\n\t\t} else {\n\t\t\tp[x] = y;\n\t\t\tif (rank[x] == rank[y]) rank[y]++;\n\
    \t\t}\n\t}\n\n\tint root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }\n\
    };\n\ntemplate<class T>\nT kruskal(int v, vector<Edge<T>> &g) {\n\tsort(g.begin(),\
    \ g.end(), cmp<T>);\n\tDisjointSet ds(v);\n\tT cost = 0;\n\tfor (Edge<T> e : g)\
    \ {\n\t\tif (!ds.same(e.from, e.to)) {\n\t\t\tcost += e.cost;\n\t\t\tds.unite(e.from,\
    \ e.to);\n\t\t}\n\t}\n\treturn cost;\n}\n"
  code: "#include <algorithm>\n#include <vector>\n\nusing namespace std;\n\ntemplate<class\
    \ T>\nstruct Edge {\n\tint from, to;\n\tT cost;\n\n\tEdge(int from, int to, T\
    \ cost) : from(from), to(to), cost(cost) {}\n};\n\ntemplate<class T>\nbool cmp(Edge<T>\
    \ const &a, Edge<T> const &b) {\n\treturn a.cost < b.cost;\n}\n\nclass DisjointSet\
    \ {\nprivate:\n\tvector<int> rank, p;\n\npublic:\n\tDisjointSet(int n) {\n\t\t\
    rank.assign(n, 0);\n\t\tp.assign(n, 0);\n\t\tfor (int i = 0; i < n; i++) p[i]\
    \ = i;\n\t}\n\n\tbool same(int x, int y) { return root(x) == root(y); }\n\n\t\
    void unite(int x, int y) {\n\t\tx = root(x), y = root(y);\n\t\tif (x == y) return;\n\
    \t\tif (rank[x] > rank[y]) {\n\t\t\tp[y] = x;\n\t\t} else {\n\t\t\tp[x] = y;\n\
    \t\t\tif (rank[x] == rank[y]) rank[y]++;\n\t\t}\n\t}\n\n\tint root(int x) { return\
    \ p[x] == x ? x : p[x] = root(p[x]); }\n};\n\ntemplate<class T>\nT kruskal(int\
    \ v, vector<Edge<T>> &g) {\n\tsort(g.begin(), g.end(), cmp<T>);\n\tDisjointSet\
    \ ds(v);\n\tT cost = 0;\n\tfor (Edge<T> e : g) {\n\t\tif (!ds.same(e.from, e.to))\
    \ {\n\t\t\tcost += e.cost;\n\t\t\tds.unite(e.from, e.to);\n\t\t}\n\t}\n\treturn\
    \ cost;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/kruskal.hpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/kruskal/grl_2_a.test.cpp
documentation_of: src/graph/kruskal.hpp
layout: document
redirect_from:
- /library/src/graph/kruskal.hpp
- /library/src/graph/kruskal.hpp.html
title: src/graph/kruskal.hpp
---
