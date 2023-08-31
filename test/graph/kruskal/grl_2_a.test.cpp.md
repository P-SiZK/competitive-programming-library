---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/kruskal.hpp
    title: src/graph/kruskal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/graph/kruskal/grl_2_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\n\
    #line 1 \"src/graph/kruskal.hpp\"\n#include <algorithm>\n#include <vector>\n\n\
    class DisjointSet {\nprivate:\n\tstd::vector<int> rank, p;\n\npublic:\n\tDisjointSet(int\
    \ n) : rank(n), p(n) {\n\t\tfor (int i = 0; i < n; i++) p[i] = i;\n\t}\n\n\tbool\
    \ same(int x, int y) { return root(x) == root(y); }\n\n\tvoid unite(int x, int\
    \ y) {\n\t\tx = root(x), y = root(y);\n\t\tif (x == y) return;\n\t\tif (rank[x]\
    \ > rank[y]) {\n\t\t\tp[y] = x;\n\t\t} else {\n\t\t\tp[x] = y;\n\t\t\tif (rank[x]\
    \ == rank[y]) rank[y]++;\n\t\t}\n\t}\n\n\tint root(int x) { return p[x] == x ?\
    \ x : p[x] = root(p[x]); }\n};\n\ntemplate<class T>\nclass Kruskal {\nprivate:\n\
    \tstruct Edge {\n\t\tint from, to;\n\t\tT cost;\n\n\t\tEdge(int from, int to,\
    \ T cost) : from(from), to(to), cost(cost) {}\n\n\t\tbool operator<(Edge const\
    \ &a) { return cost < a.cost; }\n\t};\n\n\tint n;\n\tstd::vector<Edge> g;\n\n\
    public:\n\tKruskal(int n) : n(n) {}\n\n\tvoid add_edge(int from, int to, T cost)\
    \ { g.emplace_back(from, to, cost); }\n\n\tT mst_cost() {\n\t\tT cost = 0;\n\t\
    \tstd::sort(g.begin(), g.end());\n\t\tDisjointSet ds(n);\n\t\tcost = 0;\n\t\t\
    for (Edge const &e : g) {\n\t\t\tif (!ds.same(e.from, e.to)) {\n\t\t\t\tcost +=\
    \ e.cost;\n\t\t\t\tds.unite(e.from, e.to);\n\t\t\t}\n\t\t}\n\t\treturn cost;\n\
    \t}\n};\n#line 4 \"test/graph/kruskal/grl_2_a.test.cpp\"\n\n#include <iostream>\n\
    \nusing namespace std;\n\nint main() {\n\tint v, e;\n\tcin >> v >> e;\n\tKruskal<int>\
    \ k(v);\n\tfor (int i = 0; i < e; ++i) {\n\t\tint a, b, c;\n\t\tcin >> a >> b\
    \ >> c;\n\t\tk.add_edge(a, b, c);\n\t}\n\tcout << k.mst_cost() << endl;\n\n\t\
    return 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\
    \n#include \"src/graph/kruskal.hpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n\tint v, e;\n\tcin >> v >> e;\n\tKruskal<int> k(v);\n\t\
    for (int i = 0; i < e; ++i) {\n\t\tint a, b, c;\n\t\tcin >> a >> b >> c;\n\t\t\
    k.add_edge(a, b, c);\n\t}\n\tcout << k.mst_cost() << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/graph/kruskal.hpp
  isVerificationFile: true
  path: test/graph/kruskal/grl_2_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 13:01:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/kruskal/grl_2_a.test.cpp
layout: document
redirect_from:
- /verify/test/graph/kruskal/grl_2_a.test.cpp
- /verify/test/graph/kruskal/grl_2_a.test.cpp.html
title: test/graph/kruskal/grl_2_a.test.cpp
---
