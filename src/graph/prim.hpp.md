---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/prim/grl_2_a.test.cpp
    title: test/graph/prim/grl_2_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/prim.hpp\"\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\nusing namespace std;\n\ntemplate<class T>\nclass Prim {\n\
    private:\n\tint n;\n\tvector<vector<pair<int, T>>> g;\n\npublic:\n\tPrim(int n)\
    \ : n(n), g(n) {}\n\n\tvoid add_edge(int from, int to, T cost) {\n\t\tg[from].emplace_back(to,\
    \ cost);\n\t\tg[to].emplace_back(from, cost);\n\t}\n\n\tT mst_cost() {\n\t\tT\
    \ cost = 0;\n\t\tvector<bool> used(g.size());\n\t\tpriority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<>> pq;\n\t\tpq.emplace(0, 0);\n\t\twhile (!pq.empty())\
    \ {\n\t\t\tauto [now_cost, now_v] = pq.top();\n\t\t\tpq.pop();\n\t\t\tif (used[now_v])\
    \ continue;\n\t\t\tused[now_v] = true;\n\t\t\tcost += now_cost;\n\t\t\tfor (auto\
    \ [nv, nw] : g[now_v]) pq.emplace(nw, nv);\n\t\t}\n\t\treturn cost;\n\t}\n};\n"
  code: "#include <queue>\n#include <utility>\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T>\nclass Prim {\nprivate:\n\tint n;\n\tvector<vector<pair<int,\
    \ T>>> g;\n\npublic:\n\tPrim(int n) : n(n), g(n) {}\n\n\tvoid add_edge(int from,\
    \ int to, T cost) {\n\t\tg[from].emplace_back(to, cost);\n\t\tg[to].emplace_back(from,\
    \ cost);\n\t}\n\n\tT mst_cost() {\n\t\tT cost = 0;\n\t\tvector<bool> used(g.size());\n\
    \t\tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;\n\t\tpq.emplace(0,\
    \ 0);\n\t\twhile (!pq.empty()) {\n\t\t\tauto [now_cost, now_v] = pq.top();\n\t\
    \t\tpq.pop();\n\t\t\tif (used[now_v]) continue;\n\t\t\tused[now_v] = true;\n\t\
    \t\tcost += now_cost;\n\t\t\tfor (auto [nv, nw] : g[now_v]) pq.emplace(nw, nv);\n\
    \t\t}\n\t\treturn cost;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/prim.hpp
  requiredBy: []
  timestamp: '2023-08-31 00:25:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/prim/grl_2_a.test.cpp
documentation_of: src/graph/prim.hpp
layout: document
redirect_from:
- /library/src/graph/prim.hpp
- /library/src/graph/prim.hpp.html
title: src/graph/prim.hpp
---
