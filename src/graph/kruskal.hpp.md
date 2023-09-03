---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/datastructure/disjoint_set.hpp
    title: Disjoint Set (Union-find)
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/kruskal/grl_2_a.test.cpp
    title: test/graph/kruskal/grl_2_a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/kruskal.hpp\"\n\n\n\n#line 1 \"src/datastructure/disjoint_set.hpp\"\
    \n\n\n\n#include <vector>\n\nclass DisjointSet {\nprivate:\n\tstd::vector<int>\
    \ rank, size, p;\n\tint num = 0;\n\npublic:\n\tDisjointSet(int n) : rank(n), size(n,\
    \ 1), p(n), num(n) {\n\t\tfor (int i = 0; i < n; i++) p[i] = i;\n\t}\n\n\tbool\
    \ same(int x, int y) { return root(x) == root(y); }\n\n\tvoid unite(int x, int\
    \ y) {\n\t\tx = root(x), y = root(y);\n\t\tif (x == y) return;\n\t\tnum--;\n\t\
    \tif (rank[x] > rank[y]) {\n\t\t\tp[y] = x;\n\t\t\tsize[x] += size[y];\n\t\t}\
    \ else {\n\t\t\tp[x] = y;\n\t\t\tsize[y] += size[x];\n\t\t\tif (rank[x] == rank[y])\
    \ rank[y]++;\n\t\t}\n\t}\n\n\tint root(int x) { return p[x] == x ? x : p[x] =\
    \ root(p[x]); }\n\n\tint get_size(int x) { return size[root(x)]; }\n\n\t[[nodiscard]]\
    \ int forest_size() const { return num; }\n};\n\n\n#line 5 \"src/graph/kruskal.hpp\"\
    \n\n#include <algorithm>\n#line 8 \"src/graph/kruskal.hpp\"\n\ntemplate<class\
    \ T>\nclass Kruskal {\nprivate:\n\tstruct Edge {\n\t\tint from, to;\n\t\tT cost;\n\
    \n\t\tEdge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n\n\t\
    \tbool operator<(Edge const &a) { return cost < a.cost; }\n\t};\n\n\tint n;\n\t\
    std::vector<Edge> g;\n\npublic:\n\tKruskal(int n) : n(n) {}\n\n\tvoid add_edge(int\
    \ from, int to, T cost) { g.emplace_back(from, to, cost); }\n\n\tT mst_cost()\
    \ {\n\t\tT cost = 0;\n\t\tstd::sort(g.begin(), g.end());\n\t\tDisjointSet ds(n);\n\
    \t\tcost = 0;\n\t\tfor (Edge const &e : g) {\n\t\t\tif (!ds.same(e.from, e.to))\
    \ {\n\t\t\t\tcost += e.cost;\n\t\t\t\tds.unite(e.from, e.to);\n\t\t\t}\n\t\t}\n\
    \t\treturn cost;\n\t}\n};\n\n\n"
  code: "#ifndef GRAPH_KRUSKAL_HPP\n#define GRAPH_KRUSKAL_HPP\n\n#include \"src/datastructure/disjoint_set.hpp\"\
    \n\n#include <algorithm>\n#include <vector>\n\ntemplate<class T>\nclass Kruskal\
    \ {\nprivate:\n\tstruct Edge {\n\t\tint from, to;\n\t\tT cost;\n\n\t\tEdge(int\
    \ from, int to, T cost) : from(from), to(to), cost(cost) {}\n\n\t\tbool operator<(Edge\
    \ const &a) { return cost < a.cost; }\n\t};\n\n\tint n;\n\tstd::vector<Edge> g;\n\
    \npublic:\n\tKruskal(int n) : n(n) {}\n\n\tvoid add_edge(int from, int to, T cost)\
    \ { g.emplace_back(from, to, cost); }\n\n\tT mst_cost() {\n\t\tT cost = 0;\n\t\
    \tstd::sort(g.begin(), g.end());\n\t\tDisjointSet ds(n);\n\t\tcost = 0;\n\t\t\
    for (Edge const &e : g) {\n\t\t\tif (!ds.same(e.from, e.to)) {\n\t\t\t\tcost +=\
    \ e.cost;\n\t\t\t\tds.unite(e.from, e.to);\n\t\t\t}\n\t\t}\n\t\treturn cost;\n\
    \t}\n};\n\n#endif // GRAPH_KRUSKAL_HPP\n"
  dependsOn:
  - src/datastructure/disjoint_set.hpp
  isVerificationFile: false
  path: src/graph/kruskal.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/kruskal/grl_2_a.test.cpp
documentation_of: src/graph/kruskal.hpp
layout: document
title: Kruskal
---
