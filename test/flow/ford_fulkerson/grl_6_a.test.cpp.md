---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/flow/ford_fulkerson.cpp
    title: src/flow/ford_fulkerson.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/flow/ford_fulkerson/grl_6_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\n\n\
    #line 1 \"src/flow/ford_fulkerson.cpp\"\n#include <limits>\n#include <vector>\n\
    \nusing namespace std;\n\ntemplate<class T>\nstruct FordFulkerson {\n\tstruct\
    \ Edge {\n\t\tint to, rev;\n\t\tT cap;\n\n\t\tEdge(int to, T cap, int rev) : to(to),\
    \ cap(cap), rev(rev) {}\n\t};\n\n\tconst T INF = numeric_limits<T>::max();\n\n\
    \tvector<vector<Edge>> G;\n\tvector<int> used;\n\n\tFordFulkerson(int n) : G(n),\
    \ used(n) {}\n\n\tvoid add_edge(int from, int to, T cap, bool directed = true)\
    \ {\n\t\tG[from].emplace_back(to, cap, G[to].size());\n\t\tG[to].emplace_back(from,\
    \ (directed ? 0 : cap), G[from].size() - 1);\n\t}\n\n\tT dfs(int v, int t, T f)\
    \ {\n\t\tif (v == t) return f;\n\t\tused[v] = true;\n\t\tfor (auto &e : G[v])\
    \ {\n\t\t\tif (!used[e.to] && e.cap > 0) {\n\t\t\t\tT d = dfs(e.to, t, min(f,\
    \ e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap\
    \ += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\
    \tT max_flow(int s, int t) {\n\t\tT flow = 0;\n\t\twhile (true) {\n\t\t\tfill(used.begin(),\
    \ used.end(), 0);\n\t\t\tT f = dfs(s, t, INF);\n\t\t\tif (f == 0) break;\n\t\t\
    \tflow += f;\n\t\t}\n\t\treturn flow;\n\t}\n};\n#line 4 \"test/flow/ford_fulkerson/grl_6_a.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tint V, E;\n\tcin >> V >> E;\n\tFordFulkerson<int>\
    \ G(V);\n\tfor (int i = 0; i < E; ++i) {\n\t\tint u, v, c;\n\t\tcin >> u >> v\
    \ >> c;\n\t\tG.add_edge(u, v, c);\n\t}\n\tcout << G.max_flow(0, V - 1) << endl;\n\
    \n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\n\
    \n#include \"src/flow/ford_fulkerson.cpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n\tint V, E;\n\tcin >> V >> E;\n\tFordFulkerson<int> G(V);\n\tfor (int i =\
    \ 0; i < E; ++i) {\n\t\tint u, v, c;\n\t\tcin >> u >> v >> c;\n\t\tG.add_edge(u,\
    \ v, c);\n\t}\n\tcout << G.max_flow(0, V - 1) << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/flow/ford_fulkerson.cpp
  isVerificationFile: true
  path: test/flow/ford_fulkerson/grl_6_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/flow/ford_fulkerson/grl_6_a.test.cpp
layout: document
redirect_from:
- /verify/test/flow/ford_fulkerson/grl_6_a.test.cpp
- /verify/test/flow/ford_fulkerson/grl_6_a.test.cpp.html
title: test/flow/ford_fulkerson/grl_6_a.test.cpp
---
