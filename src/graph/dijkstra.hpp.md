---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra/grl_1_a.test.cpp
    title: test/graph/dijkstra/grl_1_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/dijkstra.hpp\"\n#include <algorithm>\r\n#include\
    \ <limits>\r\n#include <queue>\r\n#include <utility>\r\n#include <vector>\r\n\r\
    \ntemplate<class T>\r\nclass Dijkstra {\r\nprivate:\r\n\tstatic constexpr T INF\
    \ = std::numeric_limits<T>::max();\r\n\r\n\tint s{};\r\n\tstd::vector<std::vector<std::pair<int,\
    \ T>>> g;\r\n\tstd::vector<T> cost;\r\n\tstd::vector<int> prevv;\r\n\r\npublic:\r\
    \n\tDijkstra(int n) : g(n), cost(n), prevv(n) {}\r\n\r\n\tvoid add_edge(int from,\
    \ int to, T cost) { g[from].emplace_back(to, cost); }\r\n\r\n\tvoid build(int\
    \ from) {\r\n\t\ts = from;\r\n\t\tcost.assign(g.size(), INF);\r\n\t\tprevv.assign(g.size(),\
    \ -1);\r\n\t\tstd::priority_queue<std::pair<T, int>,\r\n\t\t\t\t\t\t\tstd::vector<std::pair<T,\
    \ int>>,\r\n\t\t\t\t\t\t\tstd::greater<>>\r\n\t\t\tpq;\r\n\t\tcost[s] = 0;\r\n\
    \t\tpq.emplace(0, s);\r\n\t\twhile (!pq.empty()) {\r\n\t\t\tauto [now_cost, now_v]\
    \ = pq.top();\r\n\t\t\tpq.pop();\r\n\t\t\tif (cost[now_v] < now_cost) continue;\r\
    \n\t\t\tfor (auto [nv, nw] : g[now_v]) {\r\n\t\t\t\tif (cost[nv] > cost[now_v]\
    \ + nw) {\r\n\t\t\t\t\tcost[nv] = cost[now_v] + nw;\r\n\t\t\t\t\tprevv[nv] = now_v;\r\
    \n\t\t\t\t\tpq.emplace(cost[nv], nv);\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\
    \n\r\n\tT distance(int to) { return cost[to]; }\r\n\r\n\tstd::vector<int> shortest_path(int\
    \ to) {\r\n\t\tstd::vector<int> path;\r\n\t\tfor (int v = to; v != -1; v = prevv[v])\
    \ path.push_back(v);\r\n\t\tstd::reverse(path.begin(), path.end());\r\n\t\treturn\
    \ path;\r\n\t}\r\n\r\n\tbool is_unreachable(int to) { return cost[to] == INF;\
    \ }\r\n};\r\n"
  code: "#include <algorithm>\r\n#include <limits>\r\n#include <queue>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n\r\ntemplate<class T>\r\nclass Dijkstra {\r\
    \nprivate:\r\n\tstatic constexpr T INF = std::numeric_limits<T>::max();\r\n\r\n\
    \tint s{};\r\n\tstd::vector<std::vector<std::pair<int, T>>> g;\r\n\tstd::vector<T>\
    \ cost;\r\n\tstd::vector<int> prevv;\r\n\r\npublic:\r\n\tDijkstra(int n) : g(n),\
    \ cost(n), prevv(n) {}\r\n\r\n\tvoid add_edge(int from, int to, T cost) { g[from].emplace_back(to,\
    \ cost); }\r\n\r\n\tvoid build(int from) {\r\n\t\ts = from;\r\n\t\tcost.assign(g.size(),\
    \ INF);\r\n\t\tprevv.assign(g.size(), -1);\r\n\t\tstd::priority_queue<std::pair<T,\
    \ int>,\r\n\t\t\t\t\t\t\tstd::vector<std::pair<T, int>>,\r\n\t\t\t\t\t\t\tstd::greater<>>\r\
    \n\t\t\tpq;\r\n\t\tcost[s] = 0;\r\n\t\tpq.emplace(0, s);\r\n\t\twhile (!pq.empty())\
    \ {\r\n\t\t\tauto [now_cost, now_v] = pq.top();\r\n\t\t\tpq.pop();\r\n\t\t\tif\
    \ (cost[now_v] < now_cost) continue;\r\n\t\t\tfor (auto [nv, nw] : g[now_v]) {\r\
    \n\t\t\t\tif (cost[nv] > cost[now_v] + nw) {\r\n\t\t\t\t\tcost[nv] = cost[now_v]\
    \ + nw;\r\n\t\t\t\t\tprevv[nv] = now_v;\r\n\t\t\t\t\tpq.emplace(cost[nv], nv);\r\
    \n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\r\n\tT distance(int to) { return cost[to];\
    \ }\r\n\r\n\tstd::vector<int> shortest_path(int to) {\r\n\t\tstd::vector<int>\
    \ path;\r\n\t\tfor (int v = to; v != -1; v = prevv[v]) path.push_back(v);\r\n\t\
    \tstd::reverse(path.begin(), path.end());\r\n\t\treturn path;\r\n\t}\r\n\r\n\t\
    bool is_unreachable(int to) { return cost[to] == INF; }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-08-31 13:01:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra/grl_1_a.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: src/graph/dijkstra.hpp
---
