---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bellman_ford/aoj_grl_1_b.test.cpp
    title: test/graph/bellman_ford/aoj_grl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/bellman_ford.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <limits>\n#include <vector>\n\ntemplate<class T>\nclass BellmanFord {\n\
    private:\n\tstruct Edge {\n\t\tint from, to;\n\t\tT cost;\n\n\t\tEdge(int from,\
    \ int to, T cost) : from(from), to(to), cost(cost) {}\n\t};\n\n\tstatic constexpr\
    \ T INF = std::numeric_limits<T>::max();\n\n\tint n, s{};\n\tstd::vector<Edge>\
    \ g;\n\tstd::vector<T> cost;\n\tstd::vector<int> prevv;\n\tbool negative_cycle_flag{};\n\
    \npublic:\n\tBellmanFord(int n) : n(n), cost(n), prevv(n) {}\n\n\tvoid add_edge(int\
    \ from, int to, T cost) { g.emplace_back(from, to, cost); }\n\n\tvoid build(int\
    \ from) {\n\t\ts = from;\n\t\tcost.assign(n, INF);\n\t\tprevv.assign(n, -1);\n\
    \t\tcost[s] = 0;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tfor (Edge &e : g) {\n\
    \t\t\t\tif (cost[e.from] == INF) continue;\n\t\t\t\tif (cost[e.to] > cost[e.from]\
    \ + e.cost) {\n\t\t\t\t\tcost[e.to] = cost[e.from] + e.cost;\n\t\t\t\t\tprevv[e.to]\
    \ = e.from;\n\t\t\t\t\tif (i == n - 1) {\n\t\t\t\t\t\tnegative_cycle_flag = true;\n\
    \t\t\t\t\t\treturn;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tT distance(int\
    \ to) { return cost[to]; }\n\n\tstd::vector<int> shortest_path(int to) {\n\t\t\
    std::vector<int> path;\n\t\tfor (int v = to; v != -1; v = prevv[v]) path.push_back(v);\n\
    \t\tstd::reverse(path.begin(), path.end());\n\t\treturn path;\n\t}\n\n\tbool is_unreachable(int\
    \ to) { return cost[to] == INF; }\n\n\tbool has_negative_cycle() { return negative_cycle_flag;\
    \ }\n};\n\n\n"
  code: "#ifndef GRAPH_BELLMAN_FORD_HPP\n#define GRAPH_BELLMAN_FORD_HPP\n\n#include\
    \ <algorithm>\n#include <limits>\n#include <vector>\n\ntemplate<class T>\nclass\
    \ BellmanFord {\nprivate:\n\tstruct Edge {\n\t\tint from, to;\n\t\tT cost;\n\n\
    \t\tEdge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n\t};\n\
    \n\tstatic constexpr T INF = std::numeric_limits<T>::max();\n\n\tint n, s{};\n\
    \tstd::vector<Edge> g;\n\tstd::vector<T> cost;\n\tstd::vector<int> prevv;\n\t\
    bool negative_cycle_flag{};\n\npublic:\n\tBellmanFord(int n) : n(n), cost(n),\
    \ prevv(n) {}\n\n\tvoid add_edge(int from, int to, T cost) { g.emplace_back(from,\
    \ to, cost); }\n\n\tvoid build(int from) {\n\t\ts = from;\n\t\tcost.assign(n,\
    \ INF);\n\t\tprevv.assign(n, -1);\n\t\tcost[s] = 0;\n\t\tfor (int i = 0; i < n;\
    \ ++i) {\n\t\t\tfor (Edge &e : g) {\n\t\t\t\tif (cost[e.from] == INF) continue;\n\
    \t\t\t\tif (cost[e.to] > cost[e.from] + e.cost) {\n\t\t\t\t\tcost[e.to] = cost[e.from]\
    \ + e.cost;\n\t\t\t\t\tprevv[e.to] = e.from;\n\t\t\t\t\tif (i == n - 1) {\n\t\t\
    \t\t\t\tnegative_cycle_flag = true;\n\t\t\t\t\t\treturn;\n\t\t\t\t\t}\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t}\n\n\tT distance(int to) { return cost[to]; }\n\n\tstd::vector<int>\
    \ shortest_path(int to) {\n\t\tstd::vector<int> path;\n\t\tfor (int v = to; v\
    \ != -1; v = prevv[v]) path.push_back(v);\n\t\tstd::reverse(path.begin(), path.end());\n\
    \t\treturn path;\n\t}\n\n\tbool is_unreachable(int to) { return cost[to] == INF;\
    \ }\n\n\tbool has_negative_cycle() { return negative_cycle_flag; }\n};\n\n#endif\
    \ // GRAPH_BELLMAN_FORD_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/bellman_ford/aoj_grl_1_b.test.cpp
documentation_of: src/graph/bellman_ford.hpp
layout: document
title: Bellman-Ford
---
