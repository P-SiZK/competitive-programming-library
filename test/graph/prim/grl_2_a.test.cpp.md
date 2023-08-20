---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/prim.cpp
    title: src/graph/prim.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/graph/prim/grl_2_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\n\
    #line 1 \"src/graph/prim.cpp\"\n#include <queue>\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T>\nT prim(vector<vector<pair<int, T>>> &G) {\n\tT cost\
    \ = 0;\n\tconst int N = G.size();\n\tvector<bool> used(G.size());\n\tpriority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<>> pq;\n\tpq.emplace(0, 0);\n\twhile (!pq.empty())\
    \ {\n\t\tpair<T, int> p = pq.top();\n\t\tpq.pop();\n\t\tint now = p.second;\n\t\
    \tif (used[now]) continue;\n\t\tused[now] = true;\n\t\tcost += p.first;\n\t\t\
    for (auto e : G[now]) pq.emplace(e.second, e.first);\n\t}\n\treturn cost;\n}\n\
    #line 4 \"test/graph/prim/grl_2_a.test.cpp\"\n\n#include <iostream>\n#line 7 \"\
    test/graph/prim/grl_2_a.test.cpp\"\n\nusing namespace std;\n\nint main() {\n\t\
    int V, E;\n\tcin >> V >> E;\n\tvector<vector<pair<int, int>>> G(V);\n\tfor (int\
    \ i = 0; i < E; ++i) {\n\t\tint a, b, c;\n\t\tcin >> a >> b >> c;\n\t\tG[a].emplace_back(b,\
    \ c);\n\t\tG[b].emplace_back(a, c);\n\t}\n\tcout << prim(G) << endl;\n\n\treturn\
    \ 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\
    \n#include \"src/graph/prim.cpp\"\n\n#include <iostream>\n#include <vector>\n\n\
    using namespace std;\n\nint main() {\n\tint V, E;\n\tcin >> V >> E;\n\tvector<vector<pair<int,\
    \ int>>> G(V);\n\tfor (int i = 0; i < E; ++i) {\n\t\tint a, b, c;\n\t\tcin >>\
    \ a >> b >> c;\n\t\tG[a].emplace_back(b, c);\n\t\tG[b].emplace_back(a, c);\n\t\
    }\n\tcout << prim(G) << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/graph/prim.cpp
  isVerificationFile: true
  path: test/graph/prim/grl_2_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/prim/grl_2_a.test.cpp
layout: document
redirect_from:
- /verify/test/graph/prim/grl_2_a.test.cpp
- /verify/test/graph/prim/grl_2_a.test.cpp.html
title: test/graph/prim/grl_2_a.test.cpp
---
