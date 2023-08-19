---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/flow/dinic/grl_6_a.test.cpp
    title: test/flow/dinic/grl_6_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/flow/dinic.cpp\"\n#include <limits>\n#include <queue>\n\
    #include <vector>\n\nusing namespace std;\n\ntemplate<class T>\nstruct Dinic {\n\
    \tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\n\t\tEdge(int to, int cap, int\
    \ rev) : to(to), cap(cap), rev(rev) {}\n\t};\n\n\tconst T INF = numeric_limits<T>::max();\n\
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
    \t\t\t\tflow += f;\n\t\t\t}\n\t\t}\n\t\treturn flow;\n\t}\n};\n"
  code: "#include <limits>\n#include <queue>\n#include <vector>\n\nusing namespace\
    \ std;\n\ntemplate<class T>\nstruct Dinic {\n\tstruct Edge {\n\t\tint to, rev;\n\
    \t\tT cap;\n\n\t\tEdge(int to, int cap, int rev) : to(to), cap(cap), rev(rev)\
    \ {}\n\t};\n\n\tconst T INF = numeric_limits<T>::max();\n\n\tvector<vector<Edge>>\
    \ G;\n\tvector<int> level, iter;\n\n\tDinic(int n) : G(n), level(n), iter(n) {}\n\
    \n\tvoid add_edge(int from, int to, T cap, bool directed = true) {\n\t\tG[from].emplace_back(to,\
    \ cap, G[to].size());\n\t\tG[to].emplace_back(from, (directed ? 0 : cap), G[from].size()\
    \ - 1);\n\t}\n\n\tvoid bfs(int s) {\n\t\tfill(level.begin(), level.end(), -1);\n\
    \t\tqueue<int> q;\n\t\tlevel[s] = 0;\n\t\tq.push(s);\n\t\twhile (!q.empty()) {\n\
    \t\t\tint v = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto &e : G[v]) {\n\t\t\t\
    \tif (e.cap > 0 && level[e.to] == -1) {\n\t\t\t\t\tlevel[e.to] = level[v] + 1;\n\
    \t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tT dfs(int v, int\
    \ t, T f) {\n\t\tif (v == t) return f;\n\t\tfor (int &i = iter[v]; i < G[v].size();\
    \ ++i) {\n\t\t\tEdge &e = G[v][i];\n\t\t\tif (e.cap > 0 && level[v] < level[e.to])\
    \ {\n\t\t\t\tT d = dfs(e.to, t, min(f, e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\
    \te.cap -= d;\n\t\t\t\t\tG[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\t\
    \t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT max_flow(int s, int t) {\n\t\t\
    T flow = 0;\n\t\twhile (true) {\n\t\t\tbfs(s);\n\t\t\tif (level[t] == -1) break;\n\
    \t\t\tfill(iter.begin(), iter.end(), 0);\n\t\t\twhile (true) {\n\t\t\t\tT f =\
    \ dfs(s, t, INF);\n\t\t\t\tif (f == 0) break;\n\t\t\t\tflow += f;\n\t\t\t}\n\t\
    \t}\n\t\treturn flow;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/dinic.cpp
  requiredBy: []
  timestamp: '2023-08-20 06:31:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/flow/dinic/grl_6_a.test.cpp
documentation_of: src/flow/dinic.cpp
layout: document
redirect_from:
- /library/src/flow/dinic.cpp
- /library/src/flow/dinic.cpp.html
title: src/flow/dinic.cpp
---
