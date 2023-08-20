---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bellman_ford/grl_1_b.test.cpp
    title: test/graph/bellman_ford/grl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/bellman_ford.cpp\"\n#include <limits>\n#include\
    \ <vector>\n\nusing namespace std;\n\ntemplate<class T>\nstruct Edge {\n\tint\
    \ from, to;\n\tT cost;\n\n\tEdge(int from, int to, T cost) : from(from), to(to),\
    \ cost(cost) {}\n};\n\ntemplate<class T>\nvector<T> bellman_ford(int s, int V,\
    \ vector<Edge<T>> &G) {\n\tconst T INF = numeric_limits<T>::max();\n\tvector<T>\
    \ cost(V, INF);\n\tvector<int> prevr(V, -1); // \u7D4C\u8DEF\u5FA9\u5143\u7528\
    \n\tcost[s] = 0;\n\tfor (int i = 0; i < V; ++i) {\n\t\tfor (Edge<T> e : G) {\n\
    \t\t\tif (cost[e.from] == INF) continue;\n\t\t\tif (cost[e.to] > cost[e.from]\
    \ + e.cost) {\n\t\t\t\tcost[e.to] = cost[e.from] + e.cost;\n\t\t\t\tprevr[e.to]\
    \ = e.from;\n\t\t\t\tif (i == V - 1) return vector<T>();\n\t\t\t}\n\t\t}\n\t}\n\
    \treturn cost;\n}\n"
  code: "#include <limits>\n#include <vector>\n\nusing namespace std;\n\ntemplate<class\
    \ T>\nstruct Edge {\n\tint from, to;\n\tT cost;\n\n\tEdge(int from, int to, T\
    \ cost) : from(from), to(to), cost(cost) {}\n};\n\ntemplate<class T>\nvector<T>\
    \ bellman_ford(int s, int V, vector<Edge<T>> &G) {\n\tconst T INF = numeric_limits<T>::max();\n\
    \tvector<T> cost(V, INF);\n\tvector<int> prevr(V, -1); // \u7D4C\u8DEF\u5FA9\u5143\
    \u7528\n\tcost[s] = 0;\n\tfor (int i = 0; i < V; ++i) {\n\t\tfor (Edge<T> e :\
    \ G) {\n\t\t\tif (cost[e.from] == INF) continue;\n\t\t\tif (cost[e.to] > cost[e.from]\
    \ + e.cost) {\n\t\t\t\tcost[e.to] = cost[e.from] + e.cost;\n\t\t\t\tprevr[e.to]\
    \ = e.from;\n\t\t\t\tif (i == V - 1) return vector<T>();\n\t\t\t}\n\t\t}\n\t}\n\
    \treturn cost;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bellman_ford.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bellman_ford/grl_1_b.test.cpp
documentation_of: src/graph/bellman_ford.cpp
layout: document
redirect_from:
- /library/src/graph/bellman_ford.cpp
- /library/src/graph/bellman_ford.cpp.html
title: src/graph/bellman_ford.cpp
---
