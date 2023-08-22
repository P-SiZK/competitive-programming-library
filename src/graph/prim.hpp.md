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
  bundledCode: "#line 1 \"src/graph/prim.hpp\"\n#include <queue>\n#include <vector>\n\
    \nusing namespace std;\n\ntemplate<class T>\nT prim(vector<vector<pair<int, T>>>\
    \ &g) {\n\tT cost = 0;\n\tvector<bool> used(g.size());\n\tpriority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<>> pq;\n\tpq.emplace(0, 0);\n\twhile (!pq.empty())\
    \ {\n\t\tpair<T, int> p = pq.top();\n\t\tpq.pop();\n\t\tint now = p.second;\n\t\
    \tif (used[now]) continue;\n\t\tused[now] = true;\n\t\tcost += p.first;\n\t\t\
    for (auto e : g[now]) pq.emplace(e.second, e.first);\n\t}\n\treturn cost;\n}\n"
  code: "#include <queue>\n#include <vector>\n\nusing namespace std;\n\ntemplate<class\
    \ T>\nT prim(vector<vector<pair<int, T>>> &g) {\n\tT cost = 0;\n\tvector<bool>\
    \ used(g.size());\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<>>\
    \ pq;\n\tpq.emplace(0, 0);\n\twhile (!pq.empty()) {\n\t\tpair<T, int> p = pq.top();\n\
    \t\tpq.pop();\n\t\tint now = p.second;\n\t\tif (used[now]) continue;\n\t\tused[now]\
    \ = true;\n\t\tcost += p.first;\n\t\tfor (auto e : g[now]) pq.emplace(e.second,\
    \ e.first);\n\t}\n\treturn cost;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/prim.hpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
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
