---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/prim.hpp
    title: src/graph/prim.hpp
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
    #line 1 \"src/graph/prim.hpp\"\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\nusing namespace std;\n\ntemplate<class T>\nclass Prim {\nprivate:\n\
    \tint n;\n\tvector<vector<pair<int, T>>> g;\n\npublic:\n\tPrim(int n) : n(n),\
    \ g(n) {}\n\n\tvoid add_edge(int from, int to, T cost) {\n\t\tg[from].emplace_back(to,\
    \ cost);\n\t\tg[to].emplace_back(from, cost);\n\t}\n\n\tT mst_cost() {\n\t\tT\
    \ cost = 0;\n\t\tvector<bool> used(g.size());\n\t\tpriority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<>> pq;\n\t\tpq.emplace(0, 0);\n\t\twhile (!pq.empty())\
    \ {\n\t\t\tauto [now_cost, now_v] = pq.top();\n\t\t\tpq.pop();\n\t\t\tif (used[now_v])\
    \ continue;\n\t\t\tused[now_v] = true;\n\t\t\tcost += now_cost;\n\t\t\tfor (auto\
    \ [nv, nw] : g[now_v]) pq.emplace(nw, nv);\n\t\t}\n\t\treturn cost;\n\t}\n};\n\
    #line 4 \"test/graph/prim/grl_2_a.test.cpp\"\n\n#include <iostream>\n#line 7 \"\
    test/graph/prim/grl_2_a.test.cpp\"\n\nusing namespace std;\n\nint main() {\n\t\
    int v, e;\n\tcin >> v >> e;\n\tPrim<int> p(v);\n\tfor (int i = 0; i < e; ++i)\
    \ {\n\t\tint a, b, c;\n\t\tcin >> a >> b >> c;\n\t\tp.add_edge(a, b, c);\n\t}\n\
    \tcout << p.mst_cost() << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\n\
    \n#include \"src/graph/prim.hpp\"\n\n#include <iostream>\n#include <vector>\n\n\
    using namespace std;\n\nint main() {\n\tint v, e;\n\tcin >> v >> e;\n\tPrim<int>\
    \ p(v);\n\tfor (int i = 0; i < e; ++i) {\n\t\tint a, b, c;\n\t\tcin >> a >> b\
    \ >> c;\n\t\tp.add_edge(a, b, c);\n\t}\n\tcout << p.mst_cost() << endl;\n\n\t\
    return 0;\n}\n"
  dependsOn:
  - src/graph/prim.hpp
  isVerificationFile: true
  path: test/graph/prim/grl_2_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 00:25:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/prim/grl_2_a.test.cpp
layout: document
redirect_from:
- /verify/test/graph/prim/grl_2_a.test.cpp
- /verify/test/graph/prim/grl_2_a.test.cpp.html
title: test/graph/prim/grl_2_a.test.cpp
---
