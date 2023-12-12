---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/flow/dinic/aoj_grl_6_a.test.cpp
    title: test/flow/dinic/aoj_grl_6_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/flow/dinic.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <queue>\n#include <vector>\n\ntemplate<class T>\nclass Dinic\
    \ {\nprivate:\n\tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\n\t\tEdge(int to,\
    \ int cap, int rev) : to(to), rev(rev), cap(cap) {}\n\t};\n\n\tstatic constexpr\
    \ T INF = std::numeric_limits<T>::max();\n\n\tstd::vector<std::vector<Edge>> g;\n\
    \tstd::vector<int> level, iter;\n\npublic:\n\tDinic(int n) : g(n), level(n), iter(n)\
    \ {}\n\n\tvoid add_edge(int from, int to, T cap, bool directed = true) {\n\t\t\
    g[from].emplace_back(to, cap, g[to].size());\n\t\tg[to].emplace_back(from, (directed\
    \ ? 0 : cap), g[from].size() - 1);\n\t}\n\n\tvoid bfs(int s) {\n\t\tlevel.assign(g.size(),\
    \ -1);\n\t\tstd::queue<int> q;\n\t\tlevel[s] = 0;\n\t\tq.push(s);\n\t\twhile (!q.empty())\
    \ {\n\t\t\tint const V = q.front();\n\t\t\tq.pop();\n\t\t\tfor (auto &e : g[V])\
    \ {\n\t\t\t\tif (e.cap > 0 && level[e.to] == -1) {\n\t\t\t\t\tlevel[e.to] = level[V]\
    \ + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tT dfs(int\
    \ v, int t, T f) {\n\t\tif (v == t) return f;\n\t\tfor (int &i = iter[v]; i <\
    \ (int)g[v].size(); ++i) {\n\t\t\tEdge &e = g[v][i];\n\t\t\tif (e.cap > 0 && level[v]\
    \ < level[e.to]) {\n\t\t\t\tT d = dfs(e.to, t, std::min(f, e.cap));\n\t\t\t\t\
    if (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tg[e.to][e.rev].cap += d;\n\t\t\t\
    \t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\tT max_flow(int\
    \ s, int t) {\n\t\tT flow = 0;\n\t\twhile (true) {\n\t\t\tbfs(s);\n\t\t\tif (level[t]\
    \ == -1) break;\n\t\t\titer.assign(g.size(), 0);\n\t\t\twhile (true) {\n\t\t\t\
    \tT f = dfs(s, t, INF);\n\t\t\t\tif (f == 0) break;\n\t\t\t\tflow += f;\n\t\t\t\
    }\n\t\t}\n\t\treturn flow;\n\t}\n};\n\n\n"
  code: "#ifndef FLOW_DINIC_HPP\n#define FLOW_DINIC_HPP\n\n#include <algorithm>\n\
    #include <limits>\n#include <queue>\n#include <vector>\n\ntemplate<class T>\n\
    class Dinic {\nprivate:\n\tstruct Edge {\n\t\tint to, rev;\n\t\tT cap;\n\n\t\t\
    Edge(int to, int cap, int rev) : to(to), rev(rev), cap(cap) {}\n\t};\n\n\tstatic\
    \ constexpr T INF = std::numeric_limits<T>::max();\n\n\tstd::vector<std::vector<Edge>>\
    \ g;\n\tstd::vector<int> level, iter;\n\npublic:\n\tDinic(int n) : g(n), level(n),\
    \ iter(n) {}\n\n\tvoid add_edge(int from, int to, T cap, bool directed = true)\
    \ {\n\t\tg[from].emplace_back(to, cap, g[to].size());\n\t\tg[to].emplace_back(from,\
    \ (directed ? 0 : cap), g[from].size() - 1);\n\t}\n\n\tvoid bfs(int s) {\n\t\t\
    level.assign(g.size(), -1);\n\t\tstd::queue<int> q;\n\t\tlevel[s] = 0;\n\t\tq.push(s);\n\
    \t\twhile (!q.empty()) {\n\t\t\tint const V = q.front();\n\t\t\tq.pop();\n\t\t\
    \tfor (auto &e : g[V]) {\n\t\t\t\tif (e.cap > 0 && level[e.to] == -1) {\n\t\t\t\
    \t\tlevel[e.to] = level[V] + 1;\n\t\t\t\t\tq.push(e.to);\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t}\n\n\tT dfs(int v, int t, T f) {\n\t\tif (v == t) return f;\n\t\tfor\
    \ (int &i = iter[v]; i < (int)g[v].size(); ++i) {\n\t\t\tEdge &e = g[v][i];\n\t\
    \t\tif (e.cap > 0 && level[v] < level[e.to]) {\n\t\t\t\tT d = dfs(e.to, t, std::min(f,\
    \ e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tg[e.to][e.rev].cap\
    \ += d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n\
    \tT max_flow(int s, int t) {\n\t\tT flow = 0;\n\t\twhile (true) {\n\t\t\tbfs(s);\n\
    \t\t\tif (level[t] == -1) break;\n\t\t\titer.assign(g.size(), 0);\n\t\t\twhile\
    \ (true) {\n\t\t\t\tT f = dfs(s, t, INF);\n\t\t\t\tif (f == 0) break;\n\t\t\t\t\
    flow += f;\n\t\t\t}\n\t\t}\n\t\treturn flow;\n\t}\n};\n\n#endif // FLOW_DINIC_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/dinic.hpp
  requiredBy: []
  timestamp: '2023-12-12 23:23:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/flow/dinic/aoj_grl_6_a.test.cpp
documentation_of: src/flow/dinic.hpp
layout: document
title: Dinic
---
