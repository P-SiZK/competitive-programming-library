---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/flow/primal_dual.cpp
    title: src/flow/primal_dual.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"test/flow/primal_dual/grl_6_b.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\n\n\
    #line 1 \"src/flow/primal_dual.cpp\"\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n\nusing namespace std;\n\ntemplate<class T, class E>\nstruct PrimalDual\
    \ {\n\tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\t\tE cost;\n\n\t\tEdge(int\
    \ to, T cap, E cost, int rev) :\n\t\t\tto(to), rev(rev), cap(cap), cost(cost)\
    \ {}\n\t};\n\n\tconst E INF = numeric_limits<E>::max();\n\tvector<vector<Edge>>\
    \ G;\n\tvector<E> h, dist;\n\tvector<int> prevv, preve;\n\n\tPrimalDual(int n)\
    \ : G(n), h(n), dist(n), prevv(n), preve(n) {}\n\n\tvoid add_edge(int from, int\
    \ to, T cap, E cost) {\n\t\tG[from].emplace_back(to, cap, cost, G[to].size());\n\
    \t\tG[to].emplace_back(from, 0, -cost, G[from].size() - 1);\n\t}\n\n\tE min_cost_flow(int\
    \ s, int t, T f) {\n\t\tE res = 0;\n\t\tpriority_queue<pair<E, int>, vector<pair<E,\
    \ int>>, greater<>> pq;\n\n\t\twhile (f > 0) {\n\t\t\tfill(dist.begin(), dist.end(),\
    \ INF);\n\t\t\tpq.emplace(0, s);\n\t\t\tdist[s] = 0;\n\t\t\twhile (!pq.empty())\
    \ {\n\t\t\t\tpair<E, int> p = pq.top();\n\t\t\t\tpq.pop();\n\t\t\t\tif (dist[p.second]\
    \ < p.first) continue;\n\t\t\t\tfor (int i = 0; i < (int)G[p.second].size(); ++i)\
    \ {\n\t\t\t\t\tEdge &e = G[p.second][i];\n\t\t\t\t\tE ncost = dist[p.second] +\
    \ e.cost + h[p.second] - h[e.to];\n\t\t\t\t\tif (e.cap > 0 && dist[e.to] > ncost)\
    \ {\n\t\t\t\t\t\tdist[e.to] = ncost;\n\t\t\t\t\t\tprevv[e.to] = p.second;\n\t\t\
    \t\t\t\tpreve[e.to] = i;\n\t\t\t\t\t\tpq.emplace(dist[e.to], e.to);\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (dist[t] == INF) return -1;\n\t\t\tfor (int v\
    \ = 0; v < (int)h.size(); ++v)\n\t\t\t\tif (dist[v] < INF) h[v] += dist[v];\n\t\
    \t\tT d = f;\n\t\t\tfor (int v = t; v != s; v = prevv[v])\n\t\t\t\td = min(d,\
    \ G[prevv[v]][preve[v]].cap);\n\t\t\tf -= d;\n\t\t\tres += d * h[t];\n\t\t\tfor\
    \ (int v = t; v != s; v = prevv[v]) {\n\t\t\t\tEdge &e = G[prevv[v]][preve[v]];\n\
    \t\t\t\te.cap -= d;\n\t\t\t\tG[v][e.rev].cap += d;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ res;\n\t}\n};\n#line 4 \"test/flow/primal_dual/grl_6_b.test.cpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n\tint V, E, F;\n\tcin >> V >> E >> F;\n\tPrimalDual<int,\
    \ int> G(V);\n\tfor (int i = 0; i < E; ++i) {\n\t\tint u, v, c, d;\n\t\tcin >>\
    \ u >> v >> c >> d;\n\t\tG.add_edge(u, v, c, d);\n\t}\n\tcout << G.min_cost_flow(0,\
    \ V - 1, F) << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\n\
    \n#include \"src/flow/primal_dual.cpp\"\n\n#include <iostream>\n\nint main() {\n\
    \tint V, E, F;\n\tcin >> V >> E >> F;\n\tPrimalDual<int, int> G(V);\n\tfor (int\
    \ i = 0; i < E; ++i) {\n\t\tint u, v, c, d;\n\t\tcin >> u >> v >> c >> d;\n\t\t\
    G.add_edge(u, v, c, d);\n\t}\n\tcout << G.min_cost_flow(0, V - 1, F) << endl;\n\
    \n\treturn 0;\n}\n"
  dependsOn:
  - src/flow/primal_dual.cpp
  isVerificationFile: true
  path: test/flow/primal_dual/grl_6_b.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 13:03:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/flow/primal_dual/grl_6_b.test.cpp
layout: document
redirect_from:
- /verify/test/flow/primal_dual/grl_6_b.test.cpp
- /verify/test/flow/primal_dual/grl_6_b.test.cpp.html
title: test/flow/primal_dual/grl_6_b.test.cpp
---
