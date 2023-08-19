---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/bellman_ford.cpp
    title: src/graph/bellman_ford.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"test/graph/bellman_ford/grl_1_b.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\n\n\
    #line 1 \"src/graph/bellman_ford.cpp\"\n#include <limits>\n#include <vector>\n\
    \nusing namespace std;\n\ntemplate<class T>\nstruct Edge {\n\tint from, to;\n\t\
    T cost;\n\n\tEdge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n\
    };\n\ntemplate<class T>\nvector<T> bellman_ford(int s, int V, vector<Edge<T>>\
    \ &G) {\n\tconst T INF = numeric_limits<T>::max();\n\tvector<T> cost(V, INF);\n\
    \tvector<int> prevr(V, -1); // \u7D4C\u8DEF\u5FA9\u5143\u7528\n\tcost[s] = 0;\n\
    \tfor (int i = 0; i < V; ++i) {\n\t\tfor (Edge<T> e : G) {\n\t\t\tif (cost[e.from]\
    \ == INF) continue;\n\t\t\tif (cost[e.to] > cost[e.from] + e.cost) {\n\t\t\t\t\
    cost[e.to] = cost[e.from] + e.cost;\n\t\t\t\tprevr[e.to] = e.from;\n\t\t\t\tif\
    \ (i == V - 1) return vector<T>();\n\t\t\t}\n\t\t}\n\t}\n\treturn cost;\n}\n#line\
    \ 4 \"test/graph/bellman_ford/grl_1_b.test.cpp\"\n\n#include <iostream>\n#line\
    \ 7 \"test/graph/bellman_ford/grl_1_b.test.cpp\"\n\nint main() {\n\tint V, E,\
    \ r;\n\tcin >> V >> E >> r;\n\tvector<Edge<int>> G;\n\tfor (int i = 0; i < E;\
    \ ++i) {\n\t\tint s, t, d;\n\t\tcin >> s >> t >> d;\n\t\tG.emplace_back(s, t,\
    \ d);\n\t}\n\tvector<int> ans = bellman_ford(r, V, G);\n\tif (ans.empty()) cout\
    \ << \"NEGATIVE CYCLE\" << endl;\n\telse {\n\t\tfor (int i = 0; i < V; ++i) {\n\
    \t\t\tif (ans[i] == numeric_limits<int>::max()) cout << \"INF\" << endl;\n\t\t\
    \telse cout << ans[i] << endl;\n\t\t}\n\t}\n\n\treturn 0;\n}\n\n/*\n\tcreated:\
    \ 2019-08-27\n\thttps://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\n\
    */\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\n\
    \n#include \"src/graph/bellman_ford.cpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nint main() {\n\tint V, E, r;\n\tcin >> V >> E >> r;\n\tvector<Edge<int>> G;\n\
    \tfor (int i = 0; i < E; ++i) {\n\t\tint s, t, d;\n\t\tcin >> s >> t >> d;\n\t\
    \tG.emplace_back(s, t, d);\n\t}\n\tvector<int> ans = bellman_ford(r, V, G);\n\t\
    if (ans.empty()) cout << \"NEGATIVE CYCLE\" << endl;\n\telse {\n\t\tfor (int i\
    \ = 0; i < V; ++i) {\n\t\t\tif (ans[i] == numeric_limits<int>::max()) cout <<\
    \ \"INF\" << endl;\n\t\t\telse cout << ans[i] << endl;\n\t\t}\n\t}\n\n\treturn\
    \ 0;\n}\n\n/*\n\tcreated: 2019-08-27\n\thttps://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\n\
    */\n"
  dependsOn:
  - src/graph/bellman_ford.cpp
  isVerificationFile: true
  path: test/graph/bellman_ford/grl_1_b.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/bellman_ford/grl_1_b.test.cpp
layout: document
redirect_from:
- /verify/test/graph/bellman_ford/grl_1_b.test.cpp
- /verify/test/graph/bellman_ford/grl_1_b.test.cpp.html
title: test/graph/bellman_ford/grl_1_b.test.cpp
---
