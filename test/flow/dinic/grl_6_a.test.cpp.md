---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/flow/dinic.cpp
    title: src/flow/dinic.cpp
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
    #line 1 \"src/flow/dinic.cpp\"\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n\nusing namespace std;\n\ntemplate<class T>\nstruct Dinic {\n\tstruct\
    \ Edge {\n\t\tint to, rev;\n\t\tT cap;\n\n\t\tEdge(int to, int cap, int rev) :\
    \ to(to), cap(cap), rev(rev) {}\n\t};\n\n\tconst T INF = numeric_limits<T>::max();\n\
    \n\tvector<vector<Edge>> G;\n\tvector<int> level, iter;\n\n\tDinic(int n) : G(n),\
    \ level(n), iter(n) {}\n\n\tvoid add_edge(int from, int to, T cap, bool directed\
    \ = true) {\n\t\tG[from].emplace_back(to, cap, G[to].size());\n\t\tG[to].emplace_back(from,\
    \ (directed ? 0 : cap), G[from].size() - 1);\n\t}\n\n\tvoid bfs(int s) {\n\t\t\
    fill(level.begin(), level.end(), -1);\n\t\tqueue<int> q;\n\t\tlevel[s] = 0;\n\t\
    \tq.push(s);\n\t\twhile (!q.empty()) {\n\t\t\tint v = q.front();\n\t\t\tq.pop();\n\
    \t\t\tfor (auto &e : G[v]) {\n\t\t\t\tif (e.cap > 0 && level[e.to] == -1) {\n\t\
    \t\t\t\tlevel[e.to] = level[v] + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t}\n\n\tT dfs(int v, int t, T f) {\n\t\tif (v == t) return f;\n\t\t\
    for (int &i = iter[v]; i < G[v].size(); ++i) {\n\t\t\tEdge &e = G[v][i];\n\t\t\
    \tif (e.cap > 0 && level[v] < level[e.to]) {\n\t\t\t\tT d = dfs(e.to, t, min(f,\
    \ e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap\
    \ += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\
    \tT max_flow(int s, int t) {\n\t\tT flow = 0;\n\t\twhile (true) {\n\t\t\tbfs(s);\n\
    \t\t\tif (level[t] == -1) break;\n\t\t\tfill(iter.begin(), iter.end(), 0);\n\t\
    \t\twhile (true) {\n\t\t\t\tT f = dfs(s, t, INF);\n\t\t\t\tif (f == 0) break;\n\
    \t\t\t\tflow += f;\n\t\t\t}\n\t\t}\n\t\treturn flow;\n\t}\n};\n#line 4 \"test/flow/dinic/grl_6_a.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tint V, E;\n\tcin >> V >> E;\n\tDinic<int>\
    \ G(V);\n\tfor (int i = 0; i < E; ++i) {\n\t\tint u, v, c;\n\t\tcin >> u >> v\
    \ >> c;\n\t\tG.add_edge(u, v, c);\n\t}\n\tcout << G.max_flow(0, V - 1) << endl;\n\
    \n\treturn 0;\n}\n"
  code: "// verification-helper: PROBLEM https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\n\
    \n#include \"src/flow/dinic.cpp\"\n\n#include <iostream>\n\nint main() {\n\tint\
    \ V, E;\n\tcin >> V >> E;\n\tDinic<int> G(V);\n\tfor (int i = 0; i < E; ++i) {\n\
    \t\tint u, v, c;\n\t\tcin >> u >> v >> c;\n\t\tG.add_edge(u, v, c);\n\t}\n\tcout\
    \ << G.max_flow(0, V - 1) << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - src/flow/dinic.cpp
  isVerificationFile: true
  path: test/flow/dinic/grl_6_a.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/flow/dinic/grl_6_a.test.cpp
layout: document
redirect_from:
- /verify/test/flow/dinic/grl_6_a.test.cpp
- /verify/test/flow/dinic/grl_6_a.test.cpp.html
title: test/flow/dinic/grl_6_a.test.cpp
---
