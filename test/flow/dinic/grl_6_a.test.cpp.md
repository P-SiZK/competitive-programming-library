---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/flow/dinic.hpp
    title: src/flow/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/flow/dinic/grl_6_a.test.cpp\"\n// verification-helper:\
    \ PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\n\n\
    #line 1 \"src/flow/dinic.hpp\"\n\n\n\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n\ntemplate<class T>\nclass Dinic {\nprivate:\n\tstruct Edge {\n\t\t\
    int to, rev;\n\t\tT cap;\n\n\t\tEdge(int to, int cap, int rev) : to(to), rev(rev),\
    \ cap(cap) {}\n\t};\n\n\tstatic constexpr T INF = std::numeric_limits<T>::max();\n\
    \n\tstd::vector<std::vector<Edge>> g;\n\tstd::vector<int> level, iter;\n\npublic:\n\
    \tDinic(int n) : g(n), level(n), iter(n) {}\n\n\tvoid add_edge(int from, int to,\
    \ T cap, bool directed = true) {\n\t\tg[from].emplace_back(to, cap, g[to].size());\n\
    \t\tg[to].emplace_back(from, (directed ? 0 : cap), g[from].size() - 1);\n\t}\n\
    \n\tvoid bfs(int s) {\n\t\tlevel.assign(g.size(), -1);\n\t\tstd::queue<int> q;\n\
    \t\tlevel[s] = 0;\n\t\tq.push(s);\n\t\twhile (!q.empty()) {\n\t\t\tint const V\
    \ = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto &e : g[V]) {\n\t\t\t\tif (e.cap\
    \ > 0 && level[e.to] == -1) {\n\t\t\t\t\tlevel[e.to] = level[V] + 1;\n\t\t\t\t\
    \tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tT dfs(int v, int t, T f)\
    \ {\n\t\tif (v == t) return f;\n\t\tfor (int &i = iter[v]; i < (int)g[v].size();\
    \ ++i) {\n\t\t\tEdge &e = g[v][i];\n\t\t\tif (e.cap > 0 && level[v] < level[e.to])\
    \ {\n\t\t\t\tT d = dfs(e.to, t, std::min(f, e.cap));\n\t\t\t\tif (d > 0) {\n\t\
    \t\t\t\te.cap -= d;\n\t\t\t\t\tg[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT max_flow(int s, int t) {\n\
    \t\tT flow = 0;\n\t\twhile (true) {\n\t\t\tbfs(s);\n\t\t\tif (level[t] == -1)\
    \ break;\n\t\t\titer.assign(g.size(), 0);\n\t\t\twhile (true) {\n\t\t\t\tT f =\
    \ dfs(s, t, INF);\n\t\t\t\tif (f == 0) break;\n\t\t\t\tflow += f;\n\t\t\t}\n\t\
    \t}\n\t\treturn flow;\n\t}\n};\n\n\n#line 4 \"test/flow/dinic/grl_6_a.test.cpp\"\
    \n\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n\tint v_sz, e_sz;\n\
    \tcin >> v_sz >> e_sz;\n\tDinic<int> g(v_sz);\n\tfor (int i = 0; i < e_sz; ++i)\
    \ {\n\t\tint u, v, c;\n\t\tcin >> u >> v >> c;\n\t\tg.add_edge(u, v, c);\n\t}\n\
    \tcout << g.max_flow(0, v_sz - 1) << endl;\n\n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\n\
    \n#include \"src/flow/dinic.hpp\"\n\n#include <iostream>\n\nusing namespace std;\n\
    \nint main() {\n\tint v_sz, e_sz;\n\tcin >> v_sz >> e_sz;\n\tDinic<int> g(v_sz);\n\
    \tfor (int i = 0; i < e_sz; ++i) {\n\t\tint u, v, c;\n\t\tcin >> u >> v >> c;\n\
    \t\tg.add_edge(u, v, c);\n\t}\n\tcout << g.max_flow(0, v_sz - 1) << endl;\n\n\t\
    return 0;\n}\n"
  dependsOn:
  - src/flow/dinic.hpp
  isVerificationFile: true
  path: test/flow/dinic/grl_6_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 15:37:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/flow/dinic/grl_6_a.test.cpp
layout: document
redirect_from:
- /verify/test/flow/dinic/grl_6_a.test.cpp
- /verify/test/flow/dinic/grl_6_a.test.cpp.html
title: test/flow/dinic/grl_6_a.test.cpp
---
