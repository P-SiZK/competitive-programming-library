---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/flow/primal_dual/aoj_grl_6_b.test.cpp
    title: test/flow/primal_dual/aoj_grl_6_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/flow/primal_dual.hpp\"\n\n\n\n#include <limits>\n#include\
    \ <queue>\n#include <algorithm>\n#include <vector>\n\ntemplate<class T, class\
    \ E>\nclass PrimalDual {\nprivate:\n\tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\
    \t\tE cost;\n\n\t\tEdge(int to, T cap, E cost, int rev) : to(to), rev(rev), cap(cap),\
    \ cost(cost) {}\n\t};\n\n\tstatic constexpr E INF = std::numeric_limits<E>::max();\n\
    \n\tstd::vector<std::vector<Edge>> g;\n\tstd::vector<E> h, dist;\n\tstd::vector<int>\
    \ prevv, preve;\n\npublic:\n\tPrimalDual(int n) : g(n), h(n), dist(n), prevv(n),\
    \ preve(n) {}\n\n\tvoid add_edge(int from, int to, T cap, E cost) {\n\t\tg[from].emplace_back(to,\
    \ cap, cost, g[to].size());\n\t\tg[to].emplace_back(from, 0, -cost, g[from].size()\
    \ - 1);\n\t}\n\n\tE min_cost_flow(int s, int t, T f) {\n\t\tE res = 0;\n\t\tstd::priority_queue<std::pair<E,\
    \ int>,\n\t\t\t\t\t\t\tstd::vector<std::pair<E, int>>,\n\t\t\t\t\t\t\tstd::greater<>>\n\
    \t\t\tpq;\n\n\t\twhile (f > 0) {\n\t\t\tdist.assign(g.size(), INF);\n\t\t\tpq.emplace(0,\
    \ s);\n\t\t\tdist[s] = 0;\n\t\t\twhile (!pq.empty()) {\n\t\t\t\tauto [now_dist,\
    \ now_v] = pq.top();\n\t\t\t\tpq.pop();\n\t\t\t\tif (dist[now_v] < now_dist) continue;\n\
    \t\t\t\tfor (int i = 0; i < (int)g[now_v].size(); ++i) {\n\t\t\t\t\tEdge &e =\
    \ g[now_v][i];\n\t\t\t\t\tE ncost = dist[now_v] + e.cost + h[now_v] - h[e.to];\n\
    \t\t\t\t\tif (e.cap > 0 && dist[e.to] > ncost) {\n\t\t\t\t\t\tdist[e.to] = ncost;\n\
    \t\t\t\t\t\tprevv[e.to] = now_v;\n\t\t\t\t\t\tpreve[e.to] = i;\n\t\t\t\t\t\tpq.emplace(dist[e.to],\
    \ e.to);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (dist[t] == INF) return -1;\n\
    \t\t\tfor (int v = 0; v < (int)h.size(); ++v)\n\t\t\t\tif (dist[v] < INF) h[v]\
    \ += dist[v];\n\t\t\tT d = f;\n\t\t\tfor (int v = t; v != s; v = prevv[v])\n\t\
    \t\t\td = std::min(d, g[prevv[v]][preve[v]].cap);\n\t\t\tf -= d;\n\t\t\tres +=\
    \ d * h[t];\n\t\t\tfor (int v = t; v != s; v = prevv[v]) {\n\t\t\t\tEdge &e =\
    \ g[prevv[v]][preve[v]];\n\t\t\t\te.cap -= d;\n\t\t\t\tg[v][e.rev].cap += d;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n\n"
  code: "#ifndef FLOW_PRIMAL_DUAL_HPP\n#define FLOW_PRIMAL_DUAL_HPP\n\n#include <limits>\n\
    #include <queue>\n#include <algorithm>\n#include <vector>\n\ntemplate<class T,\
    \ class E>\nclass PrimalDual {\nprivate:\n\tstruct Edge {\n\t\tint to, rev;\n\t\
    \tT cap;\n\t\tE cost;\n\n\t\tEdge(int to, T cap, E cost, int rev) : to(to), rev(rev),\
    \ cap(cap), cost(cost) {}\n\t};\n\n\tstatic constexpr E INF = std::numeric_limits<E>::max();\n\
    \n\tstd::vector<std::vector<Edge>> g;\n\tstd::vector<E> h, dist;\n\tstd::vector<int>\
    \ prevv, preve;\n\npublic:\n\tPrimalDual(int n) : g(n), h(n), dist(n), prevv(n),\
    \ preve(n) {}\n\n\tvoid add_edge(int from, int to, T cap, E cost) {\n\t\tg[from].emplace_back(to,\
    \ cap, cost, g[to].size());\n\t\tg[to].emplace_back(from, 0, -cost, g[from].size()\
    \ - 1);\n\t}\n\n\tE min_cost_flow(int s, int t, T f) {\n\t\tE res = 0;\n\t\tstd::priority_queue<std::pair<E,\
    \ int>,\n\t\t\t\t\t\t\tstd::vector<std::pair<E, int>>,\n\t\t\t\t\t\t\tstd::greater<>>\n\
    \t\t\tpq;\n\n\t\twhile (f > 0) {\n\t\t\tdist.assign(g.size(), INF);\n\t\t\tpq.emplace(0,\
    \ s);\n\t\t\tdist[s] = 0;\n\t\t\twhile (!pq.empty()) {\n\t\t\t\tauto [now_dist,\
    \ now_v] = pq.top();\n\t\t\t\tpq.pop();\n\t\t\t\tif (dist[now_v] < now_dist) continue;\n\
    \t\t\t\tfor (int i = 0; i < (int)g[now_v].size(); ++i) {\n\t\t\t\t\tEdge &e =\
    \ g[now_v][i];\n\t\t\t\t\tE ncost = dist[now_v] + e.cost + h[now_v] - h[e.to];\n\
    \t\t\t\t\tif (e.cap > 0 && dist[e.to] > ncost) {\n\t\t\t\t\t\tdist[e.to] = ncost;\n\
    \t\t\t\t\t\tprevv[e.to] = now_v;\n\t\t\t\t\t\tpreve[e.to] = i;\n\t\t\t\t\t\tpq.emplace(dist[e.to],\
    \ e.to);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (dist[t] == INF) return -1;\n\
    \t\t\tfor (int v = 0; v < (int)h.size(); ++v)\n\t\t\t\tif (dist[v] < INF) h[v]\
    \ += dist[v];\n\t\t\tT d = f;\n\t\t\tfor (int v = t; v != s; v = prevv[v])\n\t\
    \t\t\td = std::min(d, g[prevv[v]][preve[v]].cap);\n\t\t\tf -= d;\n\t\t\tres +=\
    \ d * h[t];\n\t\t\tfor (int v = t; v != s; v = prevv[v]) {\n\t\t\t\tEdge &e =\
    \ g[prevv[v]][preve[v]];\n\t\t\t\te.cap -= d;\n\t\t\t\tg[v][e.rev].cap += d;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n#endif // FLOW_PRIMAL_DUAL_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/primal_dual.hpp
  requiredBy: []
  timestamp: '2023-12-12 23:23:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/flow/primal_dual/aoj_grl_6_b.test.cpp
documentation_of: src/flow/primal_dual.hpp
layout: document
title: Primal-Dual
---
