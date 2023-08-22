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
    #line 1 \"src/graph/bellman_ford.hpp\"\n#include <limits>\n#include <vector>\n\
    \nusing namespace std;\n\ntemplate<class T>\nstruct Edge {\n\tint from, to;\n\t\
    T cost;\n\n\tEdge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n\
    };\n\ntemplate<class T>\nvector<T> bellman_ford(int s, int v, vector<Edge<T>>\
    \ &g) {\n\tconst T INF = numeric_limits<T>::max();\n\tvector<T> cost(v, INF);\n\
    \tvector<int> prevr(v, -1); // \u7D4C\u8DEF\u5FA9\u5143\u7528\n\tcost[s] = 0;\n\
    \tfor (int i = 0; i < v; ++i) {\n\t\tfor (Edge<T> e : g) {\n\t\t\tif (cost[e.from]\
    \ == INF) continue;\n\t\t\tif (cost[e.to] > cost[e.from] + e.cost) {\n\t\t\t\t\
    cost[e.to] = cost[e.from] + e.cost;\n\t\t\t\tprevr[e.to] = e.from;\n\t\t\t\tif\
    \ (i == v - 1) return vector<T>();\n\t\t\t}\n\t\t}\n\t}\n\treturn cost;\n}\n#line\
    \ 4 \"test/graph/bellman_ford/grl_1_b.test.cpp\"\n\n#include <iostream>\n#line\
    \ 7 \"test/graph/bellman_ford/grl_1_b.test.cpp\"\n\nint main() {\n\tint v, e,\
    \ r;\n\tcin >> v >> e >> r;\n\tvector<Edge<int>> g;\n\tfor (int i = 0; i < e;\
    \ ++i) {\n\t\tint s, t, d;\n\t\tcin >> s >> t >> d;\n\t\tg.emplace_back(s, t,\
    \ d);\n\t}\n\tvector<int> ans = bellman_ford(r, v, g);\n\tif (ans.empty()) cout\
    \ << \"NEGATIVE CYCLE\" << endl;\n\telse {\n\t\tfor (int i = 0; i < v; ++i) {\n\
    \t\t\tif (ans[i] == numeric_limits<int>::max()) cout << \"INF\" << endl;\n\t\t\
    \telse cout << ans[i] << endl;\n\t\t}\n\t}\n\n\treturn 0;\n}\n\n/*\n\tcreated:\
    \ 2019-08-27\n\thttps://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\n\
    */\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\n\
    \n#include \"src/graph/bellman_ford.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nint main() {\n\tint v, e, r;\n\tcin >> v >> e >> r;\n\tvector<Edge<int>> g;\n\
    \tfor (int i = 0; i < e; ++i) {\n\t\tint s, t, d;\n\t\tcin >> s >> t >> d;\n\t\
    \tg.emplace_back(s, t, d);\n\t}\n\tvector<int> ans = bellman_ford(r, v, g);\n\t\
    if (ans.empty()) cout << \"NEGATIVE CYCLE\" << endl;\n\telse {\n\t\tfor (int i\
    \ = 0; i < v; ++i) {\n\t\t\tif (ans[i] == numeric_limits<int>::max()) cout <<\
    \ \"INF\" << endl;\n\t\t\telse cout << ans[i] << endl;\n\t\t}\n\t}\n\n\treturn\
    \ 0;\n}\n\n/*\n\tcreated: 2019-08-27\n\thttps://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\n\
    */\n"
  dependsOn:
  - src/graph/bellman_ford.hpp
  isVerificationFile: true
  path: test/graph/bellman_ford/grl_1_b.test.cpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/bellman_ford/grl_1_b.test.cpp
layout: document
redirect_from:
- /verify/test/graph/bellman_ford/grl_1_b.test.cpp
- /verify/test/graph/bellman_ford/grl_1_b.test.cpp.html
title: test/graph/bellman_ford/grl_1_b.test.cpp
---
