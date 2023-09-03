---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/dijkstra.hpp
    title: Dijkstra
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A
  bundledCode: "#line 1 \"test/graph/dijkstra/grl_1_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\n\
    \n#line 1 \"src/graph/dijkstra.hpp\"\n\n\n\r\n#include <algorithm>\r\n#include\
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
    \ }\r\n};\r\n\r\n\n#line 4 \"test/graph/dijkstra/grl_1_a.test.cpp\"\n\n#include\
    \ <iostream>\n#line 7 \"test/graph/dijkstra/grl_1_a.test.cpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n\tint v, e, r;\n\tcin >> v >> e >> r;\n\tDijkstra<int>\
    \ dj(v);\n\tfor (int i = 0; i < e; ++i) {\n\t\tint s, t, d;\n\t\tcin >> s >> t\
    \ >> d;\n\t\tdj.add_edge(s, t, d);\n\t}\n\tdj.build(r);\n\tfor (int i = 0; i <\
    \ v; ++i) {\n\t\tif (dj.is_unreachable(i)) cout << \"INF\" << endl;\n\t\telse\
    \ cout << dj.distance(i) << endl;\n\t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A\n\
    \n#include \"src/graph/dijkstra.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nusing namespace std;\n\nint main() {\n\tint v, e, r;\n\tcin >> v >> e >> r;\n\
    \tDijkstra<int> dj(v);\n\tfor (int i = 0; i < e; ++i) {\n\t\tint s, t, d;\n\t\t\
    cin >> s >> t >> d;\n\t\tdj.add_edge(s, t, d);\n\t}\n\tdj.build(r);\n\tfor (int\
    \ i = 0; i < v; ++i) {\n\t\tif (dj.is_unreachable(i)) cout << \"INF\" << endl;\n\
    \t\telse cout << dj.distance(i) << endl;\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/graph/dijkstra.hpp
  isVerificationFile: true
  path: test/graph/dijkstra/grl_1_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/dijkstra/grl_1_a.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra/grl_1_a.test.cpp
- /verify/test/graph/dijkstra/grl_1_a.test.cpp.html
title: test/graph/dijkstra/grl_1_a.test.cpp
---
