---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/flow/ford_fulkerson/grl_6_a.test.cpp
    title: test/flow/ford_fulkerson/grl_6_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/flow/ford_fulkerson.cpp\"\n#include <limits>\n#include\
    \ <vector>\n\nusing namespace std;\n\ntemplate<class T>\nstruct FordFulkerson\
    \ {\n\tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\n\t\tEdge(int to, T cap,\
    \ int rev) : to(to), cap(cap), rev(rev) {}\n\t};\n\n\tconst T INF = numeric_limits<T>::max();\n\
    \n\tvector<vector<Edge>> G;\n\tvector<int> used;\n\n\tFordFulkerson(int n) : G(n),\
    \ used(n) {}\n\n\tvoid add_edge(int from, int to, T cap, bool directed = true)\
    \ {\n\t\tG[from].emplace_back(to, cap, G[to].size());\n\t\tG[to].emplace_back(from,\
    \ (directed ? 0 : cap), G[from].size() - 1);\n\t}\n\n\tT dfs(int v, int t, T f)\
    \ {\n\t\tif (v == t) return f;\n\t\tused[v] = true;\n\t\tfor (auto &e : G[v])\
    \ {\n\t\t\tif (!used[e.to] && e.cap > 0) {\n\t\t\t\tT d = dfs(e.to, t, min(f,\
    \ e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap\
    \ += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\
    \tT max_flow(int s, int t) {\n\t\tT flow = 0;\n\t\twhile (true) {\n\t\t\tfill(used.begin(),\
    \ used.end(), 0);\n\t\t\tT f = dfs(s, t, INF);\n\t\t\tif (f == 0) break;\n\t\t\
    \tflow += f;\n\t\t}\n\t\treturn flow;\n\t}\n};\n"
  code: "#include <limits>\n#include <vector>\n\nusing namespace std;\n\ntemplate<class\
    \ T>\nstruct FordFulkerson {\n\tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\n\
    \t\tEdge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}\n\t};\n\n\tconst\
    \ T INF = numeric_limits<T>::max();\n\n\tvector<vector<Edge>> G;\n\tvector<int>\
    \ used;\n\n\tFordFulkerson(int n) : G(n), used(n) {}\n\n\tvoid add_edge(int from,\
    \ int to, T cap, bool directed = true) {\n\t\tG[from].emplace_back(to, cap, G[to].size());\n\
    \t\tG[to].emplace_back(from, (directed ? 0 : cap), G[from].size() - 1);\n\t}\n\
    \n\tT dfs(int v, int t, T f) {\n\t\tif (v == t) return f;\n\t\tused[v] = true;\n\
    \t\tfor (auto &e : G[v]) {\n\t\t\tif (!used[e.to] && e.cap > 0) {\n\t\t\t\tT d\
    \ = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\
    \t\t\t\t\tG[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t}\n\t\treturn 0;\n\t}\n\n\tT max_flow(int s, int t) {\n\t\tT flow = 0;\n\t\t\
    while (true) {\n\t\t\tfill(used.begin(), used.end(), 0);\n\t\t\tT f = dfs(s, t,\
    \ INF);\n\t\t\tif (f == 0) break;\n\t\t\tflow += f;\n\t\t}\n\t\treturn flow;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/ford_fulkerson.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/flow/ford_fulkerson/grl_6_a.test.cpp
documentation_of: src/flow/ford_fulkerson.cpp
layout: document
redirect_from:
- /library/src/flow/ford_fulkerson.cpp
- /library/src/flow/ford_fulkerson.cpp.html
title: src/flow/ford_fulkerson.cpp
---
