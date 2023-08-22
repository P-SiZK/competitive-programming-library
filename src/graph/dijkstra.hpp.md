---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/dijkstra/grl_1_a.test.cpp
    title: test/graph/dijkstra/grl_1_a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graph/dijkstra.hpp\"\n#include <limits>\r\n#include\
    \ <queue>\r\n#include <vector>\r\n\r\nusing namespace std;\r\n\r\ntemplate<class\
    \ T>\r\nvector<T> dijkstra(int s, vector<vector<pair<int, T>>> &g) {\r\n\tconst\
    \ T INF = numeric_limits<T>::max();\r\n\tint const N = g.size();\r\n\tvector<T>\
    \ cost(N, INF);\r\n\tvector<int> prevr(N, -1); // \u7D4C\u8DEF\u5FA9\u5143\u7528\
    \r\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;\r\n\t\
    cost[s] = 0;\r\n\tpq.push(make_pair(0, s));\r\n\twhile (!pq.empty()) {\r\n\t\t\
    pair<T, int> p = pq.top();\r\n\t\tpq.pop();\r\n\t\tint now = p.second;\r\n\t\t\
    if (cost[now] < p.first) continue;\r\n\t\tfor (auto next : g[now]) {\r\n\t\t\t\
    int nv = next.first;\r\n\t\t\tT nw = next.second;\r\n\t\t\tif (cost[nv] > cost[now]\
    \ + nw) {\r\n\t\t\t\tcost[nv] = cost[now] + nw;\r\n\t\t\t\tprevr[nv] = now;\r\n\
    \t\t\t\tpq.push(make_pair(cost[nv], nv));\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn\
    \ cost;\r\n}\r\n"
  code: "#include <limits>\r\n#include <queue>\r\n#include <vector>\r\n\r\nusing namespace\
    \ std;\r\n\r\ntemplate<class T>\r\nvector<T> dijkstra(int s, vector<vector<pair<int,\
    \ T>>> &g) {\r\n\tconst T INF = numeric_limits<T>::max();\r\n\tint const N = g.size();\r\
    \n\tvector<T> cost(N, INF);\r\n\tvector<int> prevr(N, -1); // \u7D4C\u8DEF\u5FA9\
    \u5143\u7528\r\n\tpriority_queue<pair<T, int>, vector<pair<T, int>>, greater<>>\
    \ pq;\r\n\tcost[s] = 0;\r\n\tpq.push(make_pair(0, s));\r\n\twhile (!pq.empty())\
    \ {\r\n\t\tpair<T, int> p = pq.top();\r\n\t\tpq.pop();\r\n\t\tint now = p.second;\r\
    \n\t\tif (cost[now] < p.first) continue;\r\n\t\tfor (auto next : g[now]) {\r\n\
    \t\t\tint nv = next.first;\r\n\t\t\tT nw = next.second;\r\n\t\t\tif (cost[nv]\
    \ > cost[now] + nw) {\r\n\t\t\t\tcost[nv] = cost[now] + nw;\r\n\t\t\t\tprevr[nv]\
    \ = now;\r\n\t\t\t\tpq.push(make_pair(cost[nv], nv));\r\n\t\t\t}\r\n\t\t}\r\n\t\
    }\r\n\treturn cost;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/dijkstra/grl_1_a.test.cpp
documentation_of: src/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/src/graph/dijkstra.hpp
- /library/src/graph/dijkstra.hpp.html
title: src/graph/dijkstra.hpp
---
