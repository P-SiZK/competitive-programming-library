---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/prim.hpp
    title: Prim
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/graph/prim/aoj_grl_2_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\n\
    #line 1 \"src/graph/prim.hpp\"\n\n\n\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\ntemplate<class T>\nclass Prim {\nprivate:\n\tint n;\n\tstd::vector<std::vector<std::pair<int,\
    \ T>>> g;\n\npublic:\n\tPrim(int n) : n(n), g(n) {}\n\n\tvoid add_edge(int from,\
    \ int to, T cost) {\n\t\tg[from].emplace_back(to, cost);\n\t\tg[to].emplace_back(from,\
    \ cost);\n\t}\n\n\tT mst_cost() {\n\t\tT cost = 0;\n\t\tstd::vector<bool> used(g.size());\n\
    \t\tstd::priority_queue<std::pair<T, int>,\n\t\t\t\t\t\t\tstd::vector<std::pair<T,\
    \ int>>,\n\t\t\t\t\t\t\tstd::greater<>>\n\t\t\tpq;\n\t\tpq.emplace(0, 0);\n\t\t\
    while (!pq.empty()) {\n\t\t\tauto [now_cost, now_v] = pq.top();\n\t\t\tpq.pop();\n\
    \t\t\tif (used[now_v]) continue;\n\t\t\tused[now_v] = true;\n\t\t\tcost += now_cost;\n\
    \t\t\tfor (auto [nv, nw] : g[now_v]) pq.emplace(nw, nv);\n\t\t}\n\t\treturn cost;\n\
    \t}\n};\n\n\n#line 4 \"test/graph/prim/aoj_grl_2_a.test.cpp\"\n\n#include <iostream>\n\
    #line 7 \"test/graph/prim/aoj_grl_2_a.test.cpp\"\n\nusing namespace std;\n\nint\
    \ main() {\n\tint v, e;\n\tcin >> v >> e;\n\tPrim<int> p(v);\n\tfor (int i = 0;\
    \ i < e; ++i) {\n\t\tint a, b, c;\n\t\tcin >> a >> b >> c;\n\t\tp.add_edge(a,\
    \ b, c);\n\t}\n\tcout << p.mst_cost() << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\
    \n#include \"src/graph/prim.hpp\"\n\n#include <iostream>\n#include <vector>\n\n\
    using namespace std;\n\nint main() {\n\tint v, e;\n\tcin >> v >> e;\n\tPrim<int>\
    \ p(v);\n\tfor (int i = 0; i < e; ++i) {\n\t\tint a, b, c;\n\t\tcin >> a >> b\
    \ >> c;\n\t\tp.add_edge(a, b, c);\n\t}\n\tcout << p.mst_cost() << endl;\n\n\t\
    return 0;\n}\n"
  dependsOn:
  - src/graph/prim.hpp
  isVerificationFile: true
  path: test/graph/prim/aoj_grl_2_a.test.cpp
  requiredBy: []
  timestamp: '2023-09-06 15:21:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/prim/aoj_grl_2_a.test.cpp
layout: document
redirect_from:
- /verify/test/graph/prim/aoj_grl_2_a.test.cpp
- /verify/test/graph/prim/aoj_grl_2_a.test.cpp.html
title: test/graph/prim/aoj_grl_2_a.test.cpp
---
