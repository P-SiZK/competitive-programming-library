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
    \ <vector>\n\nusing namespace std;\n\nclass DisjointSet {\nprivate:\n\tvector<int>\
    \ rank, p;\n\npublic:\n\tDisjointSet(int n) {\n\t\trank.assign(n, 0);\n\t\tp.assign(n,\
    \ 0);\n\t\tfor (int i = 0; i < n; i++) p[i] = i;\n\t}\n\n\tbool same(int x, int\
    \ y) { return root(x) == root(y); }\n\n\tvoid unite(int x, int y) {\n\t\tx = root(x),\
    \ y = root(y);\n\t\tif (x == y) return;\n\t\tif (rank[x] > rank[y]) {\n\t\t\t\
    p[y] = x;\n\t\t} else {\n\t\t\tp[x] = y;\n\t\t\tif (rank[x] == rank[y]) rank[y]++;\n\
    \t\t}\n\t}\n\n\tint root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }\n\
    };\n\ntemplate<class T>\nclass Kruskal {\nprivate:\n\tstruct Edge {\n\t\tint from,\
    \ to;\n\t\tT cost;\n\n\t\tEdge(int from, int to, T cost) : from(from), to(to),\
    \ cost(cost) {}\n\n\t\tbool operator<(Edge const &a) { return cost < a.cost; }\n\
    \t};\n\n\tint n;\n\tvector<Edge> g;\n\npublic:\n\tKruskal(int n) : n(n) {}\n\n\
    \tvoid add_edge(int from, int to, T cost) { g.emplace_back(from, to, cost); }\n\
    \n\tT mst_cost() {\n\t\tT cost = 0;\n\t\tsort(g.begin(), g.end());\n\t\tDisjointSet\
    \ ds(n);\n\t\tcost = 0;\n\t\tfor (Edge const &e : g) {\n\t\t\tif (!ds.same(e.from,\
    \ e.to)) {\n\t\t\t\tcost += e.cost;\n\t\t\t\tds.unite(e.from, e.to);\n\t\t\t}\n\
    \t\t}\n\t\treturn cost;\n\t}\n};\n"
  code: "#include <algorithm>\n#include <vector>\n\nusing namespace std;\n\nclass\
    \ DisjointSet {\nprivate:\n\tvector<int> rank, p;\n\npublic:\n\tDisjointSet(int\
    \ n) {\n\t\trank.assign(n, 0);\n\t\tp.assign(n, 0);\n\t\tfor (int i = 0; i < n;\
    \ i++) p[i] = i;\n\t}\n\n\tbool same(int x, int y) { return root(x) == root(y);\
    \ }\n\n\tvoid unite(int x, int y) {\n\t\tx = root(x), y = root(y);\n\t\tif (x\
    \ == y) return;\n\t\tif (rank[x] > rank[y]) {\n\t\t\tp[y] = x;\n\t\t} else {\n\
    \t\t\tp[x] = y;\n\t\t\tif (rank[x] == rank[y]) rank[y]++;\n\t\t}\n\t}\n\n\tint\
    \ root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }\n};\n\ntemplate<class\
    \ T>\nclass Kruskal {\nprivate:\n\tstruct Edge {\n\t\tint from, to;\n\t\tT cost;\n\
    \n\t\tEdge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n\n\t\
    \tbool operator<(Edge const &a) { return cost < a.cost; }\n\t};\n\n\tint n;\n\t\
    vector<Edge> g;\n\npublic:\n\tKruskal(int n) : n(n) {}\n\n\tvoid add_edge(int\
    \ from, int to, T cost) { g.emplace_back(from, to, cost); }\n\n\tT mst_cost()\
    \ {\n\t\tT cost = 0;\n\t\tsort(g.begin(), g.end());\n\t\tDisjointSet ds(n);\n\t\
    \tcost = 0;\n\t\tfor (Edge const &e : g) {\n\t\t\tif (!ds.same(e.from, e.to))\
    \ {\n\t\t\t\tcost += e.cost;\n\t\t\t\tds.unite(e.from, e.to);\n\t\t\t}\n\t\t}\n\
    \t\treturn cost;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/kruskal.hpp
  requiredBy: []
  timestamp: '2023-08-31 00:25:14+09:00'
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
