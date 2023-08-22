---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dijkstra.hpp
    title: src/graph/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
  bundledCode: "#line 1 \"test/graph/dijkstra/grl_1_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\n\
    \n#line 1 \"src/graph/dijkstra.hpp\"\n#include <limits>\r\n#include <queue>\r\n\
    #include <vector>\r\n\r\nusing namespace std;\r\n\r\ntemplate<class T>\r\nvector<T>\
    \ dijkstra(int s, vector<vector<pair<int, T>>> &g) {\r\n\tconst T INF = numeric_limits<T>::max();\r\
    \n\tint const N = g.size();\r\n\tvector<T> cost(N, INF);\r\n\tvector<int> prevr(N,\
    \ -1); // \u7D4C\u8DEF\u5FA9\u5143\u7528\r\n\tpriority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<>> pq;\r\n\tcost[s] = 0;\r\n\tpq.push(make_pair(0, s));\r\n\t\
    while (!pq.empty()) {\r\n\t\tpair<T, int> p = pq.top();\r\n\t\tpq.pop();\r\n\t\
    \tint now = p.second;\r\n\t\tif (cost[now] < p.first) continue;\r\n\t\tfor (auto\
    \ next : g[now]) {\r\n\t\t\tint nv = next.first;\r\n\t\t\tT nw = next.second;\r\
    \n\t\t\tif (cost[nv] > cost[now] + nw) {\r\n\t\t\t\tcost[nv] = cost[now] + nw;\r\
    \n\t\t\t\tprevr[nv] = now;\r\n\t\t\t\tpq.push(make_pair(cost[nv], nv));\r\n\t\t\
    \t}\r\n\t\t}\r\n\t}\r\n\treturn cost;\r\n}\r\n#line 4 \"test/graph/dijkstra/grl_1_a.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"test/graph/dijkstra/grl_1_a.test.cpp\"\n\n\
    int main() {\n\tint v, e, r;\n\tcin >> v >> e >> r;\n\tvector<vector<pair<int,\
    \ int>>> g(v);\n\tfor (int i = 0; i < e; ++i) {\n\t\tint s, t, d;\n\t\tcin >>\
    \ s >> t >> d;\n\t\tg[s].emplace_back(t, d);\n\t}\n\tvector<int> ans = dijkstra(r,\
    \ g);\n\tfor (int i = 0; i < v; ++i) {\n\t\tif (ans[i] == numeric_limits<int>::max())\
    \ cout << \"INF\" << endl;\n\t\telse cout << ans[i] << endl;\n\t}\n\n\treturn\
    \ 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\n\
    \n#include \"src/graph/dijkstra.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nint main() {\n\tint v, e, r;\n\tcin >> v >> e >> r;\n\tvector<vector<pair<int,\
    \ int>>> g(v);\n\tfor (int i = 0; i < e; ++i) {\n\t\tint s, t, d;\n\t\tcin >>\
    \ s >> t >> d;\n\t\tg[s].emplace_back(t, d);\n\t}\n\tvector<int> ans = dijkstra(r,\
    \ g);\n\tfor (int i = 0; i < v; ++i) {\n\t\tif (ans[i] == numeric_limits<int>::max())\
    \ cout << \"INF\" << endl;\n\t\telse cout << ans[i] << endl;\n\t}\n\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - src/graph/dijkstra.hpp
  isVerificationFile: true
  path: test/graph/dijkstra/grl_1_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dijkstra/grl_1_a.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra/grl_1_a.test.cpp
- /verify/test/graph/dijkstra/grl_1_a.test.cpp.html
title: test/graph/dijkstra/grl_1_a.test.cpp
---
