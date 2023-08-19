---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/kruskal.cpp
    title: src/graph/kruskal.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/graph/kruskal/grl_2_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\n\
    #line 1 \"src/graph/kruskal.cpp\"\n#include <algorithm>\n#include <vector>\n\n\
    using namespace std;\n\ntemplate<class T>\nstruct Edge {\n\tint from, to;\n\t\
    T cost;\n\n\tEdge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n\
    };\n\ntemplate<class T>\nbool cmp(const Edge<T> &a, const Edge<T> &b) {\n\treturn\
    \ a.cost < b.cost;\n}\n\nclass DisjointSet {\nprivate:\n\tvector<int> rank, p;\n\
    \npublic:\n\tDisjointSet(int n) {\n\t\trank.assign(n, 0);\n\t\tp.assign(n, 0);\n\
    \t\tfor (int i = 0; i < n; i++) p[i] = i;\n\t}\n\n\tbool same(int x, int y) {\
    \ return root(x) == root(y); }\n\n\tvoid unite(int x, int y) {\n\t\tx = root(x),\
    \ y = root(y);\n\t\tif (x == y) return;\n\t\tif (rank[x] > rank[y]) {\n\t\t\t\
    p[y] = x;\n\t\t} else {\n\t\t\tp[x] = y;\n\t\t\tif (rank[x] == rank[y]) rank[y]++;\n\
    \t\t}\n\t}\n\n\tint root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }\n\
    };\n\ntemplate<class T>\nT kruskal(int V, vector<Edge<T>> &G) {\n\tsort(G.begin(),\
    \ G.end(), cmp<T>);\n\tDisjointSet ds(V);\n\tT cost = 0;\n\tfor (Edge<T> e : G)\
    \ {\n\t\tif (!ds.same(e.from, e.to)) {\n\t\t\tcost += e.cost;\n\t\t\tds.unite(e.from,\
    \ e.to);\n\t\t}\n\t}\n\treturn cost;\n}\n#line 4 \"test/graph/kruskal/grl_2_a.test.cpp\"\
    \n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tint V, E;\n\
    \tcin >> V >> E;\n\tvector<Edge<int>> G;\n\tfor (int i = 0; i < E; ++i) {\n\t\t\
    int a, b, c;\n\t\tcin >> a >> b >> c;\n\t\tG.emplace_back(a, b, c);\n\t}\n\tcout\
    \ << kruskal(V, G) << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\
    \n#include \"src/graph/kruskal.cpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n\tint V, E;\n\tcin >> V >> E;\n\tvector<Edge<int>> G;\n\
    \tfor (int i = 0; i < E; ++i) {\n\t\tint a, b, c;\n\t\tcin >> a >> b >> c;\n\t\
    \tG.emplace_back(a, b, c);\n\t}\n\tcout << kruskal(V, G) << endl;\n\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - src/graph/kruskal.cpp
  isVerificationFile: true
  path: test/graph/kruskal/grl_2_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/kruskal/grl_2_a.test.cpp
layout: document
redirect_from:
- /verify/test/graph/kruskal/grl_2_a.test.cpp
- /verify/test/graph/kruskal/grl_2_a.test.cpp.html
title: test/graph/kruskal/grl_2_a.test.cpp
---
