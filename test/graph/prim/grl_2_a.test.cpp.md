---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/prim.hpp
    title: src/graph/prim.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/graph/prim/grl_2_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\n\
    #line 1 \"src/graph/prim.hpp\"\n#include <queue>\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T>\nT prim(vector<vector<pair<int, T>>> &g) {\n\tT cost\
    \ = 0;\n\tvector<bool> used(g.size());\n\tpriority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<>> pq;\n\tpq.emplace(0, 0);\n\twhile (!pq.empty()) {\n\t\tpair<T,\
    \ int> p = pq.top();\n\t\tpq.pop();\n\t\tint now = p.second;\n\t\tif (used[now])\
    \ continue;\n\t\tused[now] = true;\n\t\tcost += p.first;\n\t\tfor (auto e : g[now])\
    \ pq.emplace(e.second, e.first);\n\t}\n\treturn cost;\n}\n#line 4 \"test/graph/prim/grl_2_a.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"test/graph/prim/grl_2_a.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main() {\n\tint v, e;\n\tcin >> v >> e;\n\tvector<vector<pair<int,\
    \ int>>> g(v);\n\tfor (int i = 0; i < e; ++i) {\n\t\tint a, b, c;\n\t\tcin >>\
    \ a >> b >> c;\n\t\tg[a].emplace_back(b, c);\n\t\tg[b].emplace_back(a, c);\n\t\
    }\n\tcout << prim(g) << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\
    \n#include \"src/graph/prim.hpp\"\n\n#include <iostream>\n#include <vector>\n\n\
    using namespace std;\n\nint main() {\n\tint v, e;\n\tcin >> v >> e;\n\tvector<vector<pair<int,\
    \ int>>> g(v);\n\tfor (int i = 0; i < e; ++i) {\n\t\tint a, b, c;\n\t\tcin >>\
    \ a >> b >> c;\n\t\tg[a].emplace_back(b, c);\n\t\tg[b].emplace_back(a, c);\n\t\
    }\n\tcout << prim(g) << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/graph/prim.hpp
  isVerificationFile: true
  path: test/graph/prim/grl_2_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-22 14:56:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/prim/grl_2_a.test.cpp
layout: document
redirect_from:
- /verify/test/graph/prim/grl_2_a.test.cpp
- /verify/test/graph/prim/grl_2_a.test.cpp.html
title: test/graph/prim/grl_2_a.test.cpp
---
