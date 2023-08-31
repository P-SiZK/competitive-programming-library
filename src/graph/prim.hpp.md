---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/prim/grl_2_a.test.cpp
    title: test/graph/prim/grl_2_a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/prim.hpp\"\n\n\n\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\ntemplate<class T>\nclass Prim {\nprivate:\n\tint n;\n\tstd::vector<std::vector<std::pair<int,\
    \ T>>> g;\n\npublic:\n\tPrim(int n) : n(n), g(n) {}\n\n\tvoid add_edge(int from,\
    \ int to, T cost) {\n\t\tg[from].emplace_back(to, cost);\n\t\tg[to].emplace_back(from,\
    \ cost);\n\t}\n\n\tT mst_cost() {\n\t\tT cost = 0;\n\t\tstd::vector<bool> used(g.size());\n\
    \t\tstd::priority_queue<std::pair<T, int>,\n\t\t\t\t\t\t\tstd::vector<std::pair<T,\
    \ int>>,\n\t\t\t\t\t\t\tstd::greater<>>\n\t\t\tpq;\n\t\tpq.emplace(0, 0);\n\t\t\
    while (!pq.empty()) {\n\t\t\tauto [now_cost, now_v] = pq.top();\n\t\t\tpq.pop();\n\
    \t\t\tif (used[now_v]) continue;\n\t\t\tused[now_v] = true;\n\t\t\tcost += now_cost;\n\
    \t\t\tfor (auto [nv, nw] : g[now_v]) pq.emplace(nw, nv);\n\t\t}\n\t\treturn cost;\n\
    \t}\n};\n\n\n"
  code: "#ifndef GRAPH_PRIM_HPP\n#define GRAPH_PRIM_HPP\n\n#include <queue>\n#include\
    \ <utility>\n#include <vector>\n\ntemplate<class T>\nclass Prim {\nprivate:\n\t\
    int n;\n\tstd::vector<std::vector<std::pair<int, T>>> g;\n\npublic:\n\tPrim(int\
    \ n) : n(n), g(n) {}\n\n\tvoid add_edge(int from, int to, T cost) {\n\t\tg[from].emplace_back(to,\
    \ cost);\n\t\tg[to].emplace_back(from, cost);\n\t}\n\n\tT mst_cost() {\n\t\tT\
    \ cost = 0;\n\t\tstd::vector<bool> used(g.size());\n\t\tstd::priority_queue<std::pair<T,\
    \ int>,\n\t\t\t\t\t\t\tstd::vector<std::pair<T, int>>,\n\t\t\t\t\t\t\tstd::greater<>>\n\
    \t\t\tpq;\n\t\tpq.emplace(0, 0);\n\t\twhile (!pq.empty()) {\n\t\t\tauto [now_cost,\
    \ now_v] = pq.top();\n\t\t\tpq.pop();\n\t\t\tif (used[now_v]) continue;\n\t\t\t\
    used[now_v] = true;\n\t\t\tcost += now_cost;\n\t\t\tfor (auto [nv, nw] : g[now_v])\
    \ pq.emplace(nw, nv);\n\t\t}\n\t\treturn cost;\n\t}\n};\n\n#endif // GRAPH_PRIM_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/prim.hpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/prim/grl_2_a.test.cpp
documentation_of: src/graph/prim.hpp
layout: document
redirect_from:
- /library/src/graph/prim.hpp
- /library/src/graph/prim.hpp.html
title: src/graph/prim.hpp
---
