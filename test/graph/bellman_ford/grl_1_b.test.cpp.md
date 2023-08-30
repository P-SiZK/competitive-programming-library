---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bellman_ford.hpp
    title: src/graph/bellman_ford.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"test/graph/bellman_ford/grl_1_b.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\n\n\
    #line 1 \"src/graph/bellman_ford.hpp\"\n#include <algorithm>\n#include <limits>\n\
    #include <vector>\n\nusing namespace std;\n\ntemplate<class T>\nclass BellmanFord\
    \ {\nprivate:\n\tstruct Edge {\n\t\tint from, to;\n\t\tT cost;\n\n\t\tEdge(int\
    \ from, int to, T cost) : from(from), to(to), cost(cost) {}\n\t};\n\n\tstatic\
    \ constexpr T INF = numeric_limits<T>::max();\n\n\tint n, s{};\n\tvector<Edge>\
    \ g;\n\tvector<T> cost;\n\tvector<int> prevv;\n\tbool negative_cycle_flag{};\n\
    \npublic:\n\tBellmanFord(int n) : n(n), cost(n), prevv(n) {}\n\n\tvoid add_edge(int\
    \ from, int to, T cost) { g.emplace_back(from, to, cost); }\n\n\tvoid build(int\
    \ from) {\n\t\ts = from;\n\t\tcost.assign(n, INF);\n\t\tprevv.assign(n, -1);\n\
    \t\tcost[s] = 0;\n\t\tfor (int i = 0; i < n; ++i) {\n\t\t\tfor (Edge &e : g) {\n\
    \t\t\t\tif (cost[e.from] == INF) continue;\n\t\t\t\tif (cost[e.to] > cost[e.from]\
    \ + e.cost) {\n\t\t\t\t\tcost[e.to] = cost[e.from] + e.cost;\n\t\t\t\t\tprevv[e.to]\
    \ = e.from;\n\t\t\t\t\tif (i == n - 1) {\n\t\t\t\t\t\tnegative_cycle_flag = true;\n\
    \t\t\t\t\t\treturn;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tT distance(int\
    \ to) { return cost[to]; }\n\n\tvector<int> shortest_path(int to) {\n\t\tvector<int>\
    \ path;\n\t\tfor (int v = to; v != -1; v = prevv[v]) path.push_back(v);\n\t\t\
    reverse(path.begin(), path.end());\n\t\treturn path;\n\t}\n\n\tbool is_unreachable(int\
    \ to) { return cost[to] == INF; }\n\n\tbool has_negative_cycle() { return negative_cycle_flag;\
    \ }\n};\n#line 4 \"test/graph/bellman_ford/grl_1_b.test.cpp\"\n\n#include <iostream>\n\
    #line 7 \"test/graph/bellman_ford/grl_1_b.test.cpp\"\n\nint main() {\n\tint v,\
    \ e, r;\n\tcin >> v >> e >> r;\n\tBellmanFord<int> bf(v);\n\tfor (int i = 0; i\
    \ < e; ++i) {\n\t\tint s, t, d;\n\t\tcin >> s >> t >> d;\n\t\tbf.add_edge(s, t,\
    \ d);\n\t}\n\tbf.build(r);\n\tif (bf.has_negative_cycle()) cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n\telse {\n\t\tfor (int i = 0; i < v; ++i) {\n\t\t\tif (bf.is_unreachable(i))\
    \ cout << \"INF\" << endl;\n\t\t\telse cout << bf.distance(i) << endl;\n\t\t}\n\
    \t}\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\n\
    \n#include \"src/graph/bellman_ford.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nint main() {\n\tint v, e, r;\n\tcin >> v >> e >> r;\n\tBellmanFord<int> bf(v);\n\
    \tfor (int i = 0; i < e; ++i) {\n\t\tint s, t, d;\n\t\tcin >> s >> t >> d;\n\t\
    \tbf.add_edge(s, t, d);\n\t}\n\tbf.build(r);\n\tif (bf.has_negative_cycle()) cout\
    \ << \"NEGATIVE CYCLE\" << endl;\n\telse {\n\t\tfor (int i = 0; i < v; ++i) {\n\
    \t\t\tif (bf.is_unreachable(i)) cout << \"INF\" << endl;\n\t\t\telse cout << bf.distance(i)\
    \ << endl;\n\t\t}\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/graph/bellman_ford.hpp
  isVerificationFile: true
  path: test/graph/bellman_ford/grl_1_b.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 00:25:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/bellman_ford/grl_1_b.test.cpp
layout: document
redirect_from:
- /verify/test/graph/bellman_ford/grl_1_b.test.cpp
- /verify/test/graph/bellman_ford/grl_1_b.test.cpp.html
title: test/graph/bellman_ford/grl_1_b.test.cpp
---
