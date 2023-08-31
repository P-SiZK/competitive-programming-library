---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/flow/primal_dual.hpp
    title: src/flow/primal_dual.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B
  bundledCode: "#line 1 \"test/flow/primal_dual/grl_6_b.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\n\n\
    #line 1 \"src/flow/primal_dual.hpp\"\n\n\n\n#include <limits>\n#include <queue>\n\
    #include <vector>\n\ntemplate<class T, class E>\nclass PrimalDual {\nprivate:\n\
    \tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\t\tE cost;\n\n\t\tEdge(int to,\
    \ T cap, E cost, int rev) : to(to), rev(rev), cap(cap), cost(cost) {}\n\t};\n\n\
    \tstatic constexpr E INF = std::numeric_limits<E>::max();\n\n\tstd::vector<std::vector<Edge>>\
    \ g;\n\tstd::vector<E> h, dist;\n\tstd::vector<int> prevv, preve;\n\npublic:\n\
    \tPrimalDual(int n) : g(n), h(n), dist(n), prevv(n), preve(n) {}\n\n\tvoid add_edge(int\
    \ from, int to, T cap, E cost) {\n\t\tg[from].emplace_back(to, cap, cost, g[to].size());\n\
    \t\tg[to].emplace_back(from, 0, -cost, g[from].size() - 1);\n\t}\n\n\tE min_cost_flow(int\
    \ s, int t, T f) {\n\t\tE res = 0;\n\t\tstd::priority_queue<std::pair<E, int>,\n\
    \t\t\t\t\t\t\tstd::vector<std::pair<E, int>>,\n\t\t\t\t\t\t\tstd::greater<>>\n\
    \t\t\tpq;\n\n\t\twhile (f > 0) {\n\t\t\tdist.assign(g.size(), INF);\n\t\t\tpq.emplace(0,\
    \ s);\n\t\t\tdist[s] = 0;\n\t\t\twhile (!pq.empty()) {\n\t\t\t\tauto [now_dist,\
    \ now_v] = pq.top();\n\t\t\t\tpq.pop();\n\t\t\t\tif (dist[now_v] < now_dist) continue;\n\
    \t\t\t\tfor (int i = 0; i < (int)g[now_v].size(); ++i) {\n\t\t\t\t\tEdge &e =\
    \ g[now_v][i];\n\t\t\t\t\tE ncost = dist[now_v] + e.cost + h[now_v] - h[e.to];\n\
    \t\t\t\t\tif (e.cap > 0 && dist[e.to] > ncost) {\n\t\t\t\t\t\tdist[e.to] = ncost;\n\
    \t\t\t\t\t\tprevv[e.to] = now_v;\n\t\t\t\t\t\tpreve[e.to] = i;\n\t\t\t\t\t\tpq.emplace(dist[e.to],\
    \ e.to);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (dist[t] == INF) return -1;\n\
    \t\t\tfor (int v = 0; v < (int)h.size(); ++v)\n\t\t\t\tif (dist[v] < INF) h[v]\
    \ += dist[v];\n\t\t\tT d = f;\n\t\t\tfor (int v = t; v != s; v = prevv[v])\n\t\
    \t\t\td = std::min(d, g[prevv[v]][preve[v]].cap);\n\t\t\tf -= d;\n\t\t\tres +=\
    \ d * h[t];\n\t\t\tfor (int v = t; v != s; v = prevv[v]) {\n\t\t\t\tEdge &e =\
    \ g[prevv[v]][preve[v]];\n\t\t\t\te.cap -= d;\n\t\t\t\tg[v][e.rev].cap += d;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n\n#line 4 \"test/flow/primal_dual/grl_6_b.test.cpp\"\
    \n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tint v_sz, e_sz,\
    \ flow;\n\tcin >> v_sz >> e_sz >> flow;\n\tPrimalDual<int, int> g(v_sz);\n\tfor\
    \ (int i = 0; i < e_sz; ++i) {\n\t\tint u, v, c, d;\n\t\tcin >> u >> v >> c >>\
    \ d;\n\t\tg.add_edge(u, v, c, d);\n\t}\n\tcout << g.min_cost_flow(0, v_sz - 1,\
    \ flow) << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B\n\
    \n#include \"src/flow/primal_dual.hpp\"\n\n#include <iostream>\n\nusing namespace\
    \ std;\n\nint main() {\n\tint v_sz, e_sz, flow;\n\tcin >> v_sz >> e_sz >> flow;\n\
    \tPrimalDual<int, int> g(v_sz);\n\tfor (int i = 0; i < e_sz; ++i) {\n\t\tint u,\
    \ v, c, d;\n\t\tcin >> u >> v >> c >> d;\n\t\tg.add_edge(u, v, c, d);\n\t}\n\t\
    cout << g.min_cost_flow(0, v_sz - 1, flow) << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/flow/primal_dual.hpp
  isVerificationFile: true
  path: test/flow/primal_dual/grl_6_b.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/flow/primal_dual/grl_6_b.test.cpp
layout: document
redirect_from:
- /verify/test/flow/primal_dual/grl_6_b.test.cpp
- /verify/test/flow/primal_dual/grl_6_b.test.cpp.html
title: test/flow/primal_dual/grl_6_b.test.cpp
---
